// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ouster_msgs:srv/GetMetadata.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_MSGS__SRV__DETAIL__GET_METADATA__BUILDER_HPP_
#define OUSTER_MSGS__SRV__DETAIL__GET_METADATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ouster_msgs/srv/detail/get_metadata__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ouster_msgs
{

namespace srv
{

namespace builder
{

class Init_GetMetadata_Request_metadata_filepath
{
public:
  Init_GetMetadata_Request_metadata_filepath()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ouster_msgs::srv::GetMetadata_Request metadata_filepath(::ouster_msgs::srv::GetMetadata_Request::_metadata_filepath_type arg)
  {
    msg_.metadata_filepath = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ouster_msgs::srv::GetMetadata_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ouster_msgs::srv::GetMetadata_Request>()
{
  return ouster_msgs::srv::builder::Init_GetMetadata_Request_metadata_filepath();
}

}  // namespace ouster_msgs


namespace ouster_msgs
{

namespace srv
{

namespace builder
{

class Init_GetMetadata_Response_metadata
{
public:
  Init_GetMetadata_Response_metadata()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ouster_msgs::srv::GetMetadata_Response metadata(::ouster_msgs::srv::GetMetadata_Response::_metadata_type arg)
  {
    msg_.metadata = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ouster_msgs::srv::GetMetadata_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ouster_msgs::srv::GetMetadata_Response>()
{
  return ouster_msgs::srv::builder::Init_GetMetadata_Response_metadata();
}

}  // namespace ouster_msgs

#endif  // OUSTER_MSGS__SRV__DETAIL__GET_METADATA__BUILDER_HPP_
