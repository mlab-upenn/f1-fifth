// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ouster_sensor_msgs:srv/GetConfig.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_SENSOR_MSGS__SRV__DETAIL__GET_CONFIG__TRAITS_HPP_
#define OUSTER_SENSOR_MSGS__SRV__DETAIL__GET_CONFIG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ouster_sensor_msgs/srv/detail/get_config__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ouster_sensor_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetConfig_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetConfig_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetConfig_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ouster_sensor_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ouster_sensor_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ouster_sensor_msgs::srv::GetConfig_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ouster_sensor_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ouster_sensor_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const ouster_sensor_msgs::srv::GetConfig_Request & msg)
{
  return ouster_sensor_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ouster_sensor_msgs::srv::GetConfig_Request>()
{
  return "ouster_sensor_msgs::srv::GetConfig_Request";
}

template<>
inline const char * name<ouster_sensor_msgs::srv::GetConfig_Request>()
{
  return "ouster_sensor_msgs/srv/GetConfig_Request";
}

template<>
struct has_fixed_size<ouster_sensor_msgs::srv::GetConfig_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ouster_sensor_msgs::srv::GetConfig_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ouster_sensor_msgs::srv::GetConfig_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ouster_sensor_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetConfig_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: config
  {
    out << "config: ";
    rosidl_generator_traits::value_to_yaml(msg.config, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetConfig_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: config
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "config: ";
    rosidl_generator_traits::value_to_yaml(msg.config, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetConfig_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ouster_sensor_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ouster_sensor_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ouster_sensor_msgs::srv::GetConfig_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ouster_sensor_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ouster_sensor_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const ouster_sensor_msgs::srv::GetConfig_Response & msg)
{
  return ouster_sensor_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ouster_sensor_msgs::srv::GetConfig_Response>()
{
  return "ouster_sensor_msgs::srv::GetConfig_Response";
}

template<>
inline const char * name<ouster_sensor_msgs::srv::GetConfig_Response>()
{
  return "ouster_sensor_msgs/srv/GetConfig_Response";
}

template<>
struct has_fixed_size<ouster_sensor_msgs::srv::GetConfig_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ouster_sensor_msgs::srv::GetConfig_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ouster_sensor_msgs::srv::GetConfig_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ouster_sensor_msgs::srv::GetConfig>()
{
  return "ouster_sensor_msgs::srv::GetConfig";
}

template<>
inline const char * name<ouster_sensor_msgs::srv::GetConfig>()
{
  return "ouster_sensor_msgs/srv/GetConfig";
}

template<>
struct has_fixed_size<ouster_sensor_msgs::srv::GetConfig>
  : std::integral_constant<
    bool,
    has_fixed_size<ouster_sensor_msgs::srv::GetConfig_Request>::value &&
    has_fixed_size<ouster_sensor_msgs::srv::GetConfig_Response>::value
  >
{
};

template<>
struct has_bounded_size<ouster_sensor_msgs::srv::GetConfig>
  : std::integral_constant<
    bool,
    has_bounded_size<ouster_sensor_msgs::srv::GetConfig_Request>::value &&
    has_bounded_size<ouster_sensor_msgs::srv::GetConfig_Response>::value
  >
{
};

template<>
struct is_service<ouster_sensor_msgs::srv::GetConfig>
  : std::true_type
{
};

template<>
struct is_service_request<ouster_sensor_msgs::srv::GetConfig_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ouster_sensor_msgs::srv::GetConfig_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // OUSTER_SENSOR_MSGS__SRV__DETAIL__GET_CONFIG__TRAITS_HPP_
