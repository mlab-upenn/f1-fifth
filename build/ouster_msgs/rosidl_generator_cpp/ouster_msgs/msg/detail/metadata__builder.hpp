// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ouster_msgs:msg/Metadata.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_MSGS__MSG__DETAIL__METADATA__BUILDER_HPP_
#define OUSTER_MSGS__MSG__DETAIL__METADATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ouster_msgs/msg/detail/metadata__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ouster_msgs
{

namespace msg
{

namespace builder
{

class Init_Metadata_lidar_port
{
public:
  explicit Init_Metadata_lidar_port(::ouster_msgs::msg::Metadata & msg)
  : msg_(msg)
  {}
  ::ouster_msgs::msg::Metadata lidar_port(::ouster_msgs::msg::Metadata::_lidar_port_type arg)
  {
    msg_.lidar_port = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ouster_msgs::msg::Metadata msg_;
};

class Init_Metadata_imu_port
{
public:
  explicit Init_Metadata_imu_port(::ouster_msgs::msg::Metadata & msg)
  : msg_(msg)
  {}
  Init_Metadata_lidar_port imu_port(::ouster_msgs::msg::Metadata::_imu_port_type arg)
  {
    msg_.imu_port = std::move(arg);
    return Init_Metadata_lidar_port(msg_);
  }

private:
  ::ouster_msgs::msg::Metadata msg_;
};

class Init_Metadata_firmware_rev
{
public:
  explicit Init_Metadata_firmware_rev(::ouster_msgs::msg::Metadata & msg)
  : msg_(msg)
  {}
  Init_Metadata_imu_port firmware_rev(::ouster_msgs::msg::Metadata::_firmware_rev_type arg)
  {
    msg_.firmware_rev = std::move(arg);
    return Init_Metadata_imu_port(msg_);
  }

private:
  ::ouster_msgs::msg::Metadata msg_;
};

class Init_Metadata_serial_no
{
public:
  explicit Init_Metadata_serial_no(::ouster_msgs::msg::Metadata & msg)
  : msg_(msg)
  {}
  Init_Metadata_firmware_rev serial_no(::ouster_msgs::msg::Metadata::_serial_no_type arg)
  {
    msg_.serial_no = std::move(arg);
    return Init_Metadata_firmware_rev(msg_);
  }

private:
  ::ouster_msgs::msg::Metadata msg_;
};

class Init_Metadata_lidar_to_sensor_transform
{
public:
  explicit Init_Metadata_lidar_to_sensor_transform(::ouster_msgs::msg::Metadata & msg)
  : msg_(msg)
  {}
  Init_Metadata_serial_no lidar_to_sensor_transform(::ouster_msgs::msg::Metadata::_lidar_to_sensor_transform_type arg)
  {
    msg_.lidar_to_sensor_transform = std::move(arg);
    return Init_Metadata_serial_no(msg_);
  }

private:
  ::ouster_msgs::msg::Metadata msg_;
};

class Init_Metadata_imu_to_sensor_transform
{
public:
  explicit Init_Metadata_imu_to_sensor_transform(::ouster_msgs::msg::Metadata & msg)
  : msg_(msg)
  {}
  Init_Metadata_lidar_to_sensor_transform imu_to_sensor_transform(::ouster_msgs::msg::Metadata::_imu_to_sensor_transform_type arg)
  {
    msg_.imu_to_sensor_transform = std::move(arg);
    return Init_Metadata_lidar_to_sensor_transform(msg_);
  }

private:
  ::ouster_msgs::msg::Metadata msg_;
};

class Init_Metadata_beam_altitude_angles
{
public:
  explicit Init_Metadata_beam_altitude_angles(::ouster_msgs::msg::Metadata & msg)
  : msg_(msg)
  {}
  Init_Metadata_imu_to_sensor_transform beam_altitude_angles(::ouster_msgs::msg::Metadata::_beam_altitude_angles_type arg)
  {
    msg_.beam_altitude_angles = std::move(arg);
    return Init_Metadata_imu_to_sensor_transform(msg_);
  }

private:
  ::ouster_msgs::msg::Metadata msg_;
};

class Init_Metadata_beam_azimuth_angles
{
public:
  explicit Init_Metadata_beam_azimuth_angles(::ouster_msgs::msg::Metadata & msg)
  : msg_(msg)
  {}
  Init_Metadata_beam_altitude_angles beam_azimuth_angles(::ouster_msgs::msg::Metadata::_beam_azimuth_angles_type arg)
  {
    msg_.beam_azimuth_angles = std::move(arg);
    return Init_Metadata_beam_altitude_angles(msg_);
  }

private:
  ::ouster_msgs::msg::Metadata msg_;
};

class Init_Metadata_timestamp_mode
{
public:
  explicit Init_Metadata_timestamp_mode(::ouster_msgs::msg::Metadata & msg)
  : msg_(msg)
  {}
  Init_Metadata_beam_azimuth_angles timestamp_mode(::ouster_msgs::msg::Metadata::_timestamp_mode_type arg)
  {
    msg_.timestamp_mode = std::move(arg);
    return Init_Metadata_beam_azimuth_angles(msg_);
  }

private:
  ::ouster_msgs::msg::Metadata msg_;
};

class Init_Metadata_lidar_mode
{
public:
  explicit Init_Metadata_lidar_mode(::ouster_msgs::msg::Metadata & msg)
  : msg_(msg)
  {}
  Init_Metadata_timestamp_mode lidar_mode(::ouster_msgs::msg::Metadata::_lidar_mode_type arg)
  {
    msg_.lidar_mode = std::move(arg);
    return Init_Metadata_timestamp_mode(msg_);
  }

private:
  ::ouster_msgs::msg::Metadata msg_;
};

class Init_Metadata_hostname
{
public:
  Init_Metadata_hostname()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Metadata_lidar_mode hostname(::ouster_msgs::msg::Metadata::_hostname_type arg)
  {
    msg_.hostname = std::move(arg);
    return Init_Metadata_lidar_mode(msg_);
  }

private:
  ::ouster_msgs::msg::Metadata msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ouster_msgs::msg::Metadata>()
{
  return ouster_msgs::msg::builder::Init_Metadata_hostname();
}

}  // namespace ouster_msgs

#endif  // OUSTER_MSGS__MSG__DETAIL__METADATA__BUILDER_HPP_
