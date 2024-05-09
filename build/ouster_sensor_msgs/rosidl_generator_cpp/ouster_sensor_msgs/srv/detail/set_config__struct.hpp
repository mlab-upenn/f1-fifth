// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ouster_sensor_msgs:srv/SetConfig.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_SENSOR_MSGS__SRV__DETAIL__SET_CONFIG__STRUCT_HPP_
#define OUSTER_SENSOR_MSGS__SRV__DETAIL__SET_CONFIG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ouster_sensor_msgs__srv__SetConfig_Request __attribute__((deprecated))
#else
# define DEPRECATED__ouster_sensor_msgs__srv__SetConfig_Request __declspec(deprecated)
#endif

namespace ouster_sensor_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetConfig_Request_
{
  using Type = SetConfig_Request_<ContainerAllocator>;

  explicit SetConfig_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->config_file = "";
    }
  }

  explicit SetConfig_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : config_file(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->config_file = "";
    }
  }

  // field types and members
  using _config_file_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _config_file_type config_file;

  // setters for named parameter idiom
  Type & set__config_file(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->config_file = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ouster_sensor_msgs__srv__SetConfig_Request
    std::shared_ptr<ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ouster_sensor_msgs__srv__SetConfig_Request
    std::shared_ptr<ouster_sensor_msgs::srv::SetConfig_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetConfig_Request_ & other) const
  {
    if (this->config_file != other.config_file) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetConfig_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetConfig_Request_

// alias to use template instance with default allocator
using SetConfig_Request =
  ouster_sensor_msgs::srv::SetConfig_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ouster_sensor_msgs


#ifndef _WIN32
# define DEPRECATED__ouster_sensor_msgs__srv__SetConfig_Response __attribute__((deprecated))
#else
# define DEPRECATED__ouster_sensor_msgs__srv__SetConfig_Response __declspec(deprecated)
#endif

namespace ouster_sensor_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetConfig_Response_
{
  using Type = SetConfig_Response_<ContainerAllocator>;

  explicit SetConfig_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->config = "";
    }
  }

  explicit SetConfig_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : config(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->config = "";
    }
  }

  // field types and members
  using _config_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _config_type config;

  // setters for named parameter idiom
  Type & set__config(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->config = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ouster_sensor_msgs__srv__SetConfig_Response
    std::shared_ptr<ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ouster_sensor_msgs__srv__SetConfig_Response
    std::shared_ptr<ouster_sensor_msgs::srv::SetConfig_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetConfig_Response_ & other) const
  {
    if (this->config != other.config) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetConfig_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetConfig_Response_

// alias to use template instance with default allocator
using SetConfig_Response =
  ouster_sensor_msgs::srv::SetConfig_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ouster_sensor_msgs

namespace ouster_sensor_msgs
{

namespace srv
{

struct SetConfig
{
  using Request = ouster_sensor_msgs::srv::SetConfig_Request;
  using Response = ouster_sensor_msgs::srv::SetConfig_Response;
};

}  // namespace srv

}  // namespace ouster_sensor_msgs

#endif  // OUSTER_SENSOR_MSGS__SRV__DETAIL__SET_CONFIG__STRUCT_HPP_
