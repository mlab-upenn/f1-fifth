// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fixposition_driver_ros2:msg/NMEA.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__BUILDER_HPP_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fixposition_driver_ros2/msg/detail/nmea__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fixposition_driver_ros2
{

namespace msg
{

namespace builder
{

class Init_NMEA_mode
{
public:
  explicit Init_NMEA_mode(::fixposition_driver_ros2::msg::NMEA & msg)
  : msg_(msg)
  {}
  ::fixposition_driver_ros2::msg::NMEA mode(::fixposition_driver_ros2::msg::NMEA::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::NMEA msg_;
};

class Init_NMEA_position_covariance_type
{
public:
  explicit Init_NMEA_position_covariance_type(::fixposition_driver_ros2::msg::NMEA & msg)
  : msg_(msg)
  {}
  Init_NMEA_mode position_covariance_type(::fixposition_driver_ros2::msg::NMEA::_position_covariance_type_type arg)
  {
    msg_.position_covariance_type = std::move(arg);
    return Init_NMEA_mode(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::NMEA msg_;
};

class Init_NMEA_position_covariance
{
public:
  explicit Init_NMEA_position_covariance(::fixposition_driver_ros2::msg::NMEA & msg)
  : msg_(msg)
  {}
  Init_NMEA_position_covariance_type position_covariance(::fixposition_driver_ros2::msg::NMEA::_position_covariance_type arg)
  {
    msg_.position_covariance = std::move(arg);
    return Init_NMEA_position_covariance_type(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::NMEA msg_;
};

class Init_NMEA_course
{
public:
  explicit Init_NMEA_course(::fixposition_driver_ros2::msg::NMEA & msg)
  : msg_(msg)
  {}
  Init_NMEA_position_covariance course(::fixposition_driver_ros2::msg::NMEA::_course_type arg)
  {
    msg_.course = std::move(arg);
    return Init_NMEA_position_covariance(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::NMEA msg_;
};

class Init_NMEA_speed
{
public:
  explicit Init_NMEA_speed(::fixposition_driver_ros2::msg::NMEA & msg)
  : msg_(msg)
  {}
  Init_NMEA_course speed(::fixposition_driver_ros2::msg::NMEA::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_NMEA_course(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::NMEA msg_;
};

class Init_NMEA_altitude
{
public:
  explicit Init_NMEA_altitude(::fixposition_driver_ros2::msg::NMEA & msg)
  : msg_(msg)
  {}
  Init_NMEA_speed altitude(::fixposition_driver_ros2::msg::NMEA::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_NMEA_speed(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::NMEA msg_;
};

class Init_NMEA_longitude
{
public:
  explicit Init_NMEA_longitude(::fixposition_driver_ros2::msg::NMEA & msg)
  : msg_(msg)
  {}
  Init_NMEA_altitude longitude(::fixposition_driver_ros2::msg::NMEA::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_NMEA_altitude(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::NMEA msg_;
};

class Init_NMEA_latitude
{
public:
  explicit Init_NMEA_latitude(::fixposition_driver_ros2::msg::NMEA & msg)
  : msg_(msg)
  {}
  Init_NMEA_longitude latitude(::fixposition_driver_ros2::msg::NMEA::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_NMEA_longitude(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::NMEA msg_;
};

class Init_NMEA_header
{
public:
  Init_NMEA_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NMEA_latitude header(::fixposition_driver_ros2::msg::NMEA::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NMEA_latitude(msg_);
  }

private:
  ::fixposition_driver_ros2::msg::NMEA msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fixposition_driver_ros2::msg::NMEA>()
{
  return fixposition_driver_ros2::msg::builder::Init_NMEA_header();
}

}  // namespace fixposition_driver_ros2

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__BUILDER_HPP_
