#!/usr/bin/env python3
import numpy as np
from math import cos, sin, pi, radians, sqrt, atan2, floor
from scipy.special import fresnel
from scipy.optimize import bisect
import scipy.integrate as integrate
import scipy.special as special
import matplotlib.pyplot as plt
import matplotlib.cm as cm

# csv file name:
csvfile = '/home/lucien/ESE6150/waypoints_map.csv'

# define the turns in terms of [inside_corner, outside_corner] (each time the map changes, this need to be updated)
# corners = [{'inner': np.array([5.43, -1.57]), 'outer': np.array([5.47, -4.8])},
#          {'inner': np.array([10.6, 5.8]), 'outer': np.array([12.6, 6.0])},
#          {'inner': np.array([7.54, 7.92]), 'outer': np.array([6.95, 9.87])},
#          {'inner': np.array([7.09, 7.13]), 'outer': np.array([4.88, 6.76])},
#          {'inner': np.array([9.4, 5.27]), 'outer': np.array([7.31, 4.77])},
#          {'inner': np.array([5.7, -1.21]), 'outer': np.array([2.56, -2.5])}]
corners = [
         {'inner': np.array([10.6, 5.8]), 'outer': np.array([12.6, 6.0])},
         {'inner': np.array([7.54, 7.92]), 'outer': np.array([6.95, 9.87])},
         {'inner': np.array([7.09, 7.13]), 'outer': np.array([4.88, 6.76])},
         {'inner': np.array([9.4, 5.27]), 'outer': np.array([7.66, 4.84])},
         {'inner': np.array([5.48, -0.85]), 'outer': np.array([3.96, 0.02])},
         {'inner': np.array([4.7, -2.3]), 'outer': np.array([3.89, -3.8])},
         {'inner': np.array([5.74, -1.1]), 'outer': np.array([7.27, -2.2])},

         ]

# define velocity parameters
min_speed = 4               # the target speed at the end of braking
max_speed = 8               # the max speed on the straights
brake_dist = 3              # distance from the beginning of the turn to start braking

turn_start_dist = 0.25      # distance down the road from the inner corner to begin turn (smaller:turn earlier; larger: turn later;)
turn_end_dist = 2.0         # distance down the road from the exit of the inner corner to end turn
throttle_aggression = 0.75  # how quickly to speed up after coasting
coast_ratio = 0.6           # in a turn, when to start to accelerate (smaller: accelerate earlier; larger: accelerate later)

safe_dist = 0.5            # the distance to keep from the wall


