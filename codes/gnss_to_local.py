import rclpy
from rclpy.node import Node

import numpy as np
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped, AckermannDrive

class ReactiveFollowGap(Node):
    def __init__(self):
        super().__init__('reactive_node')
        self.lidarscan_topic = '/scan'
        self.drive_topic = '/drive'
       
        # Subscribe to LIDAR
        self.subscription = self.create_subscription(
            LaserScan,
            self.lidarscan_topic,
            self.lidar_callback,
            10)
        self.subscription  # prevent unused variable warning

        # Publisher for driving the car
        self.publisher = self.create_publisher(
            AckermannDriveStamped,
            self.drive_topic,
            10)

    def preprocess_lidar(self, ranges):
        """ Preprocess the LiDAR scan array to focus only on the front 120 degrees. """
        ranges = np.array(ranges)
        # num_points = len(ranges)
        # front_angle_deg = 120  # front angle to consider
        # points_per_degree = num_points / 360  # points per degree calculation


        # # Calculate indices to slice the front 120 degrees
        # front_points = int(points_per_degree * front_angle_deg)
        # start_idx = num_points // 2 - front_points // 2
        # end_idx = num_points // 2 + front_points // 2

        # # Slice the front 120 degrees
        # front_ranges = ranges[start_idx:end_idx]
        total_angle = 120
        num_rays = len(ranges)
        start_index = int(num_rays/360*total_angle)
        end_index = int(num_rays/360*total_angle*2)
        front_ranges = ranges[start_index:end_index]
        front_ranges = front_ranges[::-1]
        # right_half = ranges[0:int(num_rays/360*total_angle/2)]
        # left_half = ranges[int(num_rays/360*(360-total_angle/2)):]
        # front_ranges = np.hstack((left_half,right_half))

        # print(int(num_rays/360*total_angle/2))
        # print(int(num_rays/360*(360-total_angle/2)))
        # print("left shape", np.shape(left_half))
        # print("right half", np.shape(right_half))
        # print("front ranges shape",np.shape(front_ranges))

        # Apply the same preprocessing: remove high values and smooth data
        front_ranges[front_ranges < 0.1] = 0

        return front_ranges

    # def find_max_gap(self, free_space_ranges):
    #     """ Return the start index & end index of the max gap in free_space_ranges """
    #     # Transform free space to gaps and find the longest one
    #     zero_index = np.where(free_space_ranges == 0)[0]

    #     if len(zero_index) == 0:
    #         return 0, len(free_space_ranges) - 1
    #     else:
            

    #         zero_index = np.insert(zero_index, 0, -1)
    #         zero_index = np.append(zero_index, len(free_space_ranges))
    #         gap_lengths = np.diff(zero_index) - 1
    #         max_gap_idx = np.argmax(gap_lengths)
    #         return zero_index[max_gap_idx] + 1, zero_index[max_gap_idx + 1] - 1
        
    def find_max_gap(self,data):
        max_length = 0
        current_length = 0
        start_index = 0
        max_start_index = -1
        max_end_index = -1

        # TODO: handle the case where all 0
        # if(np.all(data==0))

        for i, value in enumerate(data):
            if value != 0:
                if current_length == 0:
                    start_index = i  # Start of a new sequence
                current_length += 1
            else:
                if current_length > max_length:
                    max_length = current_length
                    max_start_index = start_index
                    max_end_index = i - 1
                current_length = 0  # Reset the current sequence length
        
        # Check last sequence in case the longest sequence ends at the last element
        if current_length > max_length:
            max_length = current_length
            max_start_index = start_index
            max_end_index = len(data) - 1

        return max_start_index, max_end_index

    def find_best_point(self, start_i, end_i, ranges):
        # TODO: handle the case where all 0
        # if(np.all(data==0))

        """ Return index of best point in ranges, naively choosing the furthest point """
        max_range_idx = np.argmax(ranges[start_i:end_i+1]) + start_i
        return max_range_idx

    def lidar_callback(self, data):
        ranges = data.ranges
        proc_ranges = self.preprocess_lidar(ranges)
        print(proc_ranges)
        bubble_degree = 5
        bubble_radius = int(5/360*len(proc_ranges)) # 5/360*1024

        zero_index = np.where(proc_ranges==0)[0]
        for index in zero_index:
            start = max(index - bubble_radius, 0)
            end = min(index+bubble_radius+1, len(proc_ranges))
            proc_ranges[start:end] = 0

        # # Find closest point to LiDAR
        # best_point = self.find_best_point(start_i, end_i, proc_ranges)
        # max_index = min(len(proc_ranges), closest_point + safety_bubble_radius)
        # proc_ranges[min_index:max_index] = 0

        # Find max length gap
        start_i, end_i = self.find_max_gap(proc_ranges)

        # Find the best point in the gap
        best_point = self.find_best_point(start_i, end_i, proc_ranges)
        print("Best_point: ",best_point)

        # # Correct the index offset caused by only processing a slice of the ranges
        # best_point += offset_idx

        # Publish Drive message
        drive_msg = AckermannDriveStamped()
        drive_msg.drive.speed = 0.5  # Set speedproc_ranges
        # Steering angle is computed relative to the center of the full 360 degrees
        drive_msg.drive.steering_angle = -0.005* (best_point - len(proc_ranges) / 2)  # Basic proportional controller
        self.publisher.publish(drive_msg)
        return None

def main(args=None):
    rclpy.init(args=args)
    reactive_node = ReactiveFollowGap()
    rclpy.spin(reactive_node)

    reactive_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()