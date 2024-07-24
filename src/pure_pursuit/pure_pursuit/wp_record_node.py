import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import NavSatFix, Imu
from vision_msgs.msg import Detection2DArray
from geometry_msgs.msg import PoseWithCovarianceStamped
from nav_msgs.msg import Odometry
from math import sin, cos, asin, sqrt, pi, radians, atan2
from tf_transformations import euler_from_quaternion
from collections import namedtuple
import numpy as np
import math
import threading
import transforms3d
import os
from PyQt5.QtWidgets import QApplication
from pyqtgraph.Qt import QtCore
import pyqtgraph as pg
from datetime import datetime


class Wp_record_node(Node):
    def __init__(self):
        super().__init__("wp_record_node")
        print("initialized")

        self.declare_parameters(
            namespace='',
            parameters=[
                ('frequency', 2),
                ('pose_topic', '/gnss_to_local/local_position'),
                ('config_path', "/home/nvidia/pure_pursuit_results"),
                ('velocity', 1.0),
                ('odometry_topic', '/fixposition/odometry'),
            ])
        self.freq = self.get_parameter('frequency').get_parameter_value().integer_value
        self.dt = 1/self.freq
        self.v = self.get_parameter('velocity').get_parameter_value().double_value

        now = datetime.now()
        timestamp = now.strftime("%Y%m%d_%H%M%S")
        wp_filename = f"wp_{timestamp}.csv"

        # subscribe and publish
        self.pose_sub = self.create_subscription(PoseWithCovarianceStamped, self.get_parameter('pose_topic').get_parameter_value().string_value, 
                                                 self.pose_cb,10)
        self.odom_sub = self.create_subscription(Odometry, self.get_parameter('odometry_topic').get_parameter_value().string_value, 
                                                 self.odom_cb,10)
        print("pose subscription")
        self.timer = self.create_timer(self.dt, self.record_wp)
        self.get_logger().info(self.get_parameter('config_path').value)
        self.wp_path = os.path.join(self.get_parameter('config_path').value, wp_filename)
        self.get_logger().info("wp_record_node save wp to {}".format(self.wp_path))
        self.get_logger().info("wp_record_node initialized, frequency: {}".format(self.freq))

        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        self.initial_x = None
        self.initial_y = None
        self.initial_z = None
        with open(self.wp_path, 'w') as f:
            f.write(f"{self.x},{self.y},{self.z},{self.v}\n")
        
        # Initialize PyQtGraph
        self.app = QApplication([])
        self.win = pg.GraphicsLayoutWidget(show=True, title="Robot Position")
        self.plot = self.win.addPlot(title="Current Location")
        self.plot.setXRange(-10, 10)
        self.plot.setYRange(-10, 10)
        self.trajectory = pg.PlotCurveItem(pen=pg.mkPen('r', width=2))
        self.current_location = pg.ScatterPlotItem(size=10, brush=pg.mkBrush(0, 255, 0))
        self.plot.addItem(self.trajectory)
        self.plot.addItem(self.current_location)

        self.points = []
        self.current_point = []

        self.update_timer = QtCore.QTimer()
        self.update_timer.timeout.connect(self.update_plot)
        self.update_timer.start(50)

    def pose_cb(self, pose_msg: PoseWithCovarianceStamped):
        if self.initial_x is None and self.initial_y is None and self.initial_z is None:
            self.initial_x = pose_msg.pose.pose.position.x
            self.initial_y = pose_msg.pose.pose.position.y
            self.initial_z = pose_msg.pose.pose.position.z

            with open(self.wp_path, 'w') as f:
                f.write(f"{self.initial_x},{self.initial_y},{self.initial_z}\n")


        # Transform GNSS coordinates to robot frame
        gnss_x = pose_msg.pose.pose.position.x
        gnss_y = pose_msg.pose.pose.position.y
        gnss_z = pose_msg.pose.pose.position.z

        # FixPosition is mounted backward
        robot_x = -(gnss_x - self.initial_x)
        robot_y = -(gnss_y - self.initial_y)  
        robot_z = gnss_z - self.initial_z

        self.x = robot_x
        self.y = robot_y
        self.z = robot_z

        local_quat = np.array([pose_msg.pose.pose.orientation.x,pose_msg.pose.pose.orientation.y,pose_msg.pose.pose.orientation.z,pose_msg.pose.pose.orientation.w])
        yaw = euler_from_quaternion(local_quat)[2]
        # FixPosition is mounted backward
        yaw += pi
        # Normalize yaw to be within the range [0, 2π]
        if yaw < 0:
            yaw += 2 * np.pi
        elif yaw >= 2 * np.pi:
            yaw -= 2 * np.pi
        self.yaw = yaw

        print(f"pose call back x: {self.x}, y: {self.y}, z: {self.z}, yaw: {self.yaw}")
        self.points.append((self.x, self.y, self.z))
        self.current_point = [(self.x, self.y, self.z)]

    def odom_cb(self, odom_msg: Odometry):
        vx = odom_msg.twist.twist.linear.x
        vy = odom_msg.twist.twist.linear.y
        self.v = math.sqrt(vx**2 + vy**2)

    def record_wp(self):
        with open(self.wp_path, 'a') as f:
            f.write(f"{self.x},{self.y},{self.z},{self.v},{self.yaw}\n")

    def update_plot(self):
        if self.points:
            points_array = np.array(self.points)
            self.trajectory.setData(points_array[:, 0], points_array[:, 1])
        if self.current_point:
            self.current_location.setData([{'pos': self.current_point[0][:2], 'data': 1}])

        # Automatically adjust the range of the plot
        self.plot.enableAutoRange()

def main(args=None):
    rclpy.init(args=args)

    node = Wp_record_node()
    
    executor_thread = threading.Thread(target=rclpy.spin, args=(node,), daemon=True)
    executor_thread.start()

    QApplication.instance().exec_()

    node.destroy_node()
    rclpy.shutdown()
    executor_thread.join()

if __name__ == '__main__':
    main()
