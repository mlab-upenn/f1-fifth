// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ouster_sensor_msgs:msg/PacketMsg.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_SENSOR_MSGS__MSG__DETAIL__PACKET_MSG__STRUCT_HPP_
#define OUSTER_SENSOR_MSGS__MSG__DETAIL__PACKET_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ouster_sensor_msgs__msg__PacketMsg __attribute__((deprecated))
#else
# define DEPRECATED__ouster_sensor_msgs__msg__PacketMsg __declspec(deprecated)
#endif

namespace ouster_sensor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PacketMsg_
{
  using Type = PacketMsg_<ContainerAllocator>;

  explicit PacketMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit PacketMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _buf_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _buf_type buf;

  // setters for named parameter idiom
  Type & set__buf(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->buf = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ouster_sensor_msgs__msg__PacketMsg
    std::shared_ptr<ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ouster_sensor_msgs__msg__PacketMsg
    std::shared_ptr<ouster_sensor_msgs::msg::PacketMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PacketMsg_ & other) const
  {
    if (this->buf != other.buf) {
      return false;
    }
    return true;
  }
  bool operator!=(const PacketMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PacketMsg_

// alias to use template instance with default allocator
using PacketMsg =
  ouster_sensor_msgs::msg::PacketMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ouster_sensor_msgs

#endif  // OUSTER_SENSOR_MSGS__MSG__DETAIL__PACKET_MSG__STRUCT_HPP_
