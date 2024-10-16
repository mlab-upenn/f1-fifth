import numpy as np
from collections import namedtuple
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseWithCovarianceStamped, TwistWithCovarianceStamped
import rclpy
from rclpy.node import Node
from tf_transformations import quaternion_matrix, quaternion_from_matrix, quaternion_multiply, quaternion_inverse, quaternion_from_euler

Stamped = namedtuple('Stamped', ['sec', 'nanosec', 'val'])

class FixpositionToLocal(Node):
    def __init__(self):
        super().__init__('fix_position_node')

        odom_topic = '/fixposition/odometry'
        posecovstmp_topic = '/gnss_to_local/local_position'

        self.odom_sub = self.create_subscription(Odometry, odom_topic, self.odom_cb, 10)
        self.ekf_pub = self.create_publisher(PoseWithCovarianceStamped, posecovstmp_topic, 10)
        self.odom_pub = self.create_publisher(Odometry, '/gnss_to_local/odometry', 10)

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
        # Convert rotation_matrix to 4x4 matrix
        rotation_matrix_4x4 = np.eye(4)
        rotation_matrix_4x4[:3, :3] = rotation_matrix

        # Convert rotation matrix to quaternion
        rotation_quaternion = quaternion_from_matrix(rotation_matrix_4x4)

        # apply the rotation to the orientation quaternion
        rotated_quaternion = quaternion_multiply(rotation_quaternion, [orientation.x, orientation.y, orientation.z, orientation.w])

        return rotated_quaternion

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
        print("local x: ", local_x, ", y: ", local_y, ", z: ", local_z)

        # Set the covariance
        pose_cov_msg.pose.covariance = msg.pose.covariance


        # Extract linear velocities (ECEF) from odometry message
        # ecef_vx = msg.twist.twist.linear.x
        # ecef_vy = msg.twist.twist.linear.y
        # ecef_vz = msg.twist.twist.linear.z
        
        # dont convert, will handle in inference node
        local_vx = msg.twist.twist.linear.x
        local_vy = msg.twist.twist.linear.y
        local_vz = msg.twist.twist.linear.z

        # Convert linear velocities (ECEF) to local ENU velocities
        # local_vx, local_vy, local_vz, local_rotation_matrix = self.ecef_to_enu(ecef_vx, ecef_vy, ecef_vz, self.origin_lat, self.origin_lon, self.origin_alt)

        # Extract angular velocities (assuming no need for conversion, depends on your setup)
        local_angular_vx = msg.twist.twist.angular.x
        local_angular_vy = msg.twist.twist.angular.y
        local_angular_vz = msg.twist.twist.angular.z

        # Create a TwistWithCovarianceStamped message
        twist_cov_msg = TwistWithCovarianceStamped()

        # Set the header
        twist_cov_msg.header.frame_id = "map"
        twist_cov_msg.header.stamp.sec = msg.header.stamp.sec
        twist_cov_msg.header.stamp.nanosec = msg.header.stamp.nanosec

        # Set the linear velocities in local frame (ENU)
        twist_cov_msg.twist.twist.linear.x = local_vx
        twist_cov_msg.twist.twist.linear.y = local_vy
        twist_cov_msg.twist.twist.linear.z = local_vz

        # Set the angular velocities (these might not need conversion)
        twist_cov_msg.twist.twist.angular.x = local_angular_vx
        twist_cov_msg.twist.twist.angular.y = local_angular_vy
        twist_cov_msg.twist.twist.angular.z = local_angular_vz
        twist_cov_msg.twist.twist.angular = msg.twist.twist.angular
        # Set the covariance (use original covariance from odometry)
        twist_cov_msg.twist.covariance = msg.twist.covariance

        # Publish the PoseWithCovarianceStamped message
        self.ekf_pub.publish(pose_cov_msg)

        odom_msg = Odometry()
        odom_msg.header = pose_cov_msg.header  
        odom_msg.pose = pose_cov_msg.pose
        odom_msg.twist = twist_cov_msg.twist
        self.odom_pub.publish(odom_msg)



def main(args=None):
    rclpy.init(args=args)
    print("fixposition_to_local initialized")
    fixposition_to_local_node = FixpositionToLocal()
    rclpy.spin(fixposition_to_local_node)

    fixposition_to_local_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()