// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fixposition_driver_ros2:msg/VRTK.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__VRTK__TRAITS_HPP_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__VRTK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fixposition_driver_ros2/msg/detail/vrtk__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_with_covariance__traits.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist_with_covariance__traits.hpp"
// Member 'acceleration'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace fixposition_driver_ros2
{

namespace msg
{

inline void to_flow_style_yaml(
  const VRTK & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: pose_frame
  {
    out << "pose_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_frame, out);
    out << ", ";
  }

  // member: kin_frame
  {
    out << "kin_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.kin_frame, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: acceleration
  {
    out << "acceleration: ";
    to_flow_style_yaml(msg.acceleration, out);
    out << ", ";
  }

  // member: fusion_status
  {
    out << "fusion_status: ";
    rosidl_generator_traits::value_to_yaml(msg.fusion_status, out);
    out << ", ";
  }

  // member: imu_bias_status
  {
    out << "imu_bias_status: ";
    rosidl_generator_traits::value_to_yaml(msg.imu_bias_status, out);
    out << ", ";
  }

  // member: gnss1_status
  {
    out << "gnss1_status: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss1_status, out);
    out << ", ";
  }

  // member: gnss2_status
  {
    out << "gnss2_status: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss2_status, out);
    out << ", ";
  }

  // member: wheelspeed_status
  {
    out << "wheelspeed_status: ";
    rosidl_generator_traits::value_to_yaml(msg.wheelspeed_status, out);
    out << ", ";
  }

  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VRTK & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: pose_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_frame, out);
    out << "\n";
  }

  // member: kin_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kin_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.kin_frame, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }

  // member: acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceleration:\n";
    to_block_style_yaml(msg.acceleration, out, indentation + 2);
  }

  // member: fusion_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fusion_status: ";
    rosidl_generator_traits::value_to_yaml(msg.fusion_status, out);
    out << "\n";
  }

  // member: imu_bias_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imu_bias_status: ";
    rosidl_generator_traits::value_to_yaml(msg.imu_bias_status, out);
    out << "\n";
  }

  // member: gnss1_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss1_status: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss1_status, out);
    out << "\n";
  }

  // member: gnss2_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss2_status: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss2_status, out);
    out << "\n";
  }

  // member: wheelspeed_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wheelspeed_status: ";
    rosidl_generator_traits::value_to_yaml(msg.wheelspeed_status, out);
    out << "\n";
  }

  // member: version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VRTK & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace fixposition_driver_ros2

namespace rosidl_generator_traits
{

[[deprecated("use fixposition_driver_ros2::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fixposition_driver_ros2::msg::VRTK & msg,
  std::ostream & out, size_t indentation = 0)
{
  fixposition_driver_ros2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fixposition_driver_ros2::msg::to_yaml() instead")]]
inline std::string to_yaml(const fixposition_driver_ros2::msg::VRTK & msg)
{
  return fixposition_driver_ros2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<fixposition_driver_ros2::msg::VRTK>()
{
  return "fixposition_driver_ros2::msg::VRTK";
}

template<>
inline const char * name<fixposition_driver_ros2::msg::VRTK>()
{
  return "fixposition_driver_ros2/msg/VRTK";
}

template<>
struct has_fixed_size<fixposition_driver_ros2::msg::VRTK>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fixposition_driver_ros2::msg::VRTK>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fixposition_driver_ros2::msg::VRTK>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__VRTK__TRAITS_HPP_
