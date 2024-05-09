// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ouster_msgs:srv/GetMetadata.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_MSGS__SRV__DETAIL__GET_METADATA__STRUCT_HPP_
#define OUSTER_MSGS__SRV__DETAIL__GET_METADATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ouster_msgs__srv__GetMetadata_Request __attribute__((deprecated))
#else
# define DEPRECATED__ouster_msgs__srv__GetMetadata_Request __declspec(deprecated)
#endif

namespace ouster_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetMetadata_Request_
{
  using Type = GetMetadata_Request_<ContainerAllocator>;

  explicit GetMetadata_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->metadata_filepath = "";
    }
  }

  explicit GetMetadata_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : metadata_filepath(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->metadata_filepath = "";
    }
  }

  // field types and members
  using _metadata_filepath_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _metadata_filepath_type metadata_filepath;

  // setters for named parameter idiom
  Type & set__metadata_filepath(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->metadata_filepath = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ouster_msgs__srv__GetMetadata_Request
    std::shared_ptr<ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ouster_msgs__srv__GetMetadata_Request
    std::shared_ptr<ouster_msgs::srv::GetMetadata_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetMetadata_Request_ & other) const
  {
    if (this->metadata_filepath != other.metadata_filepath) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetMetadata_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetMetadata_Request_

// alias to use template instance with default allocator
using GetMetadata_Request =
  ouster_msgs::srv::GetMetadata_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ouster_msgs


// Include directives for member types
// Member 'metadata'
#include "ouster_msgs/msg/detail/metadata__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ouster_msgs__srv__GetMetadata_Response __attribute__((deprecated))
#else
# define DEPRECATED__ouster_msgs__srv__GetMetadata_Response __declspec(deprecated)
#endif

namespace ouster_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetMetadata_Response_
{
  using Type = GetMetadata_Response_<ContainerAllocator>;

  explicit GetMetadata_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : metadata(_init)
  {
    (void)_init;
  }

  explicit GetMetadata_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : metadata(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _metadata_type =
    ouster_msgs::msg::Metadata_<ContainerAllocator>;
  _metadata_type metadata;

  // setters for named parameter idiom
  Type & set__metadata(
    const ouster_msgs::msg::Metadata_<ContainerAllocator> & _arg)
  {
    this->metadata = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ouster_msgs__srv__GetMetadata_Response
    std::shared_ptr<ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ouster_msgs__srv__GetMetadata_Response
    std::shared_ptr<ouster_msgs::srv::GetMetadata_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetMetadata_Response_ & other) const
  {
    if (this->metadata != other.metadata) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetMetadata_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetMetadata_Response_

// alias to use template instance with default allocator
using GetMetadata_Response =
  ouster_msgs::srv::GetMetadata_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ouster_msgs

namespace ouster_msgs
{

namespace srv
{

struct GetMetadata
{
  using Request = ouster_msgs::srv::GetMetadata_Request;
  using Response = ouster_msgs::srv::GetMetadata_Response;
};

}  // namespace srv

}  // namespace ouster_msgs

#endif  // OUSTER_MSGS__SRV__DETAIL__GET_METADATA__STRUCT_HPP_
