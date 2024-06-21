#include <Eigen/Dense>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "visualization_msgs/msg/marker.hpp"


using namespace rclcpp;
using namespace std;
using Eigen::Vector2d;
using namespace ackermann_msgs::msg;
using namespace geometry_msgs::msg;
using namespace visualization_msgs::msg;
using visualization_msgs::msg::Marker; 
using visualization_msgs::msg::MarkerArray; 
using nav_msgs::msg::Odometry;

struct Waypoint {
    Eigen::Vector2d position;
    double velocity;
    double yaw;

    Waypoint(double x, double y, double v, double yaw) : position(x, y), velocity(v), yaw(yaw) {}
};

class PurePursuit : public rclcpp::Node
{
    // Implement PurePursuit
    // This is just a template, you are free to implement your own node!

private:
    bool is_real;
    bool is_ascending;
    string map_name;
    double L;
    double steering_gain;
    vector<Waypoint> waypoints;
    rclcpp::Publisher<AckermannDriveStamped>::SharedPtr pub_drive;
    rclcpp::Publisher<MarkerArray>::SharedPtr pub_vis;
    rclcpp::Subscription<PoseStamped>::SharedPtr sub_pose;
    rclcpp::Subscription<Odometry>::SharedPtr sub_odom;
    MarkerArray markerArray;
    double vMax = std::numeric_limits<double>::lowest(); // Max velocity among waypoints
    double vMin = std::numeric_limits<double>::max(); // Min velocity among waypoints
    // double currX, currY;
    Vector2d currPos; // Using Eigen for 2D vector operations
    vector<double> distances; // Distances to all waypoints
    int closest_index; // Index of the closest waypoint
    Vector2d closestPoint; // Position of the closest waypoint
    Eigen::Matrix3d rotation_matrix;
    Marker waypointMarker;
    Marker targetMarker;
    Marker closestMarker;

    void calculateClosestWaypoint() {
        double minDistance = std::numeric_limits<double>::max();
        int closestIndex = -1;
        std::vector<double> distances;

        for (size_t i = 0; i < waypoints.size(); ++i) {
            double distance = (waypoints[i].position - currPos).norm(); // Euclidean distance
            distances.push_back(distance);
            
            if (distance < minDistance) {
                minDistance = distance;
                closestIndex = i;
            }
        }
        // closestIndex now holds the index of the closest waypoint
        
        Eigen::Vector2d closestPoint = waypoints[closestIndex].position;
        
        

        // Update class members accordingly
        this->distances = distances;
        this->closest_index = closestIndex;
        this->closestPoint = closestPoint;
        
    }

    Waypoint getClosestPointBeyondLookaheadDist(double threshold) {
        int pointIndex = closest_index;
        double distance = distances[pointIndex];
        
        while (distance < threshold) {
            if (is_ascending) {
                pointIndex += 1;
                if (pointIndex >= waypoints.size()) {
                    pointIndex = 0; // Loop back to the beginning if we go past the end
                }
            } else {
                pointIndex -= 1;
                if (pointIndex < 0) {
                    pointIndex = waypoints.size() - 1; // Loop back to the end if we go before the first waypoint
                }
            }
            distance = distances[pointIndex];
        }
        // At this point, pointIndex is the index of the waypoint beyond the lookahead distance
        return waypoints[pointIndex];
    }

    
    void visualization_init() {

        // Setup waypoint marker (Green Points)
        waypointMarker.header.frame_id = "map";
        waypointMarker.ns = "waypoints";
        waypointMarker.id = 0;
        waypointMarker.type = visualization_msgs::msg::Marker::POINTS;
        // waypointMarker.action = visualization_msgs::msg::Marker::ADD;
        waypointMarker.scale.x = 0.05;
        waypointMarker.scale.y = 0.05;
        waypointMarker.color.r = 1.0;
        waypointMarker.color.a = 1.0;

        for (const auto& wpt : waypoints) {
            geometry_msgs::msg::Point point;
            point.x = wpt.position.x();
            point.y = wpt.position.y();
            point.z = 0.0;
            // printf("point x: %f, point y: %f\n", point.x, point.y);
            waypointMarker.points.push_back(point);
        }

        // Setup target marker (Green Sphere)
        targetMarker.header.frame_id = "map";
        targetMarker.ns = "target_point";
        targetMarker.id = 1;
        targetMarker.type = visualization_msgs::msg::Marker::POINTS;
        // targetMarker.action = visualization_msgs::msg::Marker::ADD;
        targetMarker.scale.x = 0.2;
        targetMarker.scale.y = 0.2;
        targetMarker.scale.z = 0.2;
        targetMarker.color.g = 1.0;
        targetMarker.color.a = 1.0;

        // Setup closest marker (Blue Sphere)
        closestMarker.header.frame_id = "map";
        closestMarker.ns = "closest_point";
        closestMarker.id = 2;
        closestMarker.type = visualization_msgs::msg::Marker::POINTS;
        // closestMarker.action = visualization_msgs::msg::Marker::ADD;
        closestMarker.scale.x = 0.2;
        closestMarker.scale.y = 0.2;
        closestMarker.scale.z = 0.2;
        closestMarker.color.b = 1.0;
        closestMarker.color.a = 1.0;

        markerArray.markers.push_back(waypointMarker);
        pub_vis->publish(markerArray);

    }
    


