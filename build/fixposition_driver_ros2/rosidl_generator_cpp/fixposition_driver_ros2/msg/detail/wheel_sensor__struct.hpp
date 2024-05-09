// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fixposition_driver_ros2:msg/WheelSensor.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__STRUCT_HPP_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__STRUCT_HPP_

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
# define DEPRECATED__fixposition_driver_ros2__msg__WheelSensor __attribute__((deprecated))
#else
# define DEPRECATED__fixposition_driver_ros2__msg__WheelSensor __declspec(deprecated)
#endif

namespace fixposition_driver_ros2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WheelSensor_
{
  using Type = WheelSensor_<ContainerAllocator>;

  explicit WheelSensor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->location = "";
      this->vx = 0l;
      this->vy = 0l;
      this->vz = 0l;
      this->vx_valid = false;
      this->vy_valid = false;
      this->vz_valid = false;
    }
  }

  explicit WheelSensor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    location(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->location = "";
      this->vx = 0l;
      this->vy = 0l;
      this->vz = 0l;
      this->vx_valid = false;
      this->vy_valid = false;
      this->vz_valid = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _location_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _location_type location;
  using _vx_type =
    int32_t;
  _vx_type vx;
  using _vy_type =
    int32_t;
  _vy_type vy;
  using _vz_type =
    int32_t;
  _vz_type vz;
  using _vx_valid_type =
    bool;
  _vx_valid_type vx_valid;
  using _vy_valid_type =
    bool;
  _vy_valid_type vy_valid;
  using _vz_valid_type =
    bool;
  _vz_valid_type vz_valid;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__location(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->location = _arg;
    return *this;
  }
  Type & set__vx(
    const int32_t & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const int32_t & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__vz(
    const int32_t & _arg)
  {
    this->vz = _arg;
    return *this;
  }
  Type & set__vx_valid(
    const bool & _arg)
  {
    this->vx_valid = _arg;
    return *this;
  }
  Type & set__vy_valid(
    const bool & _arg)
  {
    this->vy_valid = _arg;
    return *this;
  }
  Type & set__vz_valid(
    const bool & _arg)
  {
    this->vz_valid = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator> *;
  using ConstRawPtr =
    const fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fixposition_driver_ros2__msg__WheelSensor
    std::shared_ptr<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fixposition_driver_ros2__msg__WheelSensor
    std::shared_ptr<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WheelSensor_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->location != other.location) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->vz != other.vz) {
      return false;
    }
    if (this->vx_valid != other.vx_valid) {
      return false;
    }
    if (this->vy_valid != other.vy_valid) {
      return false;
    }
    if (this->vz_valid != other.vz_valid) {
      return false;
    }
    return true;
  }
  bool operator!=(const WheelSensor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WheelSensor_

// alias to use template instance with default allocator
using WheelSensor =
  fixposition_driver_ros2::msg::WheelSensor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fixposition_driver_ros2

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__STRUCT_HPP_
