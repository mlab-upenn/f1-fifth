import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
import subprocess
import cv2
import numpy as np
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import threading

class GoProFFmpegNode(Node):
    def __init__(self):
        super().__init__("gopro_ffmpeg_node")
        self.declare_parameter("stream_url", "udp://@0.0.0.0:8554?overrun_nonfatal=1&fifo_size=50000000")  # Default GoPro stream URL
        self.stream_url = self.get_parameter("stream_url").value

        # FFmpeg command
        self.ffmpeg_cmd = [
            "ffmpeg",
            "-fflags", "nobuffer",  # Low-latency flag
            "-i", self.stream_url,  # Input stream URL
            "-f", "rawvideo",      # Output format: raw video
            "-pix_fmt", "bgr24",   # Pixel format: BGR (OpenCV-compatible)
            "-"
        ]

        # Setup quos profile to keep up with the gopro images
        quos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1  # Adjust depth to buffer fewer frames to limit lag
        )

        self.bridge = CvBridge()
        self.publisher = self.create_publisher(Image, "/gopro/image_raw", quos_profile)

        self.process = None
        self.timer = self.create_timer(1/240.0, self.timer_callback)  # ~240 FPS

        # Start FFmpeg process
        self.start_ffmpeg()

    def start_ffmpeg(self):
        try:
            self.process = subprocess.Popen(
                self.ffmpeg_cmd,
                stdout=subprocess.PIPE,
                stderr=subprocess.DEVNULL,  # Suppress FFmpeg logs
                bufsize=2**8  # Large buffer size for FFmpeg output
            )
            self.get_logger().info("FFmpeg process started successfully")
        except Exception as e:
            self.get_logger().error(f"Failed to start FFmpeg process: {e}")

    def timer_callback(self):
        if not self.process:
            self.get_logger().warn("FFmpeg process not running")
            return

        # Read frame from FFmpeg output
        try:
            frame_size = 1920 * 1080 * 3  # Width * Height * Channels (3 for BGR)
            raw_frame = self.process.stdout.read(frame_size)
            if not raw_frame:
                self.get_logger().warn("No frame received from FFmpeg")
                return

            # Convert raw bytes to OpenCV image
            frame = np.frombuffer(raw_frame, dtype=np.uint8).reshape((1080, 1920, 3))  # Adjust resolution as needed
            msg = self.bridge.cv2_to_imgmsg(frame, encoding="bgr8")
            self.publisher.publish(msg)
        except Exception as e:
            self.get_logger().error(f"Error processing frame: {e}")

    def destroy_node(self):
        super().destroy_node()
        if self.process:
            self.process.terminate()
            self.process.wait()
            self.get_logger().info("FFmpeg process terminated")

def main(args=None):
    rclpy.init(args=args)
    node = GoProFFmpegNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