    Eigen::Vector4d translatePoint(const Eigen::Vector2d& targetPoint) {

        Eigen::Vector2d adjustedTargetPoint = targetPoint - currPos;

        // std::cout << "Adjusted Target Point: " << adjustedTargetPoint.transpose() << std::endl;

        // Homogeneous transformation matrix
        Eigen::Matrix4d H = Eigen::Matrix4d::Zero();
        H.block<3, 3>(0, 0) = rotation_matrix.inverse(); 
        H(0, 3) = -currPos.x() * rotation_matrix.inverse()(0, 0) - currPos.y() * rotation_matrix.inverse()(1, 0); // Adjusted
        H(1, 3) = -currPos.x() * rotation_matrix.inverse()(0, 1) - currPos.y() * rotation_matrix.inverse()(1, 1); // Adjusted
        H(2, 2) = 1.0;
        H(3, 3) = 1.0;



        // Creating a 4D vector for the adjusted target point in homogeneous coordinates
        Eigen::Vector4d adjustedTargetPointHomogeneous(adjustedTargetPoint.x(), adjustedTargetPoint.y(), 0.0, 0.0);

        // Performing the transformation
        Eigen::Vector4d translatedTargetPoint = H * adjustedTargetPointHomogeneous;

        // std::cout << "Translated Target Point: " << translatedTargetPoint.transpose() << std::endl;

        return translatedTargetPoint;
    }

    template<typename T>
    T clamp(const T& val, const T& min, const T& max) {
        return (val < min) ? min : (val > max) ? max : val;
    }


    // void loadCsvData(const std::string& filepath) {
    //     // printf("here\n");
    //     std::ifstream file(filepath);
    //     std::string line;

    //     if (!file.is_open()) {
    //         std::cerr << "Failed to open file: " << filepath << std::endl;
    //         return; // Exit the function if file could not be opened
    //     }

    //     printf("File opened successfully.\n");

    //     // Skip the first row if it contains headers
    //     std::getline(file, line);

    //     while (std::getline(file, line)) {
    //         std::istringstream ss(line);
    //         std::string cell;

    //         std::vector<std::string> row;
    //         while (std::getline(ss, cell, ',')) {
    //             row.push_back(cell);
    //         }

    //         // Adjusted for a CSV with exactly 2 columns
    //         if (row.size() == 2) {
    //             double x = std::stod(row[0]); // Corrected index
    //             double y = std::stod(row[1]); // Corrected index
    //             waypoints.push_back(Eigen::Vector2d(x, y));
    //         }
    //     }
    // }

    void loadCsvData(const std::string& filepath) {
        std::ifstream file(filepath);
        std::string line;

        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filepath << std::endl;
            return;
        }

        std::cout << "File opened successfully.\n";

        // Skip the header row
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string cell;

            std::vector<std::string> row;
            while (std::getline(ss, cell, ',')) {
                row.push_back(cell);
            }

