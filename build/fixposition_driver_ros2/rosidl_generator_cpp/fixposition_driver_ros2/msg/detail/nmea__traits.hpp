// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fixposition_driver_ros2:msg/NMEA.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__TRAITS_HPP_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fixposition_driver_ros2/msg/detail/nmea__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace fixposition_driver_ros2
{

namespace msg
{

inline void to_flow_style_yaml(
  const NMEA & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: latitude
  {
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << ", ";
  }

  // member: longitude
  {
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << ", ";
  }

  // member: altitude
  {
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: course
  {
    out << "course: ";
    rosidl_generator_traits::value_to_yaml(msg.course, out);
    out << ", ";
  }

  // member: position_covariance
  {
    if (msg.position_covariance.size() == 0) {
      out << "position_covariance: []";
    } else {
      out << "position_covariance: [";
      size_t pending_items = msg.position_covariance.size();
      for (auto item : msg.position_covariance) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: position_covariance_type
  {
    out << "position_covariance_type: ";
    rosidl_generator_traits::value_to_yaml(msg.position_covariance_type, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NMEA & msg,
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

  // member: latitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << "\n";
  }

  // member: longitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << "\n";
  }

  // member: altitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: course
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "course: ";
    rosidl_generator_traits::value_to_yaml(msg.course, out);
    out << "\n";
  }

  // member: position_covariance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position_covariance.size() == 0) {
      out << "position_covariance: []\n";
    } else {
      out << "position_covariance:\n";
      for (auto item : msg.position_covariance) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: position_covariance_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_covariance_type: ";
    rosidl_generator_traits::value_to_yaml(msg.position_covariance_type, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NMEA & msg, bool use_flow_style = false)
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
  const fixposition_driver_ros2::msg::NMEA & msg,
  std::ostream & out, size_t indentation = 0)
{
  fixposition_driver_ros2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fixposition_driver_ros2::msg::to_yaml() instead")]]
inline std::string to_yaml(const fixposition_driver_ros2::msg::NMEA & msg)
{
  return fixposition_driver_ros2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<fixposition_driver_ros2::msg::NMEA>()
{
  return "fixposition_driver_ros2::msg::NMEA";
}

template<>
inline const char * name<fixposition_driver_ros2::msg::NMEA>()
{
  return "fixposition_driver_ros2/msg/NMEA";
}

template<>
struct has_fixed_size<fixposition_driver_ros2::msg::NMEA>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fixposition_driver_ros2::msg::NMEA>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fixposition_driver_ros2::msg::NMEA>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__TRAITS_HPP_
