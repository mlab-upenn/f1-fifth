// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fixposition_driver_ros2:msg/WheelSensor.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__BUILDER_HPP_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fixposition_driver_ros2/msg/detail/wheel_sensor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fixposition_driver_ros2
{

namespace msg
{

namespace builder
{

class Init_WheelSensor_vz_valid
{
public:
  explicit Init_WheelSensor_vz_valid(::fixposition_driver_ros2::msg::WheelSensor & msg)
  : msg_(msg)
  {}
  ::fixposition_driver_ros2::msg::WheelSensor vz_valid(::fixposition_driver_ros2::msg::WheelSensor::_vz_valid_type arg)
  {
    msg_.vz_valid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::WheelSensor msg_;
};

class Init_WheelSensor_vy_valid
{
public:
  explicit Init_WheelSensor_vy_valid(::fixposition_driver_ros2::msg::WheelSensor & msg)
  : msg_(msg)
  {}
  Init_WheelSensor_vz_valid vy_valid(::fixposition_driver_ros2::msg::WheelSensor::_vy_valid_type arg)
  {
    msg_.vy_valid = std::move(arg);
    return Init_WheelSensor_vz_valid(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::WheelSensor msg_;
};

class Init_WheelSensor_vx_valid
{
public:
  explicit Init_WheelSensor_vx_valid(::fixposition_driver_ros2::msg::WheelSensor & msg)
  : msg_(msg)
  {}
  Init_WheelSensor_vy_valid vx_valid(::fixposition_driver_ros2::msg::WheelSensor::_vx_valid_type arg)
  {
    msg_.vx_valid = std::move(arg);
    return Init_WheelSensor_vy_valid(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::WheelSensor msg_;
};

class Init_WheelSensor_vz
{
public:
  explicit Init_WheelSensor_vz(::fixposition_driver_ros2::msg::WheelSensor & msg)
  : msg_(msg)
  {}
  Init_WheelSensor_vx_valid vz(::fixposition_driver_ros2::msg::WheelSensor::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_WheelSensor_vx_valid(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::WheelSensor msg_;
};

class Init_WheelSensor_vy
{
public:
  explicit Init_WheelSensor_vy(::fixposition_driver_ros2::msg::WheelSensor & msg)
  : msg_(msg)
  {}
  Init_WheelSensor_vz vy(::fixposition_driver_ros2::msg::WheelSensor::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_WheelSensor_vz(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::WheelSensor msg_;
};

class Init_WheelSensor_vx
{
public:
  explicit Init_WheelSensor_vx(::fixposition_driver_ros2::msg::WheelSensor & msg)
  : msg_(msg)
  {}
  Init_WheelSensor_vy vx(::fixposition_driver_ros2::msg::WheelSensor::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_WheelSensor_vy(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::WheelSensor msg_;
};

class Init_WheelSensor_location
{
public:
  explicit Init_WheelSensor_location(::fixposition_driver_ros2::msg::WheelSensor & msg)
  : msg_(msg)
  {}
  Init_WheelSensor_vx location(::fixposition_driver_ros2::msg::WheelSensor::_location_type arg)
  {
    msg_.location = std::move(arg);
    return Init_WheelSensor_vx(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::WheelSensor msg_;
};

class Init_WheelSensor_header
{
public:
  Init_WheelSensor_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WheelSensor_location header(::fixposition_driver_ros2::msg::WheelSensor::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_WheelSensor_location(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::WheelSensor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fixposition_driver_ros2::msg::WheelSensor>()
{
  return fixposition_driver_ros2::msg::builder::Init_WheelSensor_header();
}

}  // namespace fixposition_driver_ros2

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__BUILDER_HPP_
