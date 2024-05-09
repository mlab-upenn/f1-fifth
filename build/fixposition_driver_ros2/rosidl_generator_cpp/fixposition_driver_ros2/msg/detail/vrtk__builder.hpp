// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fixposition_driver_ros2:msg/VRTK.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__VRTK__BUILDER_HPP_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__VRTK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fixposition_driver_ros2/msg/detail/vrtk__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fixposition_driver_ros2
{

namespace msg
{

namespace builder
{

class Init_VRTK_version
{
public:
  explicit Init_VRTK_version(::fixposition_driver_ros2::msg::VRTK & msg)
  : msg_(msg)
  {}
  ::fixposition_driver_ros2::msg::VRTK version(::fixposition_driver_ros2::msg::VRTK::_version_type arg)
  {
    msg_.version = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

class Init_VRTK_wheelspeed_status
{
public:
  explicit Init_VRTK_wheelspeed_status(::fixposition_driver_ros2::msg::VRTK & msg)
  : msg_(msg)
  {}
  Init_VRTK_version wheelspeed_status(::fixposition_driver_ros2::msg::VRTK::_wheelspeed_status_type arg)
  {
    msg_.wheelspeed_status = std::move(arg);
    return Init_VRTK_version(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

class Init_VRTK_gnss2_status
{
public:
  explicit Init_VRTK_gnss2_status(::fixposition_driver_ros2::msg::VRTK & msg)
  : msg_(msg)
  {}
  Init_VRTK_wheelspeed_status gnss2_status(::fixposition_driver_ros2::msg::VRTK::_gnss2_status_type arg)
  {
    msg_.gnss2_status = std::move(arg);
    return Init_VRTK_wheelspeed_status(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

class Init_VRTK_gnss1_status
{
public:
  explicit Init_VRTK_gnss1_status(::fixposition_driver_ros2::msg::VRTK & msg)
  : msg_(msg)
  {}
  Init_VRTK_gnss2_status gnss1_status(::fixposition_driver_ros2::msg::VRTK::_gnss1_status_type arg)
  {
    msg_.gnss1_status = std::move(arg);
    return Init_VRTK_gnss2_status(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

class Init_VRTK_imu_bias_status
{
public:
  explicit Init_VRTK_imu_bias_status(::fixposition_driver_ros2::msg::VRTK & msg)
  : msg_(msg)
  {}
  Init_VRTK_gnss1_status imu_bias_status(::fixposition_driver_ros2::msg::VRTK::_imu_bias_status_type arg)
  {
    msg_.imu_bias_status = std::move(arg);
    return Init_VRTK_gnss1_status(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

class Init_VRTK_fusion_status
{
public:
  explicit Init_VRTK_fusion_status(::fixposition_driver_ros2::msg::VRTK & msg)
  : msg_(msg)
  {}
  Init_VRTK_imu_bias_status fusion_status(::fixposition_driver_ros2::msg::VRTK::_fusion_status_type arg)
  {
    msg_.fusion_status = std::move(arg);
    return Init_VRTK_imu_bias_status(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

class Init_VRTK_acceleration
{
public:
  explicit Init_VRTK_acceleration(::fixposition_driver_ros2::msg::VRTK & msg)
  : msg_(msg)
  {}
  Init_VRTK_fusion_status acceleration(::fixposition_driver_ros2::msg::VRTK::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_VRTK_fusion_status(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

class Init_VRTK_velocity
{
public:
  explicit Init_VRTK_velocity(::fixposition_driver_ros2::msg::VRTK & msg)
  : msg_(msg)
  {}
  Init_VRTK_acceleration velocity(::fixposition_driver_ros2::msg::VRTK::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_VRTK_acceleration(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

class Init_VRTK_pose
{
public:
  explicit Init_VRTK_pose(::fixposition_driver_ros2::msg::VRTK & msg)
  : msg_(msg)
  {}
  Init_VRTK_velocity pose(::fixposition_driver_ros2::msg::VRTK::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_VRTK_velocity(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

class Init_VRTK_kin_frame
{
public:
  explicit Init_VRTK_kin_frame(::fixposition_driver_ros2::msg::VRTK & msg)
  : msg_(msg)
  {}
  Init_VRTK_pose kin_frame(::fixposition_driver_ros2::msg::VRTK::_kin_frame_type arg)
  {
    msg_.kin_frame = std::move(arg);
    return Init_VRTK_pose(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

class Init_VRTK_pose_frame
{
public:
  explicit Init_VRTK_pose_frame(::fixposition_driver_ros2::msg::VRTK & msg)
  : msg_(msg)
  {}
  Init_VRTK_kin_frame pose_frame(::fixposition_driver_ros2::msg::VRTK::_pose_frame_type arg)
  {
    msg_.pose_frame = std::move(arg);
    return Init_VRTK_kin_frame(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

class Init_VRTK_header
{
public:
  Init_VRTK_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VRTK_pose_frame header(::fixposition_driver_ros2::msg::VRTK::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VRTK_pose_frame(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::VRTK msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fixposition_driver_ros2::msg::VRTK>()
{
  return fixposition_driver_ros2::msg::builder::Init_VRTK_header();
}

}  // namespace fixposition_driver_ros2

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__VRTK__BUILDER_HPP_
