import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import serial

class WheelSpeedListener(Node):
    def __init__(self):
        super().__init__('wheel_speed_listener')

        # Publishers for each wheel
        self.publisher_FL = self.create_publisher(Float32, 'wheel_speed_FL', 10)
        self.publisher_FR = self.create_publisher(Float32, 'wheel_speed_FR', 10)
        self.publisher_RL = self.create_publisher(Float32, 'wheel_speed_RL', 10)
        self.publisher_RR = self.create_publisher(Float32, 'wheel_speed_RR', 10)

        # Set the serial port and baud rate
        self.serial_port = serial.Serial('/dev/sensors/arduino', 9600, timeout=1)

        self.timer = self.create_timer(0.1, self.read_serial_data)

    def read_serial_data(self):
        try:
            # Read a line from the serial port
            line = self.serial_port.readline().decode('utf-8').strip()
            
            # Parse the wheel speeds based on the line format
            if line:
                self.parse_wheel_speeds(line)

        except serial.SerialException as e:
            self.get_logger().error(f'Serial Exception: {str(e)}')

    def parse_wheel_speeds(self, line):
        # Split the line by colon and space
        if ':' in line:
            wheel, speed = line.split(':')
            wheel = wheel.strip()
            speed = float(speed.strip())

            # Publish the speed to the corresponding topic
            if wheel == 'FL':
                self.publisher_FL.publish(Float32(data=speed))
            elif wheel == 'FR':
                self.publisher_FR.publish(Float32(data=speed))
            elif wheel == 'RL':
                self.publisher_RL.publish(Float32(data=speed))
            elif wheel == 'RR':
                self.publisher_RR.publish(Float32(data=speed))
            else:
                self.get_logger().warn(f'Unknown wheel identifier: {wheel}')

def main(args=None):
    rclpy.init(args=args)
    node = WheelSpeedListener()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.serial_port.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
