##############
####### Copied from https://github.com/mlab-upenn/gokart-autoware.universe/blob/main/gokart/Localization/ekf_gnss/ekf_gnss/ekf_gnss_node.py
##############

import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import NavSatFix, Imu
from nav_msgs.msg import Odometry
from ackermann_msgs.msg import AckermannDriveStamped
from vision_msgs.msg import Detection2DArray
from geometry_msgs.msg import PoseWithCovarianceStamped, Quaternion
from math import sin, cos, asin, sqrt, pi, radians, atan2
from collections import namedtuple
from gnss_to_local.ekf import EKF
import numpy as np
import threading
import transforms3d
from tf_transformations import quaternion_matrix, quaternion_from_matrix, quaternion_multiply, quaternion_inverse, quaternion_from_euler


X = namedtuple('X', ['sec', 'nanosec', 'x', 'y', 'yaw', 'v','omega'])
Stamped = namedtuple('Stamped', ['sec', 'nanosec', 'val'])


def get_Time(sec, nanosec):
    return sec + nanosec*1e-9

class Ekf_gnss_node(Node):
    def __init__(self):
        # here, super().__init__(<node_non from the odometry data
        # # q = msg.pose.pose.orientation
        # # q = np.array([q.w, q.x, q.y, q.z])
        # # self.q = q
        # origin_lat = 39.9416
        # origin_lon = -75.1993
        # origin_alt = -27.19
        # # Extract ECEF coordinates from odometry message
        # ecef_x = odom_msg.pose.pose.position.x
        # ecef_y = odom_msg.pose.pose.position.y
        # ecef_z = odom_msg.pose.pose.position.z
        # # Convert ECEF to local ENU coordinates
        # local_x, local_y, local_z = self.ecef_to_enu(ecef_x, ecef_y, ecef_z, origin_lat, origin_lon, origin_alt)
        # # self.last_x = Stamped(odom_msg.header.stamp.sec, odom_msg.header.stamp.nanosec, local_x)
        # # self.last_y = Stamped(odom_msg.header.stamp.sec, odom_msg.header.stamp.nanosec, local_y)
        
        # # Create a PoseWithCovarianceStamped message
        # pose_cov_msg = PoseWithCovarianceStamped()
        # # Set the header
        # pose_cov_msg.header.frame_id = "map"
        # # pose_cov_msg.header.stamp.sec = self.last_x.sec
        # # pose_cov_msg.header.stamp.nanosec = self.last_x.nanosec
        # pose_cov_msg.header.stamp.sec = odom_msg.header.stamp.sec
        # pose_cov_msg.header.stamp.nanosec = odom_msg.header.stamp.nanosec
        # # Set the pose in local frame
        # pose_cov_msg.pose.pose.position.x = local_x
        # pose_cov_msg.pose.pose.position.y = local_y
        # pose_cov_msg.pose.pose.position.z = local_z
        # pose_cov_msg.pose.pose.orientation = odom_msg.pose.pose.orientation
        # print("local_x: ", local_x, ", local_y: ", local_y, " local_z: ", local_z)
        # # Set the covariance
        # pose_cov_msg.pose.covariance = odom_msg.pose.covariance
        # # Publish the PoseWithCovarianceStamped message
        # self.ekf_pub.publish(pose_cov_msg)ame>), while the node_name should be the same as provided in launch yaml file
        super().__init__("ekf_gnss_node")

        self.declare_parameters(
            namespace='',
            parameters=[
                ('frequency', 20),
                ('origin_latitude', 39.9416),
                ('origin_longitude', -75.1993),
                ('origin_altitude', -27.19),
            ])
        self.freq = self.get_parameter('frequency').get_parameter_value().integer_value
        self.origin_lat = self.get_parameter('origin_latitude').get_parameter_value().double_value
        self.origin_lon = self.get_parameter('origin_longitude').get_parameter_value().double_value
        self.origin_alt = self.get_parameter('origin_altitude').get_parameter_value().double_value

        self.dt = 1/self.freq
        
        self.ekf = EKF()
        
        # subscribe and publish
        self.get_logger().info("ekf_gnss node initialized, dt = %f" % self.dt)
        # self.gnss_local_sub = self.create_subscription(PoseWithCovarianceStamped, "/gnss_local", self.gnss_cb, qos_profile=qos_profile_sensor_data)
        # Septentrio
        self.imu_sub = self.create_subscription(Imu, "/imu/data", self.imu_cb, qos_profile=qos_profile_sensor_data)
       
        # Fixposition
        # self.imu_sub = self.create_subscription(Imu, "/fixposition/rawimu", self.imu_cb, qos_profile=qos_profile_sensor_data)
        # self.imu_sub = self.create_subscription(Imu, "/fixposition/corrimu", self.imu_cb, qos_profile=qos_profile_sensor_data)
        self.odom_sub = self.create_subscription(Odometry, "/fixposition/odometry", self.odom_cb, qos_profile=qos_profile_sensor_data)
    
        self.wheel_sub = self.create_subscription(AckermannDriveStamped, "/drive_info_from_nucleo", self.wheel_cb, qos_profile=qos_profile_sensor_data)
        self.ekf_pub = self.create_publisher(PoseWithCovarianceStamped, "/gnss_ekf", 10)
        self.timer = self.create_timer(self.dt, self.ekf_update)

        self.last_yaw = None
        self.curr_w = None

        self.last_x = None
        self.last_y = None 
        self.last_x_covar = None
        self.last_y_covar = None
        self.curr_v = None
        self.wheel_v = None
        self.last_v = None
        self.X_est = None
        self.P_est = np.eye(5)
        self.initStatus_1 = False
        self.initStatus_2 = False

        # experiment: fixposition odometry orientation
        self.q = None

        self.msgLock = threading.Lock()

    def ecef_to_enu(self, ecef_x, ecef_y, ecef_z, origin_lat, origin_lon, origin_alt):
        # Convert degrees to radians
        lat_rad = np.radians(origin_lat)
        lon_rad = np.radians(origin_lon)

        # Calculate ECEF coordinates of the origin
        a = 6378137.0  # WGS84 major axis
        e_sq = 6.69437999014e-3  # WGS84 first eccentricity squared
        
        N = a / np.sqrt(1 - e_sq * np.sin(lat_rad)**2)
        
        ecef_origin_x = (N + origin_alt) * np.cos(lat_rad) * np.cos(lon_rad)
        ecef_origin_y = (N + origin_alt) * np.cos(lat_rad) * np.sin(lon_rad)
        ecef_origin_z = (N * (1 - e_sq) + origin_alt) * np.sin(lat_rad)

        # Calculate differences between the ECEF coordinates
        dx = ecef_x - ecef_origin_x
        dy = ecef_y - ecef_origin_y
        dz = ecef_z - ecef_origin_z

        # Define the rotation matrix
        R = np.array([
            [-np.sin(lon_rad), np.cos(lon_rad), 0],
            [-np.sin(lat_rad) * np.cos(lon_rad), -np.sin(lat_rad) * np.sin(lon_rad), np.cos(lat_rad)],
            [np.cos(lat_rad) * np.cos(lon_rad), np.cos(lat_rad) * np.sin(lon_rad), np.sin(lat_rad)]
        ])

        # Transform to ENU coordinates
        enu = R @ np.array([dx, dy, dz])
        return enu[0], enu[1], enu[2], R


    def rotate_orientation(self, orientation, rotation_matrix):
        # q1 = np.array([0.14103571, 0.         ,0.         ,0.99000451])
        # q2 = np.array([0.03126601215162431, 0.10960914117506113, -0.5226545962350743, 0.8448904184652299])
        # q1_inv = quaternion_inverse(q1)
        # q2_inv = quaternion_inverse(q2)
        # # Compute the relative rotation quaternion
        # rotation_quaternion = quaternion_multiply(q1, q2_inv)

        # example_quaternion = quaternion_multiply(rotation_quaternion, q2)

        # Convert rotation_matrix to 4x4 matrix
        rotation_matrix_4x4 = np.eye(4)
        rotation_matrix_4x4[:3, :3] = rotation_matrix

        # Convert rotation matrix to quaternion
        rotation_quaternion = quaternion_from_matrix(rotation_matrix_4x4)

        

        # apply the rotation to the orientation quaternion
        rotated_quaternion = quaternion_multiply(rotation_quaternion, [orientation.x, orientation.y, orientation.z, orientation.w])

        # rotated_quaternion = self.project_to_2d(rotated_quaternion)
        # rotation_quaternion_2d = quaternion_from_euler(0, 0, 1)
        # rotated_quaternion_2d = quaternion_multiply(rotation_quaternion_2d, rotated_quaternion)

        # print("original_quaternion: ", [orientation.w, orientation.x, orientation.y, orientation.z])
        # print("rotated_quaternion: ", rotated_quaternion)
        return rotated_quaternion
    
    def project_to_2d(self, quaternion):
        z = quaternion[3]
        w = np.sqrt(1 - z**2)
        return np.array([w, 0, 0, z])

    
    def odom_cb(self, msg: Odometry):
        # Extract ECEF coordinates from odometry message
        ecef_x = msg.pose.pose.position.x
        ecef_y = msg.pose.pose.position.y
        ecef_z = msg.pose.pose.position.z

        # Convert ECEF to local ENU coordinates
        local_x, local_y, local_z, rotation_matrix = self.ecef_to_enu(ecef_x, ecef_y, ecef_z, self.origin_lat, self.origin_lon, self.origin_alt)
        local_orientation = self.rotate_orientation(msg.pose.pose.orientation, rotation_matrix)


        self.last_x = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, local_x)
        self.last_y = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, local_y)

        self.last_x_covar = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, msg.pose.covariance[0])
        self.last_y_covar = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, msg.pose.covariance[4])

        if(msg.pose.covariance[0] > 0.0025 or msg.pose.covariance[4] > 0.0025):
            self.last_x_covar = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, 1e5*msg.pose.covariance[0])
            self.last_y_covar = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, 1e5*msg.pose.covariance[4])

        # Create a PoseWithCovarianceStamped message
        pose_cov_msg = PoseWithCovarianceStamped()

        # Set the header
        pose_cov_msg.header.frame_id = "map"
        pose_cov_msg.header.stamp.sec = self.last_x.sec
        pose_cov_msg.header.stamp.nanosec = self.last_x.nanosec

        # Set the pose in local frame
        pose_cov_msg.pose.pose.position.x = local_x
        pose_cov_msg.pose.pose.position.y = local_y
        pose_cov_msg.pose.pose.position.z = local_z
        pose_cov_msg.pose.pose.orientation.x = local_orientation[0]
        pose_cov_msg.pose.pose.orientation.y = local_orientation[1]
        pose_cov_msg.pose.pose.orientation.z = local_orientation[2]
        pose_cov_msg.pose.pose.orientation.w = local_orientation[3]
        # pose_cov_msg.pose.pose.orientation = msg.pose.pose.orientation

        # Set the covariance
        pose_cov_msg.pose.covariance = msg.pose.covariance

        # Publish the PoseWithCovarianceStamped message
        self.ekf_pub.publish(pose_cov_msg)


    # def imu_cb(self, msg: Imu):
    #     # calculate the current yaw from orientation quaternion
    #     q = msg.orientation
    #     q = np.array([q.w, q.x, q.y, q.z])
    #     euler = transforms3d.euler.quat2euler(q)
    #     yaw = euler[2]
    #     yaw_vel = msg.angular_velocity.z

    #     #get velocity from dt
    #     if(not self.initStatus_1):
    #         self.last_yaw = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, yaw)
    #         return
    #     dt = get_Time(msg.header.stamp.sec, msg.header.stamp.nanosec) - get_Time(self.last_yaw.sec, self.last_yaw.nanosec)
    #     v = msg.linear_acceleration.x*dt

    #     #instant info of YAW, ANGULAR VELO, and current YAW to be taken from the IMU
    #     self.last_yaw = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, yaw)
    #     self.curr_w = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, yaw_vel)
    #     self.curr_v = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, v)

    def wheel_cb(self, msg: AckermannDriveStamped):
        # calculate the current yaw from orientation quaternion
        speed = msg.drive.speed
        self.wheel_v = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, speed)

    # def gnss_cb(self, msg:PoseWithCovarianceStamped):
    #     # calculate the current x and y position from the gnss data
    #     x = msg.pose.pose.position.x
    #     y = msg.pose.pose.position.y
    #     #ONLY update position using GPS because thats what it is good at
    #     self.last_x = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, x)
    #     self.last_y = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, y)

    #     self.last_x_covar = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, msg.pose.covariance[0])
    #     self.last_y_covar = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, msg.pose.covariance[4])

    #     if(msg.pose.covariance[0] > 0.0025 or msg.pose.covariance[4] > 0.0025):
    #         self.last_x_covar = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, 1e5*msg.pose.covariance[0])
    #         self.last_y_covar = Stamped(msg.header.stamp.sec, msg.header.stamp.nanosec, 1e5*msg.pose.covariance[4])

    # def checkStatus(self):
        if self.last_yaw is not None and self.last_x is not None and self.last_y is not None:
            self.initStatus_1 = True
        
        if self.curr_v is not None and self.curr_w is not None and self.wheel_v is not None:
            self.initStatus_2 = True
            self.X_est = X(self.last_x.sec, self.last_x.nanosec, self.last_x.val, self.last_y.val, self.last_yaw.val, self.curr_v.val, self.curr_w.val)
            self.get_logger().info("EKF initialized")
    
    # def ekf_update(self):
    #     if(not self.initStatus_1 or not self.initStatus_2):
    #        self.checkStatus()
    #        return
        
    #     # get current time in sec and nanosec
    #     last_x_est_time = get_Time(self.X_est.sec, self.X_est.nanosec)
    #     curr_obs_time = get_Time(self.last_x.sec, self.last_x.nanosec)

    #     dt = curr_obs_time - last_x_est_time

    #     ud = np.array([[self.wheel_v.val], [self.curr_w.val]])
    #     x_est = np.array([[self.X_est.x], [self.X_est.y], [self.X_est.yaw], [self.X_est.v], [self.X_est.omega]])

    #     xEst, PEst = self.ekf.ekf_predict(x_est, self.P_est, ud, self.dt)

    #     #GNSS ONLY UPDATE
    #     z_b = np.array([True, True, False, False, False])
    #     z_covar = np.diag([self.last_x_covar.val, self.last_y_covar.val]) ** 2
    #     z = np.array([[self.last_x.val], [self.last_y.val]]) 
    #     xEst, PEst = self.ekf.ekf_partial_update(xEst, PEst, z, z_b ,z_covar)

    #     #IMU ONLY UPDATE
    #     z_b = np.array([False, False, True, False, False]) #yaw, velo, yawvelo
    #     z_covar = np.diag([1e-2]) ** 2
    #     z = np.array([[self.last_yaw.val]]) 
    #     xEst, PEst = self.ekf.ekf_partial_update(xEst, PEst, z, z_b ,z_covar)

    #     quat_to_pub = transforms3d.euler.euler2quat(0,0, xEst[2][0])

    #     #the time stamps are wrong here UPDATE IT TODO
    #     self.X_est = X(self.last_x.sec, self.last_x.nanosec, xEst[0][0], xEst[1][0], xEst[2][0], xEst[3][0], xEst[4][0])
    #     self.P_est = PEst
        
    #     # # publish the estimated position
    #     # msg = PoseWithCovarianceStamped()
    #     # msg.header.stamp.sec = self.last_x.sec
    #     # msg.header.stamp.nanosec = self.last_x.nanosec
    #     # msg.header.frame_id = "map"
    #     # msg.pose.pose.position.x = xEst[0][0]
    #     # msg.pose.pose.position.y = xEst[1][0]
    #     # msg.pose.pose.position.z = 0.0
    #     # msg.pose.pose.orientation.x = quat_to_pub[1]
    #     # msg.pose.pose.orientation.y = quat_to_pub[2]
    #     # msg.pose.pose.orientation.z = quat_to_pub[3]
    #     # msg.pose.pose.orientation.w = quat_to_pub[0]
    #     # msg.pose.covariance[0] = PEst[0][0] #x
    #     # msg.pose.covariance[7] = PEst[1][1] #y
    #     # msg.pose.covariance[35] = PEst[2][2] #yaw
    #     # self.ekf_pub.publish(msg)



def main(args=None):
    rclpy.init(args=args)
    node = Ekf_gnss_node()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()