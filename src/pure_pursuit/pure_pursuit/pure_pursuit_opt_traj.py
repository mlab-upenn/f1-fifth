import os
import math
import rclpy
import numpy as np
import pandas as pd

from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
#from vision_msgs.msg import Detection2DArray
from ackermann_msgs.msg import AckermannDriveStamped
from geometry_msgs.msg import PoseWithCovarianceStamped, PoseStamped, Pose
from nav_msgs.msg import Odometry
from nav_msgs.msg import Odometry
from math import cos, asin, sqrt, pi
from PyQt5.QtWidgets import QApplication
from pyqtgraph.Qt import QtCore
import pyqtgraph as pg
import threading

class PurePursuit_node(Node):
    def __init__(self):
        super().__init__("purepursuit_node")

        self.declare_parameters(
            namespace='',
            parameters=[
                # control 
                ('minL', 4.0),
                ('maxL', 4.0),
                ('minL_corner', 4.0),
                ('maxL_corner', 4.0),
                ('interpScale', 20),
                ('minP', 4.0),
                ('maxP', 4.0),
                ('minP_corner', 4.0),
                ('maxP_corner', 4.0),
                ('max_steer', 0.95),
                ('D', 1.0),
                ('vel_scale', 2.0),

                # wp
                ('wp_filename', "interpolated_trajectory.csv"), #pp_mincurv_1.csv
                ('wp_delim', ';'),
                ('wp_skiprows', 1),
                ('config_path', "/home/nvidia/f1-fifth/src/trajectory_csv"),
                ('wp_x_idx', 1),
                ('wp_y_idx', 2),
                ('wp_v_idx', 5),

                # topics
                ('pose_topic', '/gnss_to_local/local_position'),
                ('odom_topic', '/fixposition/odometry'),
                ('drive_topic', '/drive'),
            ])

        self.get_logger().info("purepursuit node initialized")
        self.drive_pub = self.create_publisher(AckermannDriveStamped, self.get_parameter('drive_topic').get_parameter_value().string_value, 10)
        self.target_pub = self.create_publisher(Point, '/pp_target', 10)
        self.pose_sub = self.create_subscription(PoseWithCovarianceStamped, self.get_parameter('pose_topic').get_parameter_value().string_value, self.pose_cb, 10)
        self.odom_sub = self.create_subscription(Odometry, self.get_parameter('odom_topic').get_parameter_value().string_value, self.odom_cb, 10)
        
        self.lane = None
        self.last_lane = 0
        self.curr_vel = 0.0
        self.prev_ditem = 0.0
        self.prev_steer_error = 0.0

        # control parameters
        self.maxL = self.get_parameter('maxL').get_parameter_value().double_value
        self.minL = self.get_parameter('minL').get_parameter_value().double_value
        self.maxL_corner = self.get_parameter('maxL_corner').get_parameter_value().double_value
        self.minL_corner = self.get_parameter('minL_corner').get_parameter_value().double_value
        self.interpScale = self.get_parameter('interpScale').get_parameter_value().integer_value
        self.maxP = self.get_parameter('maxP').get_parameter_value().double_value
        self.minP = self.get_parameter('minP').get_parameter_value().double_value
        self.maxP_corner = self.get_parameter('maxP_corner').get_parameter_value().double_value
        self.minP_corner = self.get_parameter('minP_corner').get_parameter_value().double_value
        self.max_steer = self.get_parameter('max_steer').get_parameter_value().double_value
        self.kd = self.get_parameter('D').get_parameter_value().double_value
        self.vel_scale = self.get_parameter('vel_scale').get_parameter_value().double_value
        
        self.initial_x = None
        self.initial_y = None
        self.initial_z = None

        # Initialize PyQtGraph
        pg.setConfigOption('background', 'w')
        pg.setConfigOption('foreground', 'k') 
        self.app = QApplication([])
        self.win = pg.GraphicsLayoutWidget(show=True, title="Robot Position Tracking")
        self.plot = self.win.addPlot(title="Trajectory and Waypoints")
        self.plot.enableAutoRange('xy', True)
        self.plot.setAspectLocked(True)

        self.waypoints_plot = pg.ScatterPlotItem(size=5, brush=pg.mkBrush(0, 0, 255), name="Waypoints")
        self.trajectory_plot = pg.PlotCurveItem(pen=pg.mkPen('r', width=2), name="Trajectory")
        self.current_location_plot = pg.ScatterPlotItem(size=10, brush=pg.mkBrush(0, 255, 0), name="Current Location")

        self.plot.addItem(self.waypoints_plot)
        self.plot.addItem(self.trajectory_plot)
        self.plot.addItem(self.current_location_plot)

        self.load_wp(wp_path=os.path.join(self.get_parameter('config_path').value, self.get_parameter('wp_filename').get_parameter_value().string_value),
                     delim=self.get_parameter('wp_delim').get_parameter_value().string_value,
                     skiprow=self.get_parameter('wp_skiprows').get_parameter_value().integer_value)

        self.points = []
        self.current_point = []

        self.update_timer = QtCore.QTimer()
        self.update_timer.timeout.connect(self.update_plot)
        self.update_timer.start(50)

        self.legend = self.plot.addLegend()

        self.legend.addItem(self.waypoints_plot, 'Waypoints')
        self.legend.addItem(self.trajectory_plot, 'Trajectory')
        self.legend.addItem(self.current_location_plot, 'Current Position')

    def load_wp(self, wp_path: str, delim: str, skiprow: int):
        self.get_logger().info("Loading waypoints from {}".format(wp_path))
        waypoints = np.loadtxt(wp_path, delimiter=delim, skiprows=skiprow)
        print("waypoints loaded")
        print("waypoints [0]", waypoints[0])
        
        # if waypoints[0, 0] == 999:
        # self.initial_x = float(waypoints[0, 0])
        # self.initial_y = float(waypoints[0, 1])
        # self.initial_z = float(waypoints[0, 2])
        # initial_pose =  np.zeros((10, 2))
        # for i in range(10):
        #     initial_pose[i,0] = self.pose_sub.pose.pose.position.x
        #     initial_pose[i,1] = self.pose_sub.pose.pose.position.y
        #     initial_pose[i,2] = self.pose_sub.pose.pose.position.z
        # self.initial_x = np.mean(initial_pose[:, 0])
        # self.initial_y = np.mean(initial_pose[:, 1])
        # self.initial_z = np.mean(initial_pose[:, 2])
        self.initial_x = 815.38
        self.initial_y = 1067.615
        self.initial_z = 3.854
        print(f"Initial pose: {self.initial_x}, {self.initial_y}")
        print("self.initial x, y, and z: ", self.initial_x, self.initial_y, self.initial_z)
        waypoints = waypoints[1:]

        waypoints = np.vstack((waypoints[:, self.get_parameter("wp_x_idx").get_parameter_value().integer_value], 
                               waypoints[:, self.get_parameter("wp_y_idx").get_parameter_value().integer_value], 
                               waypoints[:, self.get_parameter("wp_v_idx").get_parameter_value().integer_value])).T
        max_v = np.max(waypoints[:, 2]) * self.vel_scale

        # df = pd.read_csv(wp_path, delimiter=delim)
        # print(df.shape)
        # print(df)

        # # Get initial position
        # initial_row = df.iloc[0]
        # self.initial_x = float(initial_row[0])
        # self.initial_y = float(initial_row[1])
        # self.initial_z = float(initial_row[2])
        # self.get_logger().info(f"Initial position loaded: ({self.initial_x}, {self.initial_y}, {self.initial_z})")

        # # Load waypoints
        # waypoints = df.iloc[1:].to_numpy()
        # print(waypoints.shape)
        # waypoints = np.vstack((waypoints[:, self.get_parameter("wp_x_idx").get_parameter_value().integer_value], 
        #                        waypoints[:, self.get_parameter("wp_y_idx").get_parameter_value().integer_value], 
        #                        waypoints[:, self.get_parameter("wp_v_idx").get_parameter_value().integer_value])).T
        # # max_v = np.max(waypoints[:, 2]) * self.vel_scale
        # max_v = np.ones(waypoints.shape[0]) * self.vel_scale


        self.Pscale = max_v
        self.Lscale = max_v
        self.Pscale_corner = max_v
        self.Lscale_corner = max_v
        self.get_logger().info("max_v: {}".format(max_v))
        self.lane = np.expand_dims(waypoints, axis=0)


        self.waypoints_plot.setData([{'pos': (wp[0], wp[1]), 'data': 1} for wp in waypoints])

    def pose_cb(self, pose_msg: PoseWithCovarianceStamped):
        if self.initial_x is None and self.initial_y is None and self.initial_z is None:
            print("initial x,y, and z are None")
            return

        curr_x = pose_msg.pose.pose.position.x - self.initial_x
        curr_y = pose_msg.pose.pose.position.y - self.initial_y
        # print("initial x, y", self.initial_x, self.initial_y)
        # print("curr_x, y: ", curr_x, curr_y)

        self.points.append((curr_x, curr_y))
        self.current_point = [(curr_x, curr_y)]
        cur_speed = self.curr_vel
        # curr_x = pose_msg.pose.pose.position.x
        # curr_y = pose_msg.pose.pose.position.y
        curr_pos = np.array([curr_x, curr_y])
        curr_quat = pose_msg.pose.pose.orientation
        curr_yaw = math.atan2(2 * (curr_quat.w * curr_quat.z + curr_quat.x * curr_quat.y),
                              1 - 2 * (curr_quat.y ** 2 + curr_quat.z ** 2))
        curr_yaw += pi

        curr_pos_idx = np.argmin(np.linalg.norm(self.lane[0][:, :2] - curr_pos, axis=1))
        curr_lane_nearest_idx = np.argmin(np.linalg.norm(self.lane[self.last_lane][:, :2] - curr_pos, axis=1))

        L = self.get_L_w_speed(cur_speed, corner=False)

        num_lane_pts = len(self.lane[self.last_lane])
        segment_end = curr_pos_idx
        traj_distances = np.linalg.norm(self.lane[self.last_lane][:, :2] - self.lane[self.last_lane][curr_lane_nearest_idx, :2], axis=1)

        while traj_distances[segment_end] <= L:
            segment_end = (segment_end + 1) % num_lane_pts

        segment_begin = (segment_end - 1 + num_lane_pts) % num_lane_pts
        x_array = np.linspace(self.lane[self.last_lane][segment_begin][0], self.lane[self.last_lane][segment_end][0], self.interpScale)
        y_array = np.linspace(self.lane[self.last_lane][segment_begin][1], self.lane[self.last_lane][segment_end][1], self.interpScale)
        v_array = np.linspace(self.lane[self.last_lane][segment_begin][2], self.lane[self.last_lane][segment_end][2], self.interpScale)
        xy_interp = np.vstack([x_array, y_array]).T
        dist_interp = np.linalg.norm(xy_interp-curr_pos, axis=1) - L
        i_interp = np.argmin(np.abs(dist_interp))
        target_global = np.array([x_array[i_interp], y_array[i_interp]])
        self.target_point = target_global
        pub_target_point = Point()
        pub_target_point.x = target_global[0]
        pub_target_point.y = target_global[1]
        self.target_pub.publish(pub_target_point)
        target_v = v_array[i_interp]
        # speed = 1.0
        speed = target_v

        R = np.array([[np.cos(curr_yaw), np.sin(curr_yaw)],
                      [-np.sin(curr_yaw), np.cos(curr_yaw)]])

        target_local_x, target_local_y = R @ np.array([self.target_point[0] - curr_x,
                                                       self.target_point[1] - curr_y])
        L = np.linalg.norm(curr_pos - target_global)
        gamma = 2 / L ** 2
        error = gamma * target_local_y
        steer = self.get_steer_w_speed(cur_speed, error)

        message = AckermannDriveStamped()
        message.drive.speed = speed
        message.drive.steering_angle = steer

        self.drive_pub.publish(message)
        print("curr_x:{}, curr_y:{}, curr_yaw:{}, speed:{}, steer:{}".format(curr_x, curr_y, curr_yaw, speed, steer))

        # self.points.append((curr_x, curr_y))
        # self.current_point = [(curr_x, curr_y)]

    def odom_cb(self, odom: Odometry):
        self.curr_vel = -odom.twist.twist.linear.x

    def get_L_w_speed(self, speed, corner=False):
        if corner:
            interp_L_scale = (self.maxL_corner-self.minL_corner) / self.Lscale_corner
            return interp_L_scale * speed + self.minL_corner
        else:
            interp_L_scale = (self.maxL-self.minL) / self.Lscale
            return interp_L_scale * speed + self.minL

    def get_steer_w_speed(self, speed, error, corner=False):
        if corner:
            maxP = self.maxP_corner
            minP = self.minP_corner
            Pscale = self.Pscale_corner
        else:
            maxP = self.maxP
            minP = self.minP
            Pscale = self.Pscale

        interp_P_scale = (maxP-minP) / Pscale
        cur_P = maxP - speed * interp_P_scale

        d_error = error - self.prev_steer_error

        self.prev_ditem = d_error
        self.prev_steer_error = error
        if corner:
            steer = cur_P * error
        else:
            steer = cur_P * error

        new_steer = np.clip(steer, -self.max_steer, self.max_steer)
        return new_steer

    def update_plot(self):
        # print("plot updated")
        if self.points:
            points_array = np.array(self.points)
            self.trajectory_plot.setData(points_array[:, 0], points_array[:, 1])
        if self.current_point:
            self.current_location_plot.setData([{'pos': self.current_point[0], 'data': 1}])

def main(args=None):
    rclpy.init(args=args)
    node = PurePursuit_node()

    executor_thread = threading.Thread(target=rclpy.spin, args=(node,), daemon=True)
    executor_thread.start()

    QApplication.instance().exec_()

    node.destroy_node()
    rclpy.shutdown()
    executor_thread.join()

if __name__ == "__main__":
    main()
