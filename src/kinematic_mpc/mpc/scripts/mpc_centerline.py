# kinematic mpc that follows the mincurv optimized trajectory in L shape track
# This code uses fixposition (GNSS) to get the current longitudinal velocity of the robot instead of the drive command

import math
import os
from dataclasses import dataclass, field
import cvxpy
import numpy as np
import rclpy
from ackermann_msgs.msg import AckermannDriveStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
from rclpy.node import Node
from scipy.linalg import block_diag
from scipy.sparse import block_diag, csc_matrix, diags
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from utils import nearest_point
from PyQt5.QtWidgets import QApplication
from pyqtgraph.Qt import QtCore
import pyqtgraph as pg
import threading


@dataclass
class mpc_config:
    NXK: int = 4  # length of kinematic state vector: z = [x, y, v, yaw]
    NU: int = 2  # length of input vector: u = [steering speed, acceleration]
    TK: int = 7  # finite time horizon length - kinematic

    # TODO: you may need to tune the following matrices
    Rk: list = field(
        default_factory=lambda: np.diag([10, 100.0])
    )  # input cost matrix, penalty for inputs - [accel, steering_speed]
    Rdk: list = field(
        default_factory=lambda: np.diag([0.01, 100.0])
    )  # input difference cost matrix, penalty for change of inputs - [accel, steering_speed]
    Qk: list = field(
        default_factory=lambda: np.diag([25.5, 25.5, 5.5, 13.0])  
    )  # state error cost matrix, for the the next (T) prediction time steps [x, y, delta, v, yaw, yaw-rate, beta]
    Qfk: list = field(
        default_factory=lambda: np.diag([10.5, 10.5, 5.5, 13.0])
    )  # final state error matrix, penalty  for the final state constraints: [x, y, delta, v, yaw, yaw-rate, beta]

    N_IND_SEARCH: int = 20
    DTK: float = 0.1
    dlk: float = 0.03
    LENGTH: float = 0.9
    WIDTH: float = 0.54
    WB: float = 0.53
    MIN_STEER: float = -0.4189
    MAX_STEER: float = 0.4189
    MAX_DSTEER: float = np.deg2rad(180.0)
    MAX_SPEED: float = 12.0
    MIN_SPEED: float = 0.0
    MAX_ACCEL: float = 3.0 

    """
    N_IND_SEARCH: int = 20  # Search index number
    DTK: float = 0.1  # time step [s] kinematic
    dlk: float = 0.03  # dist step [m] kinematic
    LENGTH: float = 0.58  # Length of the vehicle [m]
    WIDTH: float = 0.31  # Width of the vehicle [m]
    WB: float = 0.33  # Wheelbase [m]
    MIN_STEER: float = -0.4189  # maximum steering angle [rad]
    MAX_STEER: float = 0.4189  # maximum steering angle [rad]
    MAX_DSTEER: float = np.deg2rad(180.0)  # maximum steering speed [rad/s]
    MAX_SPEED: float = 12.0  # maximum speed [m/s]
    MIN_SPEED: float = 0.0  # minimum backward speed [m/s]
    MAX_ACCEL: float = 3.0  # maximum acceleration [m/ss]"""


@dataclass
class State:
    x: float = 0.0
    y: float = 0.0
    delta: float = 0.0
    v: float = 0.0
    yaw: float = 0.0
    yawrate: float = 0.0
    beta: float = 0.0


class MPC(Node):
    def __init__(self):
        super().__init__('mpc_node')

        self.real_car = True
        self.config_path = "/home/nvidia/pure_pursuit_results"
        
        self.csv = "velocity_3_with_theta.csv"
        self.map_name = os.path.join(self.config_path, self.csv)
        self.waypoints = np.loadtxt(self.map_name, delimiter=',', skiprows=1) 



        #self.waypoints[:, 3] += math.pi/2

        drive_topic = '/drive'
        if self.real_car:
            odom_topic = '/pf/viz/inferred_pose'
        else:
            odom_topic = '/ego_racecar/odom'

        if self.real_car:
            self.sub_pose = self.create_subscription(PoseWithCovarianceStamped, '/gnss_to_local/local_position', self.pose_callback, 1)

        else:
            self.sub_pose = self.create_subscription(Odometry, odom_topic, self.pose_callback, 1)
        
        self.gnss = self.create_subscription(Odometry, '/fixposition/odometry', self.gnss_callback, 1)

        self.pub_drive = self.create_publisher(AckermannDriveStamped, drive_topic, 1)
        self.drive_msg = AckermannDriveStamped()
        self.config = mpc_config()
        self.odelta_v = None
        self.odelta = None
        self.oa = None
        self.init_flag = 0

        self.initial_x = None
        self.initial_y = None
        self.initial_yaw = None
        self.gnss_speed = 0
        if self.real_car:

            self.initial_x = 816.91
            self.initial_y = 1062.232

            print(f"Initial pose: {self.initial_x}, {self.initial_y}")
        """ if self.real_car:
            self.load_initial_pose() """
        
        self.mpc_prob_init()

        # Initialize PyQtGraph
        pg.setConfigOption('background', 'w')
        pg.setConfigOption('foreground', 'k')
        self.app = QApplication([])
        self.win = pg.GraphicsLayoutWidget(show=True, title="MPC Position Tracking")
        self.plot = self.win.addPlot(title="Trajectory and Waypoints")
        self.plot.enableAutoRange('xy', True)
        self.plot.setAspectLocked(True)

        self.waypoints_plot = pg.ScatterPlotItem(size=5, brush=pg.mkBrush(0, 0, 255), name="Waypoints")
        self.trajectory_plot = pg.PlotCurveItem(pen=pg.mkPen('r', width=2), name="Trajectory")
        self.current_location_plot = pg.ScatterPlotItem(size=10, brush=pg.mkBrush(0, 255, 0), name="Current Location")

        self.plot.addItem(self.waypoints_plot)
        self.plot.addItem(self.trajectory_plot)
        self.plot.addItem(self.current_location_plot)

        self.waypoints_plot.setData([{'pos': (wp[0], wp[1]), 'data': 1} for wp in self.waypoints])

        self.points = []
        self.current_point = []

        self.update_timer = QtCore.QTimer()
        self.update_timer.timeout.connect(self.update_plot)
        self.update_timer.start(50)

        self.legend = self.plot.addLegend()
        self.legend.addItem(self.waypoints_plot, 'Waypoints')
        self.legend.addItem(self.trajectory_plot, 'Trajectory')
        self.legend.addItem(self.current_location_plot, 'Current Position')

    def load_initial_pose(self):
        wp = np.loadtxt(self.map_name, delimiter=",", skiprows=1, max_rows=1)
        if   not self.real_car:
            self.initial_x = wp[0]
            self.initial_y = wp[1]
            print(f"Initial pose on simulation: {self.initial_x}, {self.initial_y}")

    def pose_callback(self, pose_msg):
        vehicle_state = self.get_vehicle_state(pose_msg)
        # x_m,y_m,w_tr_right_m,w_tr_left_m,v,theta
        ref_path = self.calc_ref_trajectory(vehicle_state, self.waypoints[:, 0], self.waypoints[:, 1], self.waypoints[:,5], self.waypoints[:, 4])
        x0 = [vehicle_state.x, vehicle_state.y, vehicle_state.v, vehicle_state.yaw]
        (
            self.oa,
            self.odelta_v,
            ox,
            oy,
            oyaw,
            ov,
            state_predict,
        ) = self.linear_mpc_control(ref_path, x0, self.oa, self.odelta_v)

        steer_output = self.odelta_v[0]
        speed_output = vehicle_state.v + self.oa[0] * self.config.DTK
        self.drive_msg.drive.steering_angle = steer_output
        self.drive_msg.drive.speed = speed_output
        # print(f"Steering: {steer_output}, Speed: {speed_output}")
        self.pub_drive.publish(self.drive_msg)

        self.points.append((vehicle_state.x, vehicle_state.y))
        self.current_point = [(vehicle_state.x, vehicle_state.y)]

    def gnss_callback(self, nav_msg):
        self.gnss_speed = -nav_msg.twist.twist.linear.x

        print("gnss speed: ", self.gnss_speed, "drive topic speed: ", self.drive_msg.drive.speed)

    def get_vehicle_state(self, pose_msg):
        vehicle_state = State()

        if self.real_car:
            if self.initial_x==None or self.initial_y==None:
                T=10
                initial_state = np.zeros((T,2))
                for i in range(T):
                    initial_state[i,0] = pose_msg.pose.pose.position.x
                    initial_state[i,1] = pose_msg.pose.pose.position.y
                self.initial_x = np.mean(initial_state[:,0])
                self.initial_y = np.mean(initial_state[:,1])
                print(f"Initial pose on real car: {self.initial_x}, {self.initial_y}")
            vehicle_state.x = (pose_msg.pose.pose.position.x - self.initial_x)
            vehicle_state.y = (pose_msg.pose.pose.position.y - self.initial_y)
            curr_quat = pose_msg.pose.pose.orientation
            vehicle_state.yaw = math.atan2(2 * (curr_quat.w * curr_quat.z + curr_quat.x * curr_quat.y),
                              1 - 2 * (curr_quat.y ** 2 + curr_quat.z ** 2))
            vehicle_state.yaw += math.pi
            vehicle_state.yaw = np.arctan2(np.sin(vehicle_state.yaw), np.cos(vehicle_state.yaw))
            vehicle_state.v = self.gnss_speed
        else:
            vehicle_state.x = pose_msg.pose.pose.position.x
            vehicle_state.y = pose_msg.pose.pose.position.y
            curr_quat = pose_msg.pose.pose.orientation
            vehicle_state.yaw = math.atan2(2 * (curr_quat.w * curr_quat.z + curr_quat.x * curr_quat.y),
                              1 - 2 * (curr_quat.y ** 2 + curr_quat.z ** 2))
            vehicle_state.v = self.drive_msg.drive.speed
            # vehicle_state.v = pose_msg.twist.twist.linear.x

        # quat = [quat_msg.x, quat_msg.y, quat_msg.z, quat_msg.w]
        # vehicle_state.yaw = math.atan2(2 * (quat[3] * quat[2] + quat[0] * quat[1]), 1 - 2 * (quat[1] ** 2 + quat[2] ** 2))
        
        return vehicle_state

    def mpc_prob_init(self):
        """
        Create MPC quadratic optimization problem using cvxpy, solver: OSQP
        Will be solved every iteration for control.
        More MPC problem information here: https://osqp.org/docs/examples/mpc.html
        More QP example in CVXPY here: https://www.cvxpy.org/examples/basic/quadratic_program.html
        """
        # Initialize and create vectors for the optimization problem
        # Vehicle State Vector
        self.xk = cvxpy.Variable(
            (self.config.NXK, self.config.TK + 1) # 4*9
        )
        # Control Input vector
        self.uk = cvxpy.Variable(
            (self.config.NU, self.config.TK) # 2*8
        )
        objective = 0.0  # Objective value of the optimization problem
        constraints = []  # Create constraints array

        # Initialize reference vectors
        self.x0k = cvxpy.Parameter((self.config.NXK,))
        self.x0k.value = np.zeros((self.config.NXK,))

        # Initialize reference trajectory parameter
        self.ref_traj_k = cvxpy.Parameter((self.config.NXK, self.config.TK + 1))
        self.ref_traj_k.value = np.zeros((self.config.NXK, self.config.TK + 1))

        # Initializes block diagonal form of R = [R, R, ..., R] (NU*T, NU*T)
        R_block = block_diag(tuple([self.config.Rk] * self.config.TK))

        # Initializes block diagonal form of Rd = [Rd, ..., Rd] (NU*(T-1), NU*(T-1))
        Rd_block = block_diag(tuple([self.config.Rdk] * (self.config.TK - 1)))

        # Initializes block diagonal form of Q = [Q, Q, ..., Qf] (NX*T, NX*T)
        Q_block = [self.config.Qk] * (self.config.TK)
        Q_block.append(self.config.Qfk)
        Q_block = block_diag(tuple(Q_block))

        # Formulate and create the finite-horizon optimal control problem (objective function)
        # The FTOCP has the horizon of T timesteps

        # --------------------------------------------------------
        # TODO: fill in the objectives here, you should be using cvxpy.quad_form() somehwhere

        # TODO: Objective part 1: Influence of the control inputs: Inputs u multiplied by the penalty R
        obj1 = cvxpy.quad_form(cvxpy.vec(self.uk), R_block)
        # TODO: Objective part 2: Deviation of the vehicle from the reference trajectory weighted by Q, including final Timestep T weighted by Qf
        obj2 = cvxpy.quad_form(cvxpy.vec(self.xk - self.ref_traj_k), Q_block)
        # TODO: Objective part 3: Difference from one control input to the next control input weighted by Rd
        obj3 = cvxpy.quad_form(cvxpy.vec(cvxpy.diff(self.uk, axis=1)), Rd_block)

        # Sum all objectives
        objective = obj1 + obj2 + obj3

        # --------------------------------------------------------

        # Constraints 1: Calculate the future vehicle behavior/states based on the vehicle dynamics model matrices
        # Evaluate vehicle Dynamics for next T timesteps
        A_block = []
        B_block = []
        C_block = []
        # init path to zeros
        path_predict = np.zeros((self.config.NXK, self.config.TK + 1))
        for t in range(self.config.TK):
            A, B, C = self.get_model_matrix(
                path_predict[2, t], path_predict[3, t], 0.0
            ) # steering angle is 0
            A_block.append(A)
            B_block.append(B)
            C_block.extend(C)

        A_block = block_diag(tuple(A_block)) # 32*32
        B_block = block_diag(tuple(B_block)) # 32*16
        C_block = np.array(C_block) # 32*1

        # [AA] Sparse matrix to CVX parameter for proper stuffing
        # Reference: https://github.com/cvxpy/cvxpy/issues/1159#issuecomment-718925710
        m, n = A_block.shape # m = 32, n = 32
        self.Annz_k = cvxpy.Parameter(A_block.nnz)
        data = np.ones(self.Annz_k.size) # the size is the number of nonzero elements in the sparse matrix
        rows = A_block.row * n + A_block.col # row indices of each nonzero element
        cols = np.arange(self.Annz_k.size)  # column indices of each nonzero element
        # create a sparse matrix with 1 at the ith row for the ith nonzero element in A_block
        Indexer = csc_matrix((data, (rows, cols)), shape=(m * n, self.Annz_k.size))

        # Setting sparse matrix data
        self.Annz_k.value = A_block.data

        # Now we use this sparse version instead of the old A_ block matrix
        self.Ak_ = cvxpy.reshape(Indexer @ self.Annz_k, (m, n), order="C") # 32*32

        # Same as A
        m, n = B_block.shape
        self.Bnnz_k = cvxpy.Parameter(B_block.nnz)
        data = np.ones(self.Bnnz_k.size)
        rows = B_block.row * n + B_block.col
        cols = np.arange(self.Bnnz_k.size)
        Indexer = csc_matrix((data, (rows, cols)), shape=(m * n, self.Bnnz_k.size))
        self.Bk_ = cvxpy.reshape(Indexer @ self.Bnnz_k, (m, n), order="C")
        self.Bnnz_k.value = B_block.data

        # No need for sparse matrices for C as most values are parameters
        self.Ck_ = cvxpy.Parameter(C_block.shape)
        self.Ck_.value = C_block

        # -------------------------------------------------------------
        # TODO: Constraint part 1:
        #       Add dynamics constraints to the optimization problem
        #       This constraint should be based on a few variables:
        #       self.xk, self.Ak_, self.Bk_, self.uk, and self.Ck_
        # self.xk[:, 1:]: 4*8, self.xk[:, :-1]: 4*8,self.Ak_: 32*32, self.Bk_: 32*16, self.uk: 2*8, self.Ck_: 32*1
        constraint1 = cvxpy.vec(self.xk[:, 1:]) == self.Ak_ @ cvxpy.vec(self.xk[:, :-1]) + self.Bk_ @ cvxpy.vec(self.uk) + self.Ck_
        
        # TODO: Constraint part 2:
        #       Add constraints on steering, change in steering angle
        #       cannot exceed steering angle speed limit. Should be based on:
        #       self.uk, self.config.MAX_DSTEER, self.config.DTK
        constraint2 = cvxpy.abs(self.uk[1, 1:] - self.uk[1, :-1]) <= self.config.MAX_DSTEER * self.config.DTK
        
        # TODO: Constraint part 3:
        #       Add constraints on upper and lower bounds of states and inputs
        #       and initial state constraint, should be based on:
        #       self.xk, self.x0k, self.config.MAX_SPEED, self.config.MIN_SPEED,
        #       self.uk, self.config.MAX_ACCEL, self.config.MAX_STEER
        constraint3 = self.x0k == self.xk[:, 0]
        # State constraints
        constraint4 = cvxpy.abs(self.xk[2, :]) <= self.config.MAX_SPEED

        # Input constraints
        constraint5 = cvxpy.abs(self.uk[0, :]) <= self.config.MAX_ACCEL
        constraint6 = cvxpy.abs(self.uk[1, :]) <= self.config.MAX_STEER
        constraints = [constraint1, constraint2, constraint3, constraint4, constraint5, constraint6]
        # -------------------------------------------------------------

        # Create the optimization problem in CVXPY and setup the workspace
        # Optimization goal: minimize the objective function
        self.MPC_prob = cvxpy.Problem(cvxpy.Minimize(objective), constraints)

    def calc_ref_trajectory(self, state, cx, cy, cyaw, sp):
        """
        calc referent trajectory ref_traj in T steps: [x, y, v, yaw]
        using the current velocity, calc the T points along the reference path
        :param cx: Course X-Position
        :param cy: Course y-Position
        :param cyaw: Course Heading
        :param sp: speed profile
        :dl: distance step
        :pind: Setpoint Index
        :return: reference trajectory ref_traj, reference steering angle
        """

        # Create placeholder Arrays for the reference trajectory for T steps
        ref_traj = np.zeros((self.config.NXK, self.config.TK + 1))
        ncourse = len(cx)

        # Find nearest index/setpoint from where the trajectories are calculated
        _, _, _, ind = nearest_point(np.array([state.x, state.y]), np.array([cx, cy]).T)

        # Load the initial parameters from the setpoint into the trajectory
        ref_traj[0, 0] = cx[ind]
        ref_traj[1, 0] = cy[ind]
        ref_traj[2, 0] = sp[ind]
        ref_traj[3, 0] = cyaw[ind]

        # based on current velocity, distance traveled on the ref line between time steps
        travel = abs(state.v) * self.config.DTK
        dind = travel / self.config.dlk
        dind = 2
        ind_list = int(ind) + np.insert(
            np.cumsum(np.repeat(dind, self.config.TK)), 0, 0
        ).astype(int)
        ind_list[ind_list >= ncourse] -= ncourse
        ref_traj[0, :] = cx[ind_list]
        ref_traj[1, :] = cy[ind_list]
        ref_traj[2, :] = sp[ind_list]

        angle_thres = 4.5

        for i in range(len(cyaw)):
            if cyaw[i] - state.yaw > angle_thres:
                cyaw[i] -= 2*np.pi
            if state.yaw - cyaw[i] > angle_thres:
                cyaw[i] += 2*np.pi

        ref_traj[3, :] = cyaw[ind_list]

        return ref_traj
    
    def predict_motion(self, x0, oa, od, xref):
        path_predict = xref * 0.0
        for i, _ in enumerate(x0):
            path_predict[i, 0] = x0[i]

        state = State(x=x0[0], y=x0[1], yaw=x0[3], v=x0[2])
        for (ai, di, i) in zip(oa, od, range(1, self.config.TK + 1)):
            state = self.update_state(state, ai, di)
            path_predict[0, i] = state.x
            path_predict[1, i] = state.y
            path_predict[2, i] = state.v
            path_predict[3, i] = state.yaw

        return path_predict

    def update_state(self, state, a, delta):
        if delta >= self.config.MAX_STEER:
            delta = self.config.MAX_STEER
        elif delta <= -self.config.MAX_STEER:
            delta = -self.config.MAX_STEER

        state.x = state.x + state.v * math.cos(state.yaw) * self.config.DTK
        state.y = state.y + state.v * math.sin(state.yaw) * self.config.DTK
        state.yaw = (
            state.yaw + (state.v / self.config.WB) * math.tan(delta) * self.config.DTK
        )
        state.v = state.v + a * self.config.DTK

        if state.v > self.config.MAX_SPEED:
            state.v = self.config.MAX_SPEED
        elif state.v < self.config.MIN_SPEED:
            state.v = self.config.MIN_SPEED

        return state

    def get_model_matrix(self, v, phi, delta):
        """
        Calc linear and discrete time dynamic model-> Explicit discrete time-invariant
        Linear System: Xdot = Ax +Bu + C
        State vector: x=[x, y, v, yaw]
        :param v: speed
        :param phi: heading angle of the vehicle
        :param delta: steering angle: delta_bar
        :return: A, B, C
        """

        # State (or system) matrix A, 4x4
        A = np.zeros((self.config.NXK, self.config.NXK))
        A[0, 0] = 1.0
        A[1, 1] = 1.0
        A[2, 2] = 1.0
        A[3, 3] = 1.0
        A[0, 2] = self.config.DTK * math.cos(phi)
        A[0, 3] = -self.config.DTK * v * math.sin(phi)
        A[1, 2] = self.config.DTK * math.sin(phi)
        A[1, 3] = self.config.DTK * v * math.cos(phi)
        A[3, 2] = self.config.DTK * math.tan(delta) / self.config.WB

        # Input Matrix B; 4x2
        B = np.zeros((self.config.NXK, self.config.NU))
        B[2, 0] = self.config.DTK
        B[3, 1] = self.config.DTK * v / (self.config.WB * math.cos(delta) ** 2)

        C = np.zeros(self.config.NXK)
        C[0] = self.config.DTK * v * math.sin(phi) * phi
        C[1] = -self.config.DTK * v * math.cos(phi) * phi
        C[3] = -self.config.DTK * v * delta / (self.config.WB * math.cos(delta) ** 2)

        return A, B, C

    def mpc_prob_solve(self, ref_traj, path_predict, x0):
        self.x0k.value = x0

        A_block = []
        B_block = []
        C_block = []
        for t in range(self.config.TK):
            A, B, C = self.get_model_matrix(
                path_predict[2, t], path_predict[3, t], 0.0
            )
            A_block.append(A)
            B_block.append(B)
            C_block.extend(C)

        A_block = block_diag(tuple(A_block))
        B_block = block_diag(tuple(B_block))
        C_block = np.array(C_block)

        self.Annz_k.value = A_block.data
        self.Bnnz_k.value = B_block.data
        self.Ck_.value = C_block

        self.ref_traj_k.value = ref_traj

        # Solve the optimization problem in CVXPY
        # Solver selections: cvxpy.OSQP; cvxpy.GUROBI
        self.MPC_prob.solve(solver=cvxpy.OSQP, verbose=False, warm_start=True)

        if (
            self.MPC_prob.status == cvxpy.OPTIMAL
            or self.MPC_prob.status == cvxpy.OPTIMAL_INACCURATE
        ):
            ox = np.array(self.xk.value[0, :]).flatten()
            oy = np.array(self.xk.value[1, :]).flatten()
            ov = np.array(self.xk.value[2, :]).flatten()
            oyaw = np.array(self.xk.value[3, :]).flatten()
            oa = np.array(self.uk.value[0, :]).flatten()
            odelta = np.array(self.uk.value[1, :]).flatten()

        else:
            print("Error: Cannot solve mpc..")
            oa, odelta, ox, oy, oyaw, ov = None, None, None, None, None, None

        return oa, odelta, ox, oy, oyaw, ov

    def linear_mpc_control(self, ref_path, x0, oa, od):
        """
        MPC control with updating operational point iteratively.

        Args:
            ref_path (list): Reference trajectory in T steps.
            x0 (list): Initial state vector.
            oa (list): Acceleration of T steps from the last time. If None, it is initialized with zeros.
            od (list): Delta of T steps from the last time. If None, it is initialized with zeros.

        Returns:
            tuple: A tuple containing the following elements:
                - mpc_a (list): Acceleration calculated by MPC.
                - mpc_delta (list): Delta calculated by MPC.
                - mpc_x (list): X-coordinate of the predicted vehicle motion.
                - mpc_y (list): Y-coordinate of the predicted vehicle motion.
                - mpc_yaw (list): Yaw angle of the predicted vehicle motion.
                - mpc_v (list): Velocity of the predicted vehicle motion.
                - path_predict (list): Predicted vehicle motion for x-steps.
        """
        if oa is None or od is None:
            oa = [0.0] * self.config.TK
            od = [0.0] * self.config.TK

        # Call the Motion Prediction function: Predict the vehicle motion for x-steps
        path_predict = self.predict_motion(x0, oa, od, ref_path)
        poa, pod = oa[:], od[:]

        # Run the MPC optimization: Create and solve the optimization problem
        mpc_a, mpc_delta, mpc_x, mpc_y, mpc_yaw, mpc_v = self.mpc_prob_solve(
            ref_path, path_predict, x0
        )

        return mpc_a, mpc_delta, mpc_x, mpc_y, mpc_yaw, mpc_v, path_predict


    def update_plot(self):
        if self.points:
            points_array = np.array(self.points)
            self.trajectory_plot.setData(points_array[:, 0], points_array[:, 1])
        if self.current_point:
            self.current_location_plot.setData([{'pos': self.current_point[0], 'data': 1}])


def main(args=None):
    rclpy.init(args=args)
    print("Starting MPC Node")
    mpc_node = MPC()

    executor_thread = threading.Thread(target=rclpy.spin, args=(mpc_node,), daemon=True)
    executor_thread.start()

    QApplication.instance().exec_()

    mpc_node.destroy_node()
    rclpy.shutdown()
    executor_thread.join()


if __name__ == '__main__':
    main()