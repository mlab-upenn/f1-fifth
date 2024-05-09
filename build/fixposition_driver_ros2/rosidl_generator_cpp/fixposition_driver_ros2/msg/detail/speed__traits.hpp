// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fixposition_driver_ros2:msg/Speed.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__SPEED__TRAITS_HPP_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__SPEED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fixposition_driver_ros2/msg/detail/speed__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'sensors'
#include "fixposition_driver_ros2/msg/detail/wheel_sensor__traits.hpp"

namespace fixposition_driver_ros2
{

namespace msg
{

inline void to_flow_style_yaml(
  const Speed & msg,
  std::ostream & out)
{
  out << "{";
  // member: sensors
  {
    if (msg.sensors.size() == 0) {
      out << "sensors: []";
    } else {
      out << "sensors: [";
      size_t pending_items = msg.sensors.size();
      for (auto item : msg.sensors) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Speed & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sensors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sensors.size() == 0) {
      out << "sensors: []\n";
    } else {
      out << "sensors:\n";
      for (auto item : msg.sensors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Speed & msg, bool use_flow_style = false)
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
  const fixposition_driver_ros2::msg::Speed & msg,
  std::ostream & out, size_t indentation = 0)
{
  fixposition_driver_ros2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fixposition_driver_ros2::msg::to_yaml() instead")]]
inline std::string to_yaml(const fixposition_driver_ros2::msg::Speed & msg)
{
  return fixposition_driver_ros2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<fixposition_driver_ros2::msg::Speed>()
{
  return "fixposition_driver_ros2::msg::Speed";
}

template<>
inline const char * name<fixposition_driver_ros2::msg::Speed>()
{
  return "fixposition_driver_ros2/msg/Speed";
}

template<>
struct has_fixed_size<fixposition_driver_ros2::msg::Speed>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fixposition_driver_ros2::msg::Speed>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fixposition_driver_ros2::msg::Speed>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__SPEED__TRAITS_HPP_
