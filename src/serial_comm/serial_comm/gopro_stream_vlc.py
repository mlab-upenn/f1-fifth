import rclpy
from rclpy.node import Node
import subprocess
import cv2
import numpy as np
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import codecs

class GoProVLCStreamNode(Node):
    def __init__(self):
        super().__init__('gopro_vlc_stream_node')

        # Declare and get parameters for VLC command and ROS image topic
        self.declare_parameter('vlc_command', 'cvlc udp://@:8554 --no-audio --sout "#transcode{vcodec=RV24}:duplicate{dst=standard{access=file,mux=raw,dst=-}}"')
        # self.declare_parameter('vlc_command', 'udp://@:8554')
        self.declare_parameter('image_topic', '/gopro/image_raw')

        # Get VLC command and image topic from parameters
        self.vlc_command = self.get_parameter('vlc_command').get_parameter_value().string_value
        self.image_topic = self.get_parameter('image_topic').get_parameter_value().string_value

        # Start VLC subprocess with the command, piping the output to stdout
        self.vlc_process = subprocess.Popen(self.vlc_command, shell=True, stdout=subprocess.PIPE, bufsize=10**8)

        # Initialize CvBridge to convert OpenCV images to ROS Image messages
        self.bridge = CvBridge()

        # Create a ROS publisher to publish images
        self.image_publisher = self.create_publisher(Image, self.image_topic, 10)

        # Create a timer to continuously capture and publish images
        # self.timer = self.create_timer(0.1, self.capture_and_publish)
        self.get_logger().info(f'Started VLC streaming with command: {self.vlc_command}, publishing on {self.image_topic}')
        try:
            with open("raw_image_hex.txt", 'w+') as file:
                file.write(str(codecs.encode(self.vlc_process.stdout.read(640 * 480 * 3 * 1.5), "hex")))
        except Exception as e:
            print(e)
            self.stop_vlc_process()

        
    def capture_and_publish(self):
        try:
            # Define the size of the frame (assume 640x480 resolution and 3 channels for BGR)
            frame_size = 640 * 480 * 3 # 640x480 resolution, 3 channels (BGR)

            raw_frame = self.vlc_process.stdout.read(frame_size)

            # with open("raw_frame.txt", 'r+') as f:
            #     f.write(self.vlc_process.stdout.read(frame_size * 2))
            
            if len(raw_frame) == frame_size:
                # Convert the raw frame to a numpy array
                frame = np.frombuffer(raw_frame, dtype=np.uint8).reshape((480, 640, 3))

                # Convert the frame (OpenCV format) to a ROS Image message
                ros_image = self.bridge.cv2_to_imgmsg(frame, encoding="bgr8")

                # Publish the ROS Image message
                self.image_publisher.publish(ros_image)
                self.get_logger().info('Published a new frame')
            else:
                self.get_logger().warn('No frame captured')
        except KeyboardInterrupt:
            self.destroy_node()

    def stop_vlc_process(self):
        # Stop the VLC process when the node is shutting down
        if self.vlc_process and self.vlc_process.poll() is None:
            self.get_logger().info("Stopping VLC process")
            self.vlc_process.terminate()
            try:
                self.vlc_process.wait(timeout=5)
            except subprocess.TimeoutExpired:
                self.get_logger().warn("Force killing VLC process")
                self.vlc_process.kill()

    def destroy_node(self):
        self.stop_vlc_process()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = GoProVLCStreamNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
