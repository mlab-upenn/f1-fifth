// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from fixposition_driver_ros2:msg/Speed.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "fixposition_driver_ros2/msg/detail/speed__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace fixposition_driver_ros2
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Speed_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) fixposition_driver_ros2::msg::Speed(_init);
}

void Speed_fini_function(void * message_memory)
{
  auto typed_message = static_cast<fixposition_driver_ros2::msg::Speed *>(message_memory);
  typed_message->~Speed();
}

size_t size_function__Speed__sensors(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<fixposition_driver_ros2::msg::WheelSensor> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Speed__sensors(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<fixposition_driver_ros2::msg::WheelSensor> *>(untyped_member);
  return &member[index];
}

void * get_function__Speed__sensors(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<fixposition_driver_ros2::msg::WheelSensor> *>(untyped_member);
  return &member[index];
}

void fetch_function__Speed__sensors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const fixposition_driver_ros2::msg::WheelSensor *>(
    get_const_function__Speed__sensors(untyped_member, index));
  auto & value = *reinterpret_cast<fixposition_driver_ros2::msg::WheelSensor *>(untyped_value);
  value = item;
}

void assign_function__Speed__sensors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<fixposition_driver_ros2::msg::WheelSensor *>(
    get_function__Speed__sensors(untyped_member, index));
  const auto & value = *reinterpret_cast<const fixposition_driver_ros2::msg::WheelSensor *>(untyped_value);
  item = value;
}

void resize_function__Speed__sensors(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<fixposition_driver_ros2::msg::WheelSensor> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Speed_message_member_array[1] = {
  {
    "sensors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<fixposition_driver_ros2::msg::WheelSensor>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2::msg::Speed, sensors),  // bytes offset in struct
    nullptr,  // default value
    size_function__Speed__sensors,  // size() function pointer
    get_const_function__Speed__sensors,  // get_const(index) function pointer
    get_function__Speed__sensors,  // get(index) function pointer
    fetch_function__Speed__sensors,  // fetch(index, &value) function pointer
    assign_function__Speed__sensors,  // assign(index, value) function pointer
    resize_function__Speed__sensors  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Speed_message_members = {
  "fixposition_driver_ros2::msg",  // message namespace
  "Speed",  // message name
  1,  // number of fields
  sizeof(fixposition_driver_ros2::msg::Speed),
  Speed_message_member_array,  // message members
  Speed_init_function,  // function to initialize message memory (memory has to be allocated)
  Speed_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Speed_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Speed_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace fixposition_driver_ros2


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fixposition_driver_ros2::msg::Speed>()
{
  return &::fixposition_driver_ros2::msg::rosidl_typesupport_introspection_cpp::Speed_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fixposition_driver_ros2, msg, Speed)() {
  return &::fixposition_driver_ros2::msg::rosidl_typesupport_introspection_cpp::Speed_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
