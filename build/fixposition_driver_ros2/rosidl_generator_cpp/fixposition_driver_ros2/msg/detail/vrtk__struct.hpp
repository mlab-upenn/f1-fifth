// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fixposition_driver_ros2:msg/VRTK.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__VRTK__STRUCT_HPP_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__VRTK__STRUCT_HPP_

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
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_with_covariance__struct.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist_with_covariance__struct.hpp"
// Member 'acceleration'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fixposition_driver_ros2__msg__VRTK __attribute__((deprecated))
#else
# define DEPRECATED__fixposition_driver_ros2__msg__VRTK __declspec(deprecated)
#endif

namespace fixposition_driver_ros2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VRTK_
{
  using Type = VRTK_<ContainerAllocator>;

  explicit VRTK_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pose(_init),
    velocity(_init),
    acceleration(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pose_frame = "";
      this->kin_frame = "";
      this->fusion_status = 0;
      this->imu_bias_status = 0;
      this->gnss1_status = 0;
      this->gnss2_status = 0;
      this->wheelspeed_status = 0;
      this->version = "";
    }
  }

  explicit VRTK_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    pose_frame(_alloc),
    kin_frame(_alloc),
    pose(_alloc, _init),
    velocity(_alloc, _init),
    acceleration(_alloc, _init),
    version(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pose_frame = "";
      this->kin_frame = "";
      this->fusion_status = 0;
      this->imu_bias_status = 0;
      this->gnss1_status = 0;
      this->gnss2_status = 0;
      this->wheelspeed_status = 0;
      this->version = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _pose_frame_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _pose_frame_type pose_frame;
  using _kin_frame_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _kin_frame_type kin_frame;
  using _pose_type =
    geometry_msgs::msg::PoseWithCovariance_<ContainerAllocator>;
  _pose_type pose;
  using _velocity_type =
    geometry_msgs::msg::TwistWithCovariance_<ContainerAllocator>;
  _velocity_type velocity;
  using _acceleration_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _acceleration_type acceleration;
  using _fusion_status_type =
    int16_t;
  _fusion_status_type fusion_status;
  using _imu_bias_status_type =
    int16_t;
  _imu_bias_status_type imu_bias_status;
  using _gnss1_status_type =
    int16_t;
  _gnss1_status_type gnss1_status;
  using _gnss2_status_type =
    int16_t;
  _gnss2_status_type gnss2_status;
  using _wheelspeed_status_type =
    int16_t;
  _wheelspeed_status_type wheelspeed_status;
  using _version_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _version_type version;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__pose_frame(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->pose_frame = _arg;
    return *this;
  }
  Type & set__kin_frame(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->kin_frame = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::PoseWithCovariance_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::TwistWithCovariance_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__acceleration(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }
  Type & set__fusion_status(
    const int16_t & _arg)
  {
    this->fusion_status = _arg;
    return *this;
  }
  Type & set__imu_bias_status(
    const int16_t & _arg)
  {
    this->imu_bias_status = _arg;
    return *this;
  }
  Type & set__gnss1_status(
    const int16_t & _arg)
  {
    this->gnss1_status = _arg;
    return *this;
  }
  Type & set__gnss2_status(
    const int16_t & _arg)
  {
    this->gnss2_status = _arg;
    return *this;
  }
  Type & set__wheelspeed_status(
    const int16_t & _arg)
  {
    this->wheelspeed_status = _arg;
    return *this;
  }
  Type & set__version(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->version = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fixposition_driver_ros2::msg::VRTK_<ContainerAllocator> *;
  using ConstRawPtr =
    const fixposition_driver_ros2::msg::VRTK_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fixposition_driver_ros2::msg::VRTK_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fixposition_driver_ros2::msg::VRTK_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fixposition_driver_ros2::msg::VRTK_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fixposition_driver_ros2::msg::VRTK_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fixposition_driver_ros2::msg::VRTK_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fixposition_driver_ros2::msg::VRTK_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fixposition_driver_ros2::msg::VRTK_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fixposition_driver_ros2::msg::VRTK_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fixposition_driver_ros2__msg__VRTK
    std::shared_ptr<fixposition_driver_ros2::msg::VRTK_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fixposition_driver_ros2__msg__VRTK
    std::shared_ptr<fixposition_driver_ros2::msg::VRTK_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VRTK_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->pose_frame != other.pose_frame) {
      return false;
    }
    if (this->kin_frame != other.kin_frame) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    if (this->fusion_status != other.fusion_status) {
      return false;
    }
    if (this->imu_bias_status != other.imu_bias_status) {
      return false;
    }
    if (this->gnss1_status != other.gnss1_status) {
      return false;
    }
    if (this->gnss2_status != other.gnss2_status) {
      return false;
    }
    if (this->wheelspeed_status != other.wheelspeed_status) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    return true;
  }
  bool operator!=(const VRTK_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VRTK_

// alias to use template instance with default allocator
using VRTK =
  fixposition_driver_ros2::msg::VRTK_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fixposition_driver_ros2

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__VRTK__STRUCT_HPP_
