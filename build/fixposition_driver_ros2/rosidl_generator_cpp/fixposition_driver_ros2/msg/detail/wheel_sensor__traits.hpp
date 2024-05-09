// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fixposition_driver_ros2:msg/WheelSensor.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__TRAITS_HPP_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fixposition_driver_ros2/msg/detail/wheel_sensor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace fixposition_driver_ros2
{

namespace msg
{

inline void to_flow_style_yaml(
  const WheelSensor & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: location
  {
    out << "location: ";
    rosidl_generator_traits::value_to_yaml(msg.location, out);
    out << ", ";
  }

  // member: vx
  {
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << ", ";
  }

  // member: vy
  {
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << ", ";
  }

  // member: vz
  {
    out << "vz: ";
    rosidl_generator_traits::value_to_yaml(msg.vz, out);
    out << ", ";
  }

  // member: vx_valid
  {
    out << "vx_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.vx_valid, out);
    out << ", ";
  }

  // member: vy_valid
  {
    out << "vy_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.vy_valid, out);
    out << ", ";
  }

  // member: vz_valid
  {
    out << "vz_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.vz_valid, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WheelSensor & msg,
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

  // member: location
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "location: ";
    rosidl_generator_traits::value_to_yaml(msg.location, out);
    out << "\n";
  }

  // member: vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << "\n";
  }

  // member: vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << "\n";
  }

  // member: vz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vz: ";
    rosidl_generator_traits::value_to_yaml(msg.vz, out);
    out << "\n";
  }

  // member: vx_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.vx_valid, out);
    out << "\n";
  }

  // member: vy_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vy_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.vy_valid, out);
    out << "\n";
  }

  // member: vz_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vz_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.vz_valid, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WheelSensor & msg, bool use_flow_style = false)
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
  const fixposition_driver_ros2::msg::WheelSensor & msg,
  std::ostream & out, size_t indentation = 0)
{
  fixposition_driver_ros2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fixposition_driver_ros2::msg::to_yaml() instead")]]
inline std::string to_yaml(const fixposition_driver_ros2::msg::WheelSensor & msg)
{
  return fixposition_driver_ros2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<fixposition_driver_ros2::msg::WheelSensor>()
{
  return "fixposition_driver_ros2::msg::WheelSensor";
}

template<>
inline const char * name<fixposition_driver_ros2::msg::WheelSensor>()
{
  return "fixposition_driver_ros2/msg/WheelSensor";
}

template<>
struct has_fixed_size<fixposition_driver_ros2::msg::WheelSensor>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fixposition_driver_ros2::msg::WheelSensor>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fixposition_driver_ros2::msg::WheelSensor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__TRAITS_HPP_
