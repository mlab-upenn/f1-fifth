import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import NavSatFix, Imu
from vision_msgs.msg import Detection2DArray
from geometry_msgs.msg import PoseWithCovarianceStamped
from math import sin, cos, asin, sqrt, pi, radians, atan2
from collections import namedtuple
import numpy as np
import threading
import transforms3d
import os
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
                ('wp_filename', "wp.csv"),
                ('config_path', "/home/nvidia/pure_pursuit_results"),
                ('velocity', 1.0),
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
        print("pose subscription")
        self.timer = self.create_timer(self.dt, self.record_wp)
        self.get_logger().info(self.get_parameter('config_path').value)
        self.wp_path = os.path.join(self.get_parameter('config_path').value, wp_filename)
        self.get_logger().info("wp_record_node save wp to {}".format(self.wp_path))
        self.get_logger().info("wp_record_node initialized, frequency: {}".format(self.freq))

        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        with open(self.wp_path, 'w') as f:
            f.write(str(self.x) + ',' + str(self.y) + ',' + str(self.z) + ',' + str(self.v) + '\n')
                                               
    def pose_cb(self, pose_msg: PoseWithCovarianceStamped):
        self.x = pose_msg.pose.pose.position.x
        self.y = pose_msg.pose.pose.position.y
        self.z = pose_msg.pose.pose.position.z
        print("pose call back x: ", self.x, "y: " , self.y, "z: ", self.z)

    def record_wp(self):
        with open(self.wp_path, 'a') as f:
            f.write(str(self.x) + ',' + str(self.y) + ',' + str(self.z) + ',' + str(self.v) + '\n')


def main(args=None):
    rclpy.init(args=args)

    node = Wp_record_node()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()