// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fixposition_driver_ros2:msg/Speed.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__SPEED__STRUCT_HPP_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__SPEED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'sensors'
#include "fixposition_driver_ros2/msg/detail/wheel_sensor__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fixposition_driver_ros2__msg__Speed __attribute__((deprecated))
#else
# define DEPRECATED__fixposition_driver_ros2__msg__Speed __declspec(deprecated)
#endif

namespace fixposition_driver_ros2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Speed_
{
  using Type = Speed_<ContainerAllocator>;

  explicit Speed_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Speed_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _sensors_type =
    std::vector<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator>>>;
  _sensors_type sensors;

  // setters for named parameter idiom
  Type & set__sensors(
    const std::vector<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<fixposition_driver_ros2::msg::WheelSensor_<ContainerAllocator>>> & _arg)
  {
    this->sensors = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fixposition_driver_ros2::msg::Speed_<ContainerAllocator> *;
  using ConstRawPtr =
    const fixposition_driver_ros2::msg::Speed_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fixposition_driver_ros2::msg::Speed_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fixposition_driver_ros2::msg::Speed_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fixposition_driver_ros2::msg::Speed_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fixposition_driver_ros2::msg::Speed_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fixposition_driver_ros2::msg::Speed_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fixposition_driver_ros2::msg::Speed_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fixposition_driver_ros2::msg::Speed_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fixposition_driver_ros2::msg::Speed_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fixposition_driver_ros2__msg__Speed
    std::shared_ptr<fixposition_driver_ros2::msg::Speed_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fixposition_driver_ros2__msg__Speed
    std::shared_ptr<fixposition_driver_ros2::msg::Speed_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Speed_ & other) const
  {
    if (this->sensors != other.sensors) {
      return false;
    }
    return true;
  }
  bool operator!=(const Speed_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Speed_

// alias to use template instance with default allocator
using Speed =
  fixposition_driver_ros2::msg::Speed_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fixposition_driver_ros2

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__SPEED__STRUCT_HPP_