            // Ensure the row has exactly 4 columns
            if (row.size() == 4) {
                double x = std::stod(row[0]);
                double y = std::stod(row[1]);
                double v = std::stod(row[2]);
                double yaw = std::stod(row[3]);

                waypoints.push_back(Waypoint(x, y, v, yaw));

                // Update the max and min velocities
                if (v > vMax) vMax = v;
                if (v < vMin) vMin = v;
            }
        }

        std::cout << "Loaded " << waypoints.size() << " waypoints.\n";
        std::cout << "Maximum velocity: " << vMax << ", Minimum velocity: " << vMin << std::endl;
    }


    void pose_callback(geometry_msgs::msg::Quaternion quat)
    {
        // Convert tf2 quaternion to Eigen Quaternion
        Eigen::Quaterniond eigen_quat(quat.w, quat.x, quat.y, quat.z);

        // Convert Eigen Quaternion to rotation matrix
        rotation_matrix = eigen_quat.toRotationMatrix();
        

        // TODO: find the current waypoint to track using methods mentioned in lecture
        calculateClosestWaypoint();
        Waypoint closestWaypoint = waypoints[closest_index];

        // TODO: transform goal point to vehicle frame of reference
        
        Waypoint target_waypoint = getClosestPointBeyondLookaheadDist(L);
        Eigen::Vector2d targetPoint = target_waypoint.position;
        

        Eigen::Vector4d translated_target_pt = translatePoint(targetPoint);
        // std::cout << "Translated Target Point: " << translated_target_pt.transpose() << std::endl;

        // TODO: calculate curvature/steering angle
        double y = translated_target_pt[1];
        // printf("y: %f\n", y);
        double gamma = steering_gain * (2 * y / (L * L));

        // Limiting the steering angle to within [-0.35, 0.35] radians
        // gamma = clamp(gamma, -0.35, 0.35);

        // TODO: publish drive message, don't forget to limit the steering angle.
        AckermannDriveStamped drive_msg;
        drive_msg.drive.steering_angle = gamma;
        drive_msg.drive.speed = closestWaypoint.velocity; // Example fixed speed, adjust as necessary
        // printf("drive_msg.drive.steering_angle= %f\n", gamma);
        // Publishing the drive message
        
        pub_drive->publish(drive_msg);
        
        

        // Printing the steering angle and speed
        // std::cout << "steering = " << gamma << ", speed = " << drive_msg.drive.speed << std::endl;
        markerArray.markers.clear();

        Point target_marker_point;
        target_marker_point.x = targetPoint.x();
        target_marker_point.y = targetPoint.y();
        // printf("target point x: %f y: %f\n", target_marker_point.x, target_marker_point.y);
        target_marker_point.z = 0.0;
        targetMarker.points.push_back(target_marker_point);

        Point closest_marker_point;
        closest_marker_point.x = closestPoint.x();
        closest_marker_point.y = closestPoint.y();
        // printf("Closest point x: %f y: %f\n", closest_marker_point.x, closest_marker_point.y);
        closest_marker_point.z = 0.0;
        closestMarker.points.push_back(closest_marker_point);

        

        markerArray.markers.push_back(waypointMarker);
        markerArray.markers.push_back(targetMarker);
        markerArray.markers.push_back(closestMarker);

        pub_vis->publish(markerArray);
        // printf("published markers\n");
        
    }


    void odom_pose_callback(const std::shared_ptr<Odometry> pose_msg)
    {
        

        currPos.x() =  pose_msg->pose.pose.position.x;
        currPos.y() =  pose_msg->pose.pose.position.y;

        // Transform quaternion pose message to rotation matrix
        geometry_msgs::msg::Quaternion quat = pose_msg->pose.pose.orientation;

        pose_callback(quat);
        
    }

    void pose_stmp_callback(const std::shared_ptr<PoseStamped> pose_msg)
    {

        currPos.x() = pose_msg->pose.position.x; 
        currPos.y() = pose_msg->pose.position.y; 

        geometry_msgs::msg::Quaternion quat = pose_msg->pose.orientation; 
        
        pose_callback(quat);
    }

    void printWaypoints(const std::vector<Eigen::Vector2d>& waypoints) {
        std::cout << "Waypoints:" << std::endl;
        for (size_t i = 0; i < waypoints.size(); ++i) {
            // Accessing each waypoint's x and y components
            double x = waypoints[i].x() ; // x component
            double y = waypoints[i].y() ; // y component

            // Print the current waypoint
            std::cout << "Waypoint " << i << ": (" << x << ", " << y << ")" << std::endl;
        }
    }


public:
    PurePursuit() : Node("pure_pursuit_node")
    {
        // ROS parameters
        is_real = false;
        is_ascending = true;  // waypoint indices are ascending during tracking
        string csv_name = "waypoints";
        L = 1.0;  // Lookahead distance
        steering_gain = 0.5;

        // Topics
        string drive_topic = "/drive";
        string odom_topic = is_real ? "/pf/viz/inferred_pose" : "/ego_racecar/odom";
        string visualization_topic = "/visualization_marker_array";

        pub_drive = this->create_publisher<AckermannDriveStamped>(drive_topic, 1);


        rclcpp::QoS custom_qos_profile(10); // 10 is the history depth
        custom_qos_profile.transient_local(); // Setting the durability to TRANSIENT_LOCAL
        custom_qos_profile.reliable(); // Setting the reliability to RELIABLE (optional)

        pub_vis = this->create_publisher<MarkerArray>(visualization_topic, custom_qos_profile);

        // Load waypoints from CSV || Update youre absolute path
        std::string csv_path = "/home/lee/work/f1/sim_ws/src/lab-5-slam-and-pure-pursuit-team-6/pure_pursuit/waypoints/" + csv_name + ".csv"; 
        loadCsvData(csv_path);

        // printWaypoints(waypoints);
        // Subscribers and Publishers
        if (is_real) {
            sub_pose = this->create_subscription<PoseStamped>(
                odom_topic, 
                1, 
                std::bind(&PurePursuit::pose_stmp_callback, this, std::placeholders::_1));
        } else {
            sub_odom = this->create_subscription<Odometry>(
                odom_topic, 
                1, 
                std::bind(&PurePursuit::odom_pose_callback, this, std::placeholders::_1));
        }

        visualization_init();
    }

    
    ~PurePursuit() {}
};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PurePursuit>());
    rclcpp::shutdown();
    return 0;
}