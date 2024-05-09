// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fixposition_driver_ros2:msg/NMEA.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__STRUCT_HPP_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fixposition_driver_ros2__msg__NMEA __attribute__((deprecated))
#else
# define DEPRECATED__fixposition_driver_ros2__msg__NMEA __declspec(deprecated)
#endif

namespace fixposition_driver_ros2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NMEA_
{
  using Type = NMEA_<ContainerAllocator>;

  explicit NMEA_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->altitude = 0.0;
      this->speed = 0.0;
      this->course = 0.0;
      std::fill<typename std::array<double, 9>::iterator, double>(this->position_covariance.begin(), this->position_covariance.end(), 0.0);
      this->position_covariance_type = 0;
      this->mode = "";
    }
  }

  explicit NMEA_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    position_covariance(_alloc),
    mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->altitude = 0.0;
      this->speed = 0.0;
      this->course = 0.0;
      std::fill<typename std::array<double, 9>::iterator, double>(this->position_covariance.begin(), this->position_covariance.end(), 0.0);
      this->position_covariance_type = 0;
      this->mode = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _altitude_type =
    double;
  _altitude_type altitude;
  using _speed_type =
    double;
  _speed_type speed;
  using _course_type =
    double;
  _course_type course;
  using _position_covariance_type =
    std::array<double, 9>;
  _position_covariance_type position_covariance;
  using _position_covariance_type_type =
    uint8_t;
  _position_covariance_type_type position_covariance_type;
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__altitude(
    const double & _arg)
  {
    this->altitude = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__course(
    const double & _arg)
  {
    this->course = _arg;
    return *this;
  }
  Type & set__position_covariance(
    const std::array<double, 9> & _arg)
  {
    this->position_covariance = _arg;
    return *this;
  }
  Type & set__position_covariance_type(
    const uint8_t & _arg)
  {
    this->position_covariance_type = _arg;
    return *this;
  }
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t COVARIANCE_TYPE_UNKNOWN =
    0u;
  static constexpr uint8_t COVARIANCE_TYPE_APPROXIMATED =
    1u;
  static constexpr uint8_t COVARIANCE_TYPE_DIAGONAL_KNOWN =
    2u;
  static constexpr uint8_t COVARIANCE_TYPE_KNOWN =
    3u;

  // pointer types
  using RawPtr =
    fixposition_driver_ros2::msg::NMEA_<ContainerAllocator> *;
  using ConstRawPtr =
    const fixposition_driver_ros2::msg::NMEA_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fixposition_driver_ros2::msg::NMEA_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fixposition_driver_ros2::msg::NMEA_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fixposition_driver_ros2::msg::NMEA_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fixposition_driver_ros2::msg::NMEA_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fixposition_driver_ros2::msg::NMEA_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fixposition_driver_ros2::msg::NMEA_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fixposition_driver_ros2::msg::NMEA_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fixposition_driver_ros2::msg::NMEA_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fixposition_driver_ros2__msg__NMEA
    std::shared_ptr<fixposition_driver_ros2::msg::NMEA_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fixposition_driver_ros2__msg__NMEA
    std::shared_ptr<fixposition_driver_ros2::msg::NMEA_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NMEA_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->altitude != other.altitude) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->course != other.course) {
      return false;
    }
    if (this->position_covariance != other.position_covariance) {
      return false;
    }
    if (this->position_covariance_type != other.position_covariance_type) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const NMEA_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NMEA_

// alias to use template instance with default allocator
using NMEA =
  fixposition_driver_ros2::msg::NMEA_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NMEA_<ContainerAllocator>::COVARIANCE_TYPE_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NMEA_<ContainerAllocator>::COVARIANCE_TYPE_APPROXIMATED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NMEA_<ContainerAllocator>::COVARIANCE_TYPE_DIAGONAL_KNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NMEA_<ContainerAllocator>::COVARIANCE_TYPE_KNOWN;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace fixposition_driver_ros2

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__STRUCT_HPP_
