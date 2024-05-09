// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ouster_sensor_msgs:srv/SetConfig.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_SENSOR_MSGS__SRV__DETAIL__SET_CONFIG__BUILDER_HPP_
#define OUSTER_SENSOR_MSGS__SRV__DETAIL__SET_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ouster_sensor_msgs/srv/detail/set_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ouster_sensor_msgs
{

namespace srv
{

namespace builder
{

class Init_SetConfig_Request_config_file
{
public:
  Init_SetConfig_Request_config_file()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ouster_sensor_msgs::srv::SetConfig_Request config_file(::ouster_sensor_msgs::srv::SetConfig_Request::_config_file_type arg)
  {
    msg_.config_file = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ouster_sensor_msgs::srv::SetConfig_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ouster_sensor_msgs::srv::SetConfig_Request>()
{
  return ouster_sensor_msgs::srv::builder::Init_SetConfig_Request_config_file();
}

}  // namespace ouster_sensor_msgs


namespace ouster_sensor_msgs
{

namespace srv
{

namespace builder
{

class Init_SetConfig_Response_config
{
public:
  Init_SetConfig_Response_config()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ouster_sensor_msgs::srv::SetConfig_Response config(::ouster_sensor_msgs::srv::SetConfig_Response::_config_type arg)
  {
    msg_.config = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ouster_sensor_msgs::srv::SetConfig_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ouster_sensor_msgs::srv::SetConfig_Response>()
{
  return ouster_sensor_msgs::srv::builder::Init_SetConfig_Response_config();
}

}  // namespace ouster_sensor_msgs

#endif  // OUSTER_SENSOR_MSGS__SRV__DETAIL__SET_CONFIG__BUILDER_HPP_