class LineGenerator:
    dist_straight_points = 0.3      # rough distance in meters between waypoints on the straight
    dist_brake_points = 0.3         # same as straight points but for braking
    num_turn_points = 10             # number of waypoints to have in turns

    def __init__(self, min_speed, max_speed, brake_dist, turn_start_dist, turn_end_dist, coast_ratio, throttle_aggression, safe_dist, turns):
        self.v_min = min_speed
        self.v_max = max_speed
        self.s_brake = brake_dist
        self.s_turn = turn_start_dist
        self.s_turn_end = turn_end_dist
        self.coast_ratio = coast_ratio
        self.floor_it = throttle_aggression
        self.buff = safe_dist
        self.turns = turns

        # two circular lists for inner points and outer points
        self.inners = np.zeros((2, len(self.turns) + 1))
        self.outers = self.inners.copy()
        for i in range(len(self.turns)):
            self.inners[0, i] = self.turns[i]['inner'][0]
            self.inners[1, i] = self.turns[i]['inner'][1]
            self.outers[0, i] = self.turns[i]['outer'][0]
            self.outers[1, i] = self.turns[i]['outer'][1]
        self.inners[:, -1] = self.inners[:, 0]
        self.outers[:, -1] = self.outers[:, 0]

        self.num_brake_points = floor(brake_dist / self.dist_brake_points)  # number of waypoints to have in braking zone


    def place_point_near_wall(self, current_turn, prev_turn, dist, go_fwd):
        """
        find the point to start to turn
        
        Args:
            turn_from (dictionary): current turn
            turn_to (dictionary): previous turn
            dist (float): distance down the road from the inner corner to begin turn ???
            go_fwd (bollen): if go forward or go backward

        Returns:
            placed_point: point on track to start to turn
            placed_point_wall: point along the wall to start to turn
        """
        # unit vector from current outer corner to previous outer corner
        unit_wall_outer = prev_turn['outer'] - current_turn['outer']
        unit_wall_outer = unit_wall_outer / np.linalg.norm(unit_wall_outer)
        
        # point on outside wall to point aligned with next inner wall
        outer_start = vect_proj(current_turn['inner'] - current_turn['outer'], unit_wall_outer) + current_turn['outer']

        # define buffer before the turn
        vec_buff_pre = self.buff * unit_wall_outer  # buffer is still pointing along wall
        if go_fwd:
            rot = pi / 2
        else:
            rot = -pi / 2
        vec_buff_pre = rotate(vec_buff_pre, rot)  # rotate it -90 degrees
        # find point on outside wall aligned with turn_start
        placed_point_wall = unit_wall_outer * dist + outer_start
        # add the buffer to it to find the point the turn begins
        placed_point = vec_buff_pre + placed_point_wall

        return placed_point, placed_point_wall

    # credit to jethro on StackOverflow
    def past_line(self, line_1, line_2, point): # determines if a point is past a line
        return ((line_2[0] - line_1[0]) * (point[1] - line_1[1]) - \
                (line_2[1] - line_1[1]) * (point[0] - line_1[0])) > 0


    def def_turn(self, curr_turn_idx, start_vel, turn_finished):
        """
        plots the racing line through turn starting at braking zone of current turn 
        and ending at braking zone start point of next turn

        Args:
            curr_turn_idx (int): current turn index
            start_vel (float): velocity when starting a turn (start to brake)
            turn_finished (boolen): 

        Returns:
            _type_: 
        """
        turn_now = self.turns[curr_turn_idx % len(self.turns)]   # current turn
        turn_next = self.turns[(curr_turn_idx + 1) % len(self.turns)]   # next turn
        turn_prev = self.turns[(curr_turn_idx - 1) % len(self.turns)]   # last turn

        turn_points = np.array([]).reshape(0,3) # points to return
        
        # 1. find the point that start to turn
        turn_start, turn_start_wall = self.place_point_near_wall(turn_now, turn_prev, self.s_turn, False)

        if turn_finished:
            # 2. find the point that start to brake
            brake_start, _ = self.place_point_near_wall(turn_now, turn_prev, self.s_brake, False)

            # 3. create the braking waypoints
            new_points = np.zeros((self.num_brake_points,3))
            for i in range(self.num_brake_points):
                # velocity interpolation
                curr_vel = (self.v_min - start_vel) * i / (self.num_brake_points - 1) + start_vel
                # distance interpolation
                curr_dist = self.s_brake * i / (self.num_brake_points - 1)
                # one single waypoint in the braking zone
                curr_point = proj_along(brake_start, turn_start, curr_dist)
                # append point to the list
                new_points[i, :] = np.array([curr_point[0], curr_point[1], curr_vel])
            # append point to the list
            turn_points = np.vstack((turn_points, new_points))
            
            # 4. find the heading vector at the start of the turn, used later
            curr_dir = turn_points[self.num_brake_points - 1, 0:2] - \
                       turn_points[self.num_brake_points - 2, 0:2]
            exclude_next_first_point = True
            
        else: # have to modify the velocity of preceding points and possibly cut it short
            # remove all the current waypoints past the turn beginning
            this_count = 0
            while self.past_line(turn_start, turn_start_wall, self.waypoints[-1,0:2]):
                this_count = this_count + 1
                self.waypoints = self.waypoints[:-1, :]
            print("Turn unfinished; deleting %d waypoints" % this_count)

            # iterate *backwards* through the existing waypoints, reducing their speed
            new_start_vel = self.waypoints[-self.num_brake_points,2]
            print(new_start_vel)
            for i in range(1,self.num_brake_points+1):
                self.waypoints[-i,2] = (new_start_vel - self.v_min) * i / (self.num_brake_points + 0) + \
                                       self.v_min
            # also update the turn_start position to be the end of waypoints
            turn_start = self.waypoints[-1,0:2]
            # find the heading at the start of the turn, used later
            curr_dir = turn_start - self.waypoints[-2,0:2]
            exclude_next_first_point = False

        # unit heading vector at the starting of the turn
        T1 = curr_dir / np.linalg.norm(curr_dir)
        # unit heading vector at the end of the turn
        next_dir = turn_next['inner'] - turn_now['inner']
        T2 = next_dir / np.linalg.norm(next_dir)
        
        
        # 5. def spiral_interp_points(start,final,T1,T2,num_points):
        
        # 5.1 find the turn end point (straight start point)
        straight_start, _ = self.place_point_near_wall(turn_now, turn_next, self.s_turn_end, True)
        
        # 5.2 generate a Euler Spiral trajectory from start point (start, T1) to the end point (final, T2)
        x_spi, y_spi, T0, P0, N0, theta, phi1, phi2 = spiral_interp_points(turn_start, straight_start,
                                                                           T1, T2, self.num_turn_points + 1)
        x_spi = np.array(x_spi)
        y_spi = np.array(y_spi)
        if exclude_next_first_point:
            excl_idx = 1
        else:
            excl_idx = 0
            
        # 5.3 append point to the list
        new_points = np.hstack((x_spi[excl_idx:], y_spi[excl_idx:], np.zeros(((x_spi.shape[0] - excl_idx), 1))))
        new_points[:,2] = self.v_min

        # 5.4 give them a velocity based on how far into the turn you want to start accelerating
        num_coast_points = floor(self.coast_ratio * self.num_turn_points)
        for i in range(self.num_turn_points - num_coast_points):
            curr_vel = min(self.v_max,
                           self.floor_it * (self.v_max - self.v_min) * i + self.v_min)
            new_points[num_coast_points + i, 2] = curr_vel
        turn_points = np.vstack((turn_points,new_points))

        # finally, define the straight
        straight_length = np.linalg.norm(turn_now['inner'] - turn_next['inner'])   # the straight's raw length
        if straight_length - (self.s_brake + self.s_turn + self.s_turn_end) > 0:   # if have enough space
            straight_end, _ = self.place_point_near_wall(turn_next, turn_now,
                                                         self.s_brake + self.s_turn, False)
            completed_turn = True
        else:
            straight_end, _ = self.place_point_near_wall(turn_next, turn_now, self.s_turn, False)
            completed_turn = False

        straight_dist = np.linalg.norm(straight_end - straight_start)   # the straight's exactly length
        num_straight_points = max(floor(straight_dist/self.dist_straight_points),0)
        turn_end_vel = min(self.v_max,curr_vel)    # sometimes you don't reach full speed
        new_points  = np.zeros((num_straight_points,3))
        for i in range(num_straight_points):  # start at 1 b/c end of turn is on straight
            curr_vel = min(self.v_max,
                           self.floor_it * i * (self.v_max - turn_end_vel) + turn_end_vel)
            curr_dist = straight_dist * i / (num_straight_points - 1)
            curr_point = proj_along(straight_start, straight_end, curr_dist)
            new_points[i, :] = np.array([curr_point[0], curr_point[1], curr_vel])
        end_vel = curr_vel
        turn_points = np.vstack((turn_points[:-1],new_points))

        return turn_points, num_straight_points, end_vel, completed_turn
    
    def remap_speed(self, waypoints):
        yaws = waypoints[:,-1]
        yaw0 = yaws[0]
        yaws_shifted = np.roll(yaws,-1)
        yaws_shifted[-1] = yaw0
        yaw_diff = yaws - yaws_shifted
        
        to_delete_indices = [] 
        for i,_ in enumerate(waypoints):
            if abs(yaw_diff[i]) > 1.0:
                to_delete_indices.append(i)
        new_waypoints = np.delete(waypoints, to_delete_indices, axis=0)
        new_yaw_diff = np.delete(yaw_diff, to_delete_indices, axis=0)
        
        print(new_yaw_diff)
        min_yaw = min(abs(new_yaw_diff))
        max_yaw = max(abs(new_yaw_diff))
        print(min_yaw, max_yaw)

        for i,waypoint in enumerate(new_waypoints):
            waypoint[2] = self.v_max - ((self.v_max-self.v_min) * (abs(new_yaw_diff[i]) - min_yaw) / (max_yaw - min_yaw))
            
        plt.plot(new_yaw_diff)
        plt.show()
        return new_waypoints
        


    # defines its waypoints [x,y,z]
    # this is the main function to generate the trajectory
    def create_line(self):

        self.waypoints = np.array([]).reshape(0, 3)
        turn_finished = True
        curr_vel = self.v_max       # start at full speed.
        
        # 1. difine the turn points
        for i in range(len(self.turns)):
            new_points, num_straight_points, curr_vel, turn_finished = self.def_turn(i, curr_vel, turn_finished)
            self.waypoints = np.vstack((self.waypoints, new_points[:-1, :]))
            
        # 2. find the yaw of every waypoint
        points_length = self.waypoints.shape[0]
        yaws = np.zeros((points_length, 1))
        for i in range(points_length + 1):
            curr_point = self.waypoints[i % points_length, 0:2]
            prev_point = self.waypoints[(i - 1) % points_length, 0:2]
            yaws[i % points_length] = atan2(curr_point[1] - prev_point[1], curr_point[0] - prev_point[0])
        self.waypoints = np.hstack((self.waypoints, yaws))
        # print(self.waypoints.shape)
        
        # 3. remap the speed with yaw
        # self.waypoints = self.remap_speed(self.waypoints)
        
        return
    

    # PLOTTING FUNCTIONS #######################
    # plot just the map
    def plot_map(self):
        plt.plot(self.inners[0], self.inners[1], c='k')
        plt.plot(self.outers[0], self.outers[1], c='k')
        ax = plt.gca()
        ax.set_aspect('equal', 'box')
        return

    def plot_racing_line(self):
        plot_colourline(self.waypoints[:, 0], self.waypoints[:, 1], self.waypoints[:, 2])
        ax = plt.gca()
        ax.set_aspect('equal', 'box')
        return

    def plot_velocity(self):
        plot_colourline(np.arange(self.waypoints.shape[0]),
                        self.waypoints[:, 2], self.waypoints[:, 2])

    def plot_yaw(self):
        plt.plot(np.arange(self.waypoints.shape[0]), self.waypoints[:,3])


# credit to "An improved Euler spiral algorithm for shape completion"
# by Walton and Meek, 2008, Canadian Conference on Computer and Robot Vision
def spiral_interp_points(start, final, T1, T2, num_points):
    """
    generate a Euler Spiral trajectory from start point (start, T1) to the end point (final, T2)
    # credit to "An improved Euler spiral algorithm for shape completion"
    # by Walton and Meek, 2008, Canadian Conference on Computer and Robot Vision

    Args:
        start (point): _description_
        final (point): _description_
        T1 (vector): _description_
        T2 (vector): _description_
        num_points (int): _description_

    Returns:
        _type_: _description_
    """
    D = np.array([final[0] - start[0], final[1] - start[1]])
    d = np.linalg.norm(D)
    P1 = start.copy()  # np.array([start.x,start.y])
    P2 = final.copy()  # np.array([final.x,final.y])
    phi1 = atan2(np.cross(T1, D), np.dot(T1, D))
    phi2 = atan2(np.cross(D, T2), np.dot(D, T2))
    reverse_flag = False
    if (np.abs(phi1) > np.abs(phi2)):
        #print("phi1 > phi2; reverse")
        reverse_flag = True
        phi1, phi2, P1, D = reverse(phi1, phi2, P1, D)
    reflect = False
    if (phi2 < 0):
        reflect, phi1, phi2 = reflect_func(phi1, phi2)
        #print("Reflecting")

    T = D / d
    theta = 0
    sign = 1
    t1 = 0
    t2 = sqrt(2 * (phi1 + phi2) / pi)
    S, C = fresnel(t2)
    h = S * cos(phi1) - C * sin(phi1)

    if ((phi1 > 0) and (h <= 0)):  # C-shaped
        #print("C-shaped spiral")
        s = False
        if False: #(h > 0.0001):  # solution is theta=0
            print("solution is theta=0")
        else:
            lambd = (1 - cos(phi1)) / (1 - cos(phi2))
            theta0 = lambd ** 2 * (phi1 + phi2) / (1 - lambd ** 2)
            theta = solve(0, theta0, phi1, phi2, sign)
            # theta = bisect(find_theta,0,theta0,args=(phi1,phi2,s))
    else:  # S-shaped
        #print("S-shaped spiral")
        #print("Heuristic: %0.5f" % h)
        s = True
        sign = -1
        theta0 = max(0, -phi1)
        theta1 = pi / 2 - phi1
        theta = solve(theta0, theta1, phi1, phi2, sign)
        # theta = bisect(find_theta,theta0,theta1,args=(phi1,phi2,s))
    #print("Theta:\t%0.5f" % (theta * 180 / pi))

    t1 = sign * sqrt(2 * theta / pi)
    t2 = sqrt(2 * (theta + phi1 + phi2) / pi)
    S1, C1 = fresnel(t1)
    S2, C2 = fresnel(t2)
    phi = phi1 + theta
    a = d / ((S2 - S1) * sin(phi) + (C2 - C1) * cos(phi))
    if (reflect):
        T0 = rotate(T, phi)
        N0 = rotate(T0, -pi / 2)
    else:
        T0 = rotate(T, -phi)
        N0 = rotate(T0, pi / 2)
    P0 = P1 - a * (C1 * T0 + S1 * N0)

    # evaluate to find the points
    x_points = np.zeros((num_points, 1))
    y_points = x_points.copy()
    for i in range(num_points):
        t = (t2 - t1) / (num_points - 1) * (i) + t1
        St, Ct = fresnel(t)
        point = P0 + a * (Ct * T0 + St * N0)
        x_points[i] = point[0]
        y_points[i] = point[1]
    if (reverse_flag):  # just to make sure P1 is at the beginning
        x_points = np.flipud(x_points)
        y_points = np.flipud(y_points)
    return x_points, y_points, T0, P0, N0, theta, phi1, phi2


def proj_along(start, target, dist):
    """
    travel a certain distance from one point in the direction of another:

    Args:
        start (point): start point
        target (point): end point
        dist (float): distance to travel

    Returns:
        new_point: 
    """
    # find unit vector from start to target
    vect = target - start
    unit = vect / np.linalg.norm(vect)
    # travel that distance
    new_point = dist * unit + start
    return new_point


def vect_proj(image, screen):
    """
    project vector image onto screen

    Args:
        image (ndarray): vector to be projected
        screen (ndarray): vector to project onto

    Returns:
        ndarray: project result
    """
    return screen * np.dot(image, screen) / np.dot(screen, screen)


# credit to Alejandro on StackOverflow
def plot_colourline(x, y, c):
    c = cm.RdYlGn((c - np.min(c)) / (np.max(c) - np.min(c)))
    ax = plt.gca()
    for i in np.arange(len(x) - 1):
        ax.plot([x[i], x[i + 1]], [y[i], y[i + 1]], c=c[i], marker='o')
    return


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __sub__(self, other):
        x = self.x - other.x
        y = self.y - other.y
        return Point(x, y)

    def norm(self):
        return sqrt(self.x ** 2 + self.y ** 2)


def reverse(phi1, phi2, P1, D):
    Dnew = -D
    P1new = P1 - Dnew
    phi = phi1
    phi1new = -phi2
    phi2new = -phi
    return phi1new, phi2new, P1new, Dnew


def reflect_func(phi1, phi2):
    reflectFlag = True
    phi1new = -phi1
    phi2new = -phi2
    return reflectFlag, phi1new, phi2new


def rotate(V, alpha):
    Wx = V[0] * cos(alpha) - V[1] * sin(alpha)
    Wy = V[0] * sin(alpha) + V[1] * cos(alpha)
    return np.array([Wx, Wy])


def fresnel2(theta):
    if (theta < 0):
        thetanew = -theta
        sign = -1
    else:
        thetanew = theta
        sign = 1
    S, C = fresnel(sqrt(2 * abs(theta) / pi))
    return sign * S, sign * C


def evaluate(theta, phi1, phi2, sign):
    S1, C1 = fresnel2(theta)
    S2, C2 = fresnel2(theta + phi1 + phi2)
    c = cos(theta + phi1)
    s = sin(theta + phi1)
    f = sqrt(2 * pi) * (c * (S2 - sign * S1) - s * (C2 - sign * C1))
    fprime = sin(phi2) / sqrt(theta + phi1 + phi2) + sign * sin(phi1) / sqrt(np.where(theta == 0, 1e-20, theta)) \
             - sqrt(2 * pi) * (s * (S2 - sign * S1) + c * (C2 - sign * C1))
    return f, fprime


def solve(a, b, phi1, phi2, sign):
    tol = 0.000001
    iterLim = 1000
    fa, faprime = evaluate(a, phi1, phi2, sign)
    fb, fbprime = evaluate(b, phi1, phi2, sign)
    theta = 0.5 * (a + b)
    f, fprime = evaluate(theta, phi1, phi2, sign)
    error = b - a
    iters = 0
    while ((error > tol) and (iters < iterLim)):
        iters = iters + 1
        failure = True
        if (abs(fprime) > tol):
            theta_iter = theta - f / fprime
            delta = abs(theta - theta_iter)
            if ((theta_iter > a) and (theta_iter < b) and (delta < 0.5 * error)):
                failure = False
                theta = theta_iter
                error = delta
        if (failure):
            if (fa * f < 0):
                b = theta
                fb = f
            else:
                a = theta
                fa = f
            theta = 0.5 * (a + b)
            error = b - a
        f, fprime = evaluate(theta, phi1, phi2, sign)
    if (iters >= iterLim):
        print("Maximum iterations reached")
    return theta


if __name__ == "__main__":

    racing_line = LineGenerator(min_speed, max_speed, brake_dist, turn_start_dist, turn_end_dist, coast_ratio, throttle_aggression, safe_dist, corners)

    plt.close('all')
    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1)

    racing_line.create_line()

    np.savetxt(csvfile, racing_line.waypoints, delimiter=",")

    racing_line.plot_map()
    racing_line.plot_racing_line()

    fig = plt.figure()
    racing_line.plot_velocity()
    plt.show()

