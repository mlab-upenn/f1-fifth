// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ouster_msgs:msg/Metadata.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_MSGS__MSG__DETAIL__METADATA__TRAITS_HPP_
#define OUSTER_MSGS__MSG__DETAIL__METADATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ouster_msgs/msg/detail/metadata__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ouster_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Metadata & msg,
  std::ostream & out)
{
  out << "{";
  // member: hostname
  {
    out << "hostname: ";
    rosidl_generator_traits::value_to_yaml(msg.hostname, out);
    out << ", ";
  }

  // member: lidar_mode
  {
    out << "lidar_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.lidar_mode, out);
    out << ", ";
  }

  // member: timestamp_mode
  {
    out << "timestamp_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp_mode, out);
    out << ", ";
  }

  // member: beam_azimuth_angles
  {
    if (msg.beam_azimuth_angles.size() == 0) {
      out << "beam_azimuth_angles: []";
    } else {
      out << "beam_azimuth_angles: [";
      size_t pending_items = msg.beam_azimuth_angles.size();
      for (auto item : msg.beam_azimuth_angles) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: beam_altitude_angles
  {
    if (msg.beam_altitude_angles.size() == 0) {
      out << "beam_altitude_angles: []";
    } else {
      out << "beam_altitude_angles: [";
      size_t pending_items = msg.beam_altitude_angles.size();
      for (auto item : msg.beam_altitude_angles) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: imu_to_sensor_transform
  {
    if (msg.imu_to_sensor_transform.size() == 0) {
      out << "imu_to_sensor_transform: []";
    } else {
      out << "imu_to_sensor_transform: [";
      size_t pending_items = msg.imu_to_sensor_transform.size();
      for (auto item : msg.imu_to_sensor_transform) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: lidar_to_sensor_transform
  {
    if (msg.lidar_to_sensor_transform.size() == 0) {
      out << "lidar_to_sensor_transform: []";
    } else {
      out << "lidar_to_sensor_transform: [";
      size_t pending_items = msg.lidar_to_sensor_transform.size();
      for (auto item : msg.lidar_to_sensor_transform) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: serial_no
  {
    out << "serial_no: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_no, out);
    out << ", ";
  }

  // member: firmware_rev
  {
    out << "firmware_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.firmware_rev, out);
    out << ", ";
  }

  // member: imu_port
  {
    out << "imu_port: ";
    rosidl_generator_traits::value_to_yaml(msg.imu_port, out);
    out << ", ";
  }

  // member: lidar_port
  {
    out << "lidar_port: ";
    rosidl_generator_traits::value_to_yaml(msg.lidar_port, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Metadata & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: hostname
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hostname: ";
    rosidl_generator_traits::value_to_yaml(msg.hostname, out);
    out << "\n";
  }

  // member: lidar_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lidar_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.lidar_mode, out);
    out << "\n";
  }

  // member: timestamp_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp_mode, out);
    out << "\n";
  }

  // member: beam_azimuth_angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.beam_azimuth_angles.size() == 0) {
      out << "beam_azimuth_angles: []\n";
    } else {
      out << "beam_azimuth_angles:\n";
      for (auto item : msg.beam_azimuth_angles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: beam_altitude_angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.beam_altitude_angles.size() == 0) {
      out << "beam_altitude_angles: []\n";
    } else {
      out << "beam_altitude_angles:\n";
      for (auto item : msg.beam_altitude_angles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: imu_to_sensor_transform
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.imu_to_sensor_transform.size() == 0) {
      out << "imu_to_sensor_transform: []\n";
    } else {
      out << "imu_to_sensor_transform:\n";
      for (auto item : msg.imu_to_sensor_transform) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: lidar_to_sensor_transform
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.lidar_to_sensor_transform.size() == 0) {
      out << "lidar_to_sensor_transform: []\n";
    } else {
      out << "lidar_to_sensor_transform:\n";
      for (auto item : msg.lidar_to_sensor_transform) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: serial_no
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "serial_no: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_no, out);
    out << "\n";
  }

  // member: firmware_rev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "firmware_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.firmware_rev, out);
    out << "\n";
  }

  // member: imu_port
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imu_port: ";
    rosidl_generator_traits::value_to_yaml(msg.imu_port, out);
    out << "\n";
  }

  // member: lidar_port
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lidar_port: ";
    rosidl_generator_traits::value_to_yaml(msg.lidar_port, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Metadata & msg, bool use_flow_style = false)
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

}  // namespace ouster_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ouster_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ouster_msgs::msg::Metadata & msg,
  std::ostream & out, size_t indentation = 0)
{
  ouster_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ouster_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ouster_msgs::msg::Metadata & msg)
{
  return ouster_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ouster_msgs::msg::Metadata>()
{
  return "ouster_msgs::msg::Metadata";
}

template<>
inline const char * name<ouster_msgs::msg::Metadata>()
{
  return "ouster_msgs/msg/Metadata";
}

template<>
struct has_fixed_size<ouster_msgs::msg::Metadata>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ouster_msgs::msg::Metadata>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ouster_msgs::msg::Metadata>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OUSTER_MSGS__MSG__DETAIL__METADATA__TRAITS_HPP_
