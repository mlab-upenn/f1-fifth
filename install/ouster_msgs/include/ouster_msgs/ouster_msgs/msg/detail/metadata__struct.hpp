// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ouster_msgs:msg/Metadata.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_MSGS__MSG__DETAIL__METADATA__STRUCT_HPP_
#define OUSTER_MSGS__MSG__DETAIL__METADATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ouster_msgs__msg__Metadata __attribute__((deprecated))
#else
# define DEPRECATED__ouster_msgs__msg__Metadata __declspec(deprecated)
#endif

namespace ouster_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Metadata_
{
  using Type = Metadata_<ContainerAllocator>;

  explicit Metadata_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->hostname = "";
      this->lidar_mode = "";
      this->timestamp_mode = "";
      this->serial_no = "";
      this->firmware_rev = "";
      this->imu_port = 0;
      this->lidar_port = 0;
    }
  }

  explicit Metadata_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : hostname(_alloc),
    lidar_mode(_alloc),
    timestamp_mode(_alloc),
    serial_no(_alloc),
    firmware_rev(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->hostname = "";
      this->lidar_mode = "";
      this->timestamp_mode = "";
      this->serial_no = "";
      this->firmware_rev = "";
      this->imu_port = 0;
      this->lidar_port = 0;
    }
  }

  // field types and members
  using _hostname_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _hostname_type hostname;
  using _lidar_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _lidar_mode_type lidar_mode;
  using _timestamp_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _timestamp_mode_type timestamp_mode;
  using _beam_azimuth_angles_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _beam_azimuth_angles_type beam_azimuth_angles;
  using _beam_altitude_angles_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _beam_altitude_angles_type beam_altitude_angles;
  using _imu_to_sensor_transform_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _imu_to_sensor_transform_type imu_to_sensor_transform;
  using _lidar_to_sensor_transform_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _lidar_to_sensor_transform_type lidar_to_sensor_transform;
  using _serial_no_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _serial_no_type serial_no;
  using _firmware_rev_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _firmware_rev_type firmware_rev;
  using _imu_port_type =
    int8_t;
  _imu_port_type imu_port;
  using _lidar_port_type =
    int8_t;
  _lidar_port_type lidar_port;

  // setters for named parameter idiom
  Type & set__hostname(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->hostname = _arg;
    return *this;
  }
  Type & set__lidar_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->lidar_mode = _arg;
    return *this;
  }
  Type & set__timestamp_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->timestamp_mode = _arg;
    return *this;
  }
  Type & set__beam_azimuth_angles(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->beam_azimuth_angles = _arg;
    return *this;
  }
  Type & set__beam_altitude_angles(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->beam_altitude_angles = _arg;
    return *this;
  }
  Type & set__imu_to_sensor_transform(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->imu_to_sensor_transform = _arg;
    return *this;
  }
  Type & set__lidar_to_sensor_transform(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->lidar_to_sensor_transform = _arg;
    return *this;
  }
  Type & set__serial_no(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->serial_no = _arg;
    return *this;
  }
  Type & set__firmware_rev(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->firmware_rev = _arg;
    return *this;
  }
  Type & set__imu_port(
    const int8_t & _arg)
  {
    this->imu_port = _arg;
    return *this;
  }
  Type & set__lidar_port(
    const int8_t & _arg)
  {
    this->lidar_port = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ouster_msgs::msg::Metadata_<ContainerAllocator> *;
  using ConstRawPtr =
    const ouster_msgs::msg::Metadata_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ouster_msgs::msg::Metadata_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ouster_msgs::msg::Metadata_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ouster_msgs::msg::Metadata_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ouster_msgs::msg::Metadata_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ouster_msgs::msg::Metadata_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ouster_msgs::msg::Metadata_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ouster_msgs::msg::Metadata_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ouster_msgs::msg::Metadata_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ouster_msgs__msg__Metadata
    std::shared_ptr<ouster_msgs::msg::Metadata_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ouster_msgs__msg__Metadata
    std::shared_ptr<ouster_msgs::msg::Metadata_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Metadata_ & other) const
  {
    if (this->hostname != other.hostname) {
      return false;
    }
    if (this->lidar_mode != other.lidar_mode) {
      return false;
    }
    if (this->timestamp_mode != other.timestamp_mode) {
      return false;
    }
    if (this->beam_azimuth_angles != other.beam_azimuth_angles) {
      return false;
    }
    if (this->beam_altitude_angles != other.beam_altitude_angles) {
      return false;
    }
    if (this->imu_to_sensor_transform != other.imu_to_sensor_transform) {
      return false;
    }
    if (this->lidar_to_sensor_transform != other.lidar_to_sensor_transform) {
      return false;
    }
    if (this->serial_no != other.serial_no) {
      return false;
    }
    if (this->firmware_rev != other.firmware_rev) {
      return false;
    }
    if (this->imu_port != other.imu_port) {
      return false;
    }
    if (this->lidar_port != other.lidar_port) {
      return false;
    }
    return true;
  }
  bool operator!=(const Metadata_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Metadata_

// alias to use template instance with default allocator
using Metadata =
  ouster_msgs::msg::Metadata_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ouster_msgs

#endif  // OUSTER_MSGS__MSG__DETAIL__METADATA__STRUCT_HPP_
