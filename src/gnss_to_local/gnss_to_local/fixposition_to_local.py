import numpy as np
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseWithCovarianceStamped
import rclpy
from rclpy.node import Node

class FixpositionToLocal(Node):
    def __init__(self):
        super().__init__('fix_position_node')

        odom_topic = '/fixposition/odometry'
        posecovstmp_topic = 'gnss_to_local/local_position'

        self.odom_sub = self.create_subscription(Odometry, odom_topic, self.odom_cb, 10)
        self.ekf_pub = self.create_publisher(PoseWithCovarianceStamped, posecovstmp_topic, 10)



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
        return enu[0], enu[1], enu[2]
        
    def odom_cb(self, odom_msg: Odometry):
        # set the current orientation from the odometry data
        # q = msg.pose.pose.orientation
        # q = np.array([q.w, q.x, q.y, q.z])
        # self.q = q
        origin_lat = 39.9416
        origin_lon = -75.1993
        origin_alt = -27.19
        # Extract ECEF coordinates from odometry message
        ecef_x = odom_msg.pose.pose.position.x
        ecef_y = odom_msg.pose.pose.position.y
        ecef_z = odom_msg.pose.pose.position.z
        # Convert ECEF to local ENU coordinates
        local_x, local_y, local_z = self.ecef_to_enu(ecef_x, ecef_y, ecef_z, origin_lat, origin_lon, origin_alt)
        # self.last_x = Stamped(odom_msg.header.stamp.sec, odom_msg.header.stamp.nanosec, local_x)
        # self.last_y = Stamped(odom_msg.header.stamp.sec, odom_msg.header.stamp.nanosec, local_y)
        
        # Create a PoseWithCovarianceStamped message
        pose_cov_msg = PoseWithCovarianceStamped()
        # Set the header
        pose_cov_msg.header.frame_id = "map"
        # pose_cov_msg.header.stamp.sec = self.last_x.sec
        # pose_cov_msg.header.stamp.nanosec = self.last_x.nanosec
        pose_cov_msg.header.stamp.sec = odom_msg.header.stamp.sec
        pose_cov_msg.header.stamp.nanosec = odom_msg.header.stamp.nanosec
        # Set the pose in local frame
        pose_cov_msg.pose.pose.position.x = local_x
        pose_cov_msg.pose.pose.position.y = local_y
        pose_cov_msg.pose.pose.position.z = local_z
        pose_cov_msg.pose.pose.orientation = odom_msg.pose.pose.orientation
        print("local_x: ", local_x, ", local_y: ", local_y, " local_z: ", local_z)
        # Set the covariance
        pose_cov_msg.pose.covariance = odom_msg.pose.covariance
        # Publish the PoseWithCovarianceStamped message
        self.ekf_pub.publish(pose_cov_msg)


def main(args=None):
    rclpy.init(args=args)
    print("fixposition_to_local initialized")
    fixposition_to_local_node = FixpositionToLocal()
    rclpy.spin(fixposition_to_local_node)

    fixposition_to_local_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
