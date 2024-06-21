#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
# from tf_transformations import euler_from_quaternion
import math

import numpy as np
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped, AckermannDrive
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
from visualization_msgs.msg import Marker, MarkerArray
from geometry_msgs.msg import Point
from std_msgs.msg import ColorRGBA

from os.path import join

# get the file path for this package
csv_loc = '/home/lucien/ESE6150/traj_map.csv'

#  Constants from xacro
WIDTH = 0.2032  # (m)
WHEEL_LENGTH = 0.0381  # (m)
MAX_STEER = 0.36  # (rad)


class PurePursuit(Node):
    """ 
    Implement Pure Pursuit on the car
    This is just a template, you are free to implement your own node!
    """

    def __init__(self):
        super().__init__('pure_pursuit_node')

        # Params
        self.declare_parameter('if_real', False)
        self.declare_parameter('lookahead_distance', 2.7)
        self.declare_parameter('lookahead_points', 15)      # to calculate yaw diff
        self.declare_parameter('lookbehind_points', 2)      # to eliminate the influence of latency
        self.declare_parameter('L_slope_atten', 0.5)        # attenuate lookahead distance with large yaw, (larger: smaller L when turning)

        self.declare_parameter('kp', 0.6)
        self.declare_parameter('ki', 0.0)
        self.declare_parameter('kd', 0.005)
        self.declare_parameter("max_control", MAX_STEER)
        self.declare_parameter("steer_alpha", 1.0)

        # PID Control Params
        self.prev_error = 0.0
        self.integral = 0.0
        self.prev_steer = 0.0
        
        self.flag = self.get_parameter('lookahead_distance').get_parameter_value().bool_value

        # TODO: Get target x and y from pre-calculated waypoints
        waypoints = np.loadtxt(csv_loc, delimiter=',')
        self.x_list = waypoints[:, 0]
        self.y_list = waypoints[:, 1]
        self.v_list = waypoints[:, 2]
        self.xyv_list = waypoints[:, 0:2]   # (x,y,v)
        self.yaw_list = waypoints[:, 3]
        self.v_max = np.max(self.v_list)
        self.v_min = np.min(self.v_list)

        # Topics & Subs, Pubs
        
        if self.flag == True:  
            odom_topic = '/pf/viz/inferred_pose'
            self.odom_sub_ = self.create_subscription(PoseStamped, odom_topic, self.pose_callback, 10)
        else:
            odom_topic = '/ego_racecar/odom'
            self.odom_sub_ = self.create_subscription(Odometry, odom_topic, self.pose_callback, 10)
        drive_topic = '/drive'
        waypoint_topic = '/waypoint'
        waypoint_path_topic = '/waypoint_path'

        self.traj_published = False
        self.drive_pub_ = self.create_publisher(AckermannDriveStamped, drive_topic, 10)
        self.waypoint_pub_ = self.create_publisher(Marker, waypoint_topic, 10)
        self.waypoint_path_pub_ = self.create_publisher(Marker, waypoint_path_topic, 10)

    def pose_callback(self, pose_msg):
        if self.flag == True:  
            curr_x = pose_msg.pose.position.x
            curr_y = pose_msg.pose.position.y
            curr_quat = pose_msg.pose.orientation
        else:
            curr_x = pose_msg.pose.pose.position.x
            curr_y = pose_msg.pose.pose.position.y
            curr_quat = pose_msg.pose.pose.orientation
        curr_pos = np.array([curr_x, curr_y])
        curr_yaw = math.atan2(2 * (curr_quat.w * curr_quat.z + curr_quat.x * curr_quat.y),
                              1 - 2 * (curr_quat.y ** 2 + curr_quat.z ** 2))

        # find the closest current point
        # find index of closest point
        distances = np.linalg.norm(self.xyv_list - curr_pos, axis=1)
        min_idx = np.argmin(distances)
        closest_point = self.xyv_list[min_idx, :]

        # change L based on another lookahead distance for yaw difference!
        L = self.get_parameter('lookahead_distance').get_parameter_value().double_value
        lookahead_points = self.get_parameter('lookahead_points').get_parameter_value().integer_value
        lookbehind_points = self.get_parameter('lookbehind_points').get_parameter_value().integer_value
        
        future_yaw_target = self.yaw_list[(min_idx + lookahead_points) % self.yaw_list.shape[0]]
        past_yaw_target = self.yaw_list[(min_idx - lookbehind_points) % self.yaw_list.shape[0]]
        yaw_diff = abs(past_yaw_target - future_yaw_target)
        if yaw_diff > np.pi:
            yaw_diff = yaw_diff - 2 * np.pi
        if yaw_diff < -np.pi:
            yaw_diff = yaw_diff + 2 * np.pi
        yaw_diff = abs(yaw_diff)
        L = self.decrease_lookahead(L, yaw_diff)
        gamma = 2 / L ** 2  # curvature of arc

        # TODO: find the current waypoint to track using methods mentioned in lecture
        self.curr_target_idx = min_idx
        next_idx = min_idx + 1
        next_dist = distances[next_idx % len(distances)]
        while (next_dist <= L):
            min_idx = next_idx
            next_idx = next_idx + 1
            next_dist = distances[next_idx % distances.shape[0]]  # avoid hitting the array's end
        # once points are found, find linear interpolation of them through binary search 
        # until it's at the right distance L
        close_point = self.xyv_list[min_idx % distances.shape[0], :]
        far_point = self.xyv_list[next_idx % distances.shape[0], :]
        dist_btwn_ends = np.linalg.norm(far_point - close_point)
        guess_point = self.proj_along(close_point, far_point, dist_btwn_ends / 2)
        dist_to_guess = np.linalg.norm(curr_pos - guess_point)
        num_iters = 0
        while (abs(dist_to_guess - L) > 0.01):
            if (dist_to_guess > L):  # too far away, set the guess point as the far point
                far_point = guess_point
                dist_btwn_ends = np.linalg.norm(far_point - close_point)
                direction = -1  # go backward
            else:  # too close, set the guess point as the close point
                close_point = guess_point
                dist_btwn_ends = np.linalg.norm(far_point - close_point)
                direction = 1  # go forward
            # recalculate
            guess_point = self.proj_along(close_point, far_point, direction * dist_btwn_ends / 2)
            dist_to_guess = np.linalg.norm(curr_pos - guess_point)
            num_iters = num_iters + 1
        self.target_point = guess_point
        # print(num_iters)

        # TODO: transform goal point to vehicle frame of reference
        R = np.array([[np.cos(curr_yaw), np.sin(curr_yaw)],
                      [-np.sin(curr_yaw), np.cos(curr_yaw)]])
        target_x, target_y = R @ np.array([self.target_point[0] - curr_x,
                                           self.target_point[1] - curr_y])
        target_v = self.v_list[self.curr_target_idx % len(self.v_list)]
        # compute error using the lookahead distance
        error = gamma * target_y

        # TODO: publish drive message, don't forget to limit the steering angle.
        message = AckermannDriveStamped()
        message.drive.speed = target_v
        message.drive.steering_angle = self.get_steer(error)
        self.get_logger().info('speed: %f, steer: %f' % (target_v, self.get_steer(error)))
        self.drive_pub_.publish(message)

        # remember to visualize the waypoints
        self.visualize_waypoints()


    # travel a certain distance from one point in the direction of another
    def proj_along(self, start, target, dist):
        # find unit vector from start to target
        vect = target - start
        if (np.linalg.norm(vect) < 0.0001):
            return start
        unit = vect / np.linalg.norm(vect)
        # travel that distance
        new_point = dist * unit + start
        return new_point

    def decrease_lookahead(self, L, yaw_diff):
        slope = self.get_parameter('L_slope_atten').get_parameter_value().double_value
        # print(yaw_diff)
        if (yaw_diff > np.pi / 2):
            yaw_diff = np.pi / 2
        L = max(0.5, L * ((np.pi / 2 - yaw_diff * slope) / (np.pi / 2)))

        return L

    def visualize_waypoints(self):
        # TODO: publish the waypoints properly
        marker = Marker()
        marker.header.frame_id = '/map'
        marker.id = 0
        marker.ns = 'pursuit_waypoint' + str(0)
        marker.type = 4
        marker.action = 0
        marker.points = []
        marker.colors = []
        length = self.x_list.shape[0]
        for i in range(length + 1):
            this_point = Point()
            this_point.x = self.x_list[i % length]
            this_point.y = self.y_list[i % length]
            marker.points.append(this_point)

            this_color = ColorRGBA()
            normalized_target_speed = (self.v_list[i % length] - self.v_min) / (self.v_max - self.v_min)
            this_color.a = 1.0
            this_color.r = (1 - normalized_target_speed)
            this_color.g = normalized_target_speed
            marker.colors.append(this_color)

        this_scale = 0.1
        marker.scale.x = this_scale
        marker.scale.y = this_scale
        marker.scale.z = this_scale

        marker.pose.orientation.w = 1.0

        self.waypoint_path_pub_.publish(marker)

        # also publish the target but larger
        marker = Marker()
        marker.header.frame_id = '/map'
        marker.id = 0
        marker.ns = 'pursuit_waypoint_target'
        marker.type = 1
        marker.action = 0
        marker.pose.position.x = self.target_point[0]
        marker.pose.position.y = self.target_point[1]

        normalized_target_speed = self.v_list[self.curr_target_idx] / self.v_max
        marker.color.a = 1.0
        marker.color.r = (1 - normalized_target_speed)
        marker.color.g = normalized_target_speed

        this_scale = 0.2
        marker.scale.x = this_scale
        marker.scale.y = this_scale
        marker.scale.z = this_scale

        marker.pose.orientation.w = 1.0

        self.waypoint_pub_.publish(marker)

    def get_steer(self, error):
        """ Get desired steering angle by PID
        """
        kp = self.get_parameter('kp').get_parameter_value().double_value
        ki = self.get_parameter('ki').get_parameter_value().double_value
        kd = self.get_parameter('kd').get_parameter_value().double_value
        max_control = self.get_parameter('max_control').get_parameter_value().double_value
        alpha = self.get_parameter('steer_alpha').get_parameter_value().double_value

        d_error = error - self.prev_error
        self.prev_error = error
        self.integral += error
        steer = kp * error + ki * self.integral + kd * d_error
        new_steer = np.clip(steer, -max_control, max_control)
        new_steer = alpha * new_steer + (1 - alpha) * self.prev_steer
        self.prev_steer = new_steer

        return new_steer


def main(args=None):
    
    rclpy.init(args=args)
    print("PurePursuit Initialized")
    pure_pursuit_node = PurePursuit()
    rclpy.spin(pure_pursuit_node)

    pure_pursuit_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
