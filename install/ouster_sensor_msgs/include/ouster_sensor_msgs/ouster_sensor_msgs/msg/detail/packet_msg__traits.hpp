// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ouster_sensor_msgs:msg/PacketMsg.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_SENSOR_MSGS__MSG__DETAIL__PACKET_MSG__TRAITS_HPP_
#define OUSTER_SENSOR_MSGS__MSG__DETAIL__PACKET_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ouster_sensor_msgs/msg/detail/packet_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ouster_sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PacketMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: buf
  {
    if (msg.buf.size() == 0) {
      out << "buf: []";
    } else {
      out << "buf: [";
      size_t pending_items = msg.buf.size();
      for (auto item : msg.buf) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const PacketMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: buf
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.buf.size() == 0) {
      out << "buf: []\n";
    } else {
      out << "buf:\n";
      for (auto item : msg.buf) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PacketMsg & msg, bool use_flow_style = false)
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

}  // namespace ouster_sensor_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ouster_sensor_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ouster_sensor_msgs::msg::PacketMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  ouster_sensor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ouster_sensor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ouster_sensor_msgs::msg::PacketMsg & msg)
{
  return ouster_sensor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ouster_sensor_msgs::msg::PacketMsg>()
{
  return "ouster_sensor_msgs::msg::PacketMsg";
}

template<>
inline const char * name<ouster_sensor_msgs::msg::PacketMsg>()
{
  return "ouster_sensor_msgs/msg/PacketMsg";
}

template<>
struct has_fixed_size<ouster_sensor_msgs::msg::PacketMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ouster_sensor_msgs::msg::PacketMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ouster_sensor_msgs::msg::PacketMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OUSTER_SENSOR_MSGS__MSG__DETAIL__PACKET_MSG__TRAITS_HPP_
