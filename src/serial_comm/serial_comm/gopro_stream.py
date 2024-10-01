import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
import subprocess
import cv2
import numpy as np
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import threading

class GoProVLCStreamNode(Node):
    def __init__(self):
        super().__init__('gopro_vlc_stream_node')

        # Declare and get parameters for VLC command and ROS image topic
        # self.declare_parameter('vlc_command', 'cvlc udp://@:8554 --no-audio --sout "#transcode{vcodec=RV24}:duplicate{dst=standard{access=file,mux=raw,dst=-}}"')
        # self.declare_parameter('vlc_command', 'udp://@:8554')
        self.declare_parameter('image_topic', '/gopro/image_raw')
        self.declare_parameter('FPS', 100)

        # Get VLC command and image topic from parameters
        # self.vlc_command = self.get_parameter('vlc_command').get_parameter_value().string_value
        self.image_topic = self.get_parameter('image_topic').get_parameter_value().string_value

        # Start VLC subprocess with the command, piping the output to stdout
        # self.vlc_process = subprocess.Popen(self.vlc_command, shell=True, stdout=subprocess.PIPE, bufsize=10**6)

        # Initialize CvBridge to convert OpenCV images to ROS Image messages
        self.bridge = CvBridge()

        # Setup quos profile to keep up with the gopro images
        quos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1  # Adjust depth to buffer fewer frames to limit lag
        )



        # Create a ROS publisher to publish images
        self.image_publisher = self.create_publisher(Image, self.image_topic,  quos_profile)

        self.cap = cv2.VideoCapture('udp://@:8554', cv2.CAP_ANY)
        self.cap.set(cv2.CAP_PROP_BUFFERSIZE, 1)  # This doesn't work yet for FFMPEG
        print(self.cap.getBackendName())

        # We create a reader which just grabs frames continuously
        # Grab is fast and does not actually get the frames, it just reserves them
        # Then on the timer, we just retrieve the frames we want to publish.
        self.cap_lock = threading.Lock()
        self.reading_thread = threading.Thread(target=self._live_reader)
        self.reading_thread.daemon = True
        self.reading_thread.start()

        self.FPS = self.get_parameter('FPS').get_parameter_value().integer_value
        # Create a timer to continuously retrieve and publish images
        self.timer = self.create_timer(1/self.FPS, self.capture_and_publish)
        # self.get_logger().info(f'Started VLC streaming with command: {self.vlc_command}, publishing on {self.image_topic}')


    def _live_reader(self):
        while True:
            with self.cap_lock:
                ret = self.cap.grab()
            if not ret:
                break

    def capture_and_publish(self):
        # Define the size of the frame (assume 640x480 resolution and 3 channels for BGR)
        # frame_size = 640 * 480 * 3  # 640x480 resolution, 3 channels (BGR)

        # raw_frame = self.vlc_process.stdout.read(frame_size)

        # with open("raw_img.txt") as file:
            # file.write(raw_frame)

        # if len(raw_frame) == frame_size:
        #     # Convert the raw frame to a numpy array
        #     frame = np.frombuffer(raw_frame, dtype=np.uint8).reshape((480, 640, 3))

        #     # Convert the frame (OpenCV format) to a ROS Image message
        #     ros_image = self.bridge.cv2_to_imgmsg(frame, encoding="bgr8")

        #     # Publish the ROS Image message
        #     self.image_publisher.publish(ros_image)
        #     self.get_logger().info('Published a new frame')
        # else:
        #     self.get_logger().warn('No frame captured')

        with self.cap_lock:
            ret, frame = self.cap.retrieve()
        if not ret:
            self.get_logger().warn("No Frame Captured")
        else:
            ros_image = self.bridge.cv2_to_imgmsg(frame)
            self.image_publisher.publish(ros_image)
            self.get_logger().info("Published a new frame") 


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
        self.cap.release()
        # self.stop_vlc_process()
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
