// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ouster_msgs:msg/Metadata.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ouster_msgs/msg/detail/metadata__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ouster_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Metadata_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ouster_msgs::msg::Metadata(_init);
}

void Metadata_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ouster_msgs::msg::Metadata *>(message_memory);
  typed_message->~Metadata();
}

size_t size_function__Metadata__beam_azimuth_angles(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Metadata__beam_azimuth_angles(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__Metadata__beam_azimuth_angles(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__Metadata__beam_azimuth_angles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Metadata__beam_azimuth_angles(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Metadata__beam_azimuth_angles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Metadata__beam_azimuth_angles(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__Metadata__beam_azimuth_angles(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Metadata__beam_altitude_angles(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Metadata__beam_altitude_angles(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__Metadata__beam_altitude_angles(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__Metadata__beam_altitude_angles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Metadata__beam_altitude_angles(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Metadata__beam_altitude_angles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Metadata__beam_altitude_angles(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__Metadata__beam_altitude_angles(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Metadata__imu_to_sensor_transform(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Metadata__imu_to_sensor_transform(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__Metadata__imu_to_sensor_transform(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__Metadata__imu_to_sensor_transform(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Metadata__imu_to_sensor_transform(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Metadata__imu_to_sensor_transform(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Metadata__imu_to_sensor_transform(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__Metadata__imu_to_sensor_transform(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Metadata__lidar_to_sensor_transform(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Metadata__lidar_to_sensor_transform(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__Metadata__lidar_to_sensor_transform(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__Metadata__lidar_to_sensor_transform(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Metadata__lidar_to_sensor_transform(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Metadata__lidar_to_sensor_transform(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Metadata__lidar_to_sensor_transform(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__Metadata__lidar_to_sensor_transform(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Metadata_message_member_array[11] = {
  {
    "hostname",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs::msg::Metadata, hostname),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "lidar_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs::msg::Metadata, lidar_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "timestamp_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs::msg::Metadata, timestamp_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "beam_azimuth_angles",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs::msg::Metadata, beam_azimuth_angles),  // bytes offset in struct
    nullptr,  // default value
    size_function__Metadata__beam_azimuth_angles,  // size() function pointer
    get_const_function__Metadata__beam_azimuth_angles,  // get_const(index) function pointer
    get_function__Metadata__beam_azimuth_angles,  // get(index) function pointer
    fetch_function__Metadata__beam_azimuth_angles,  // fetch(index, &value) function pointer
    assign_function__Metadata__beam_azimuth_angles,  // assign(index, value) function pointer
    resize_function__Metadata__beam_azimuth_angles  // resize(index) function pointer
  },
  {
    "beam_altitude_angles",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs::msg::Metadata, beam_altitude_angles),  // bytes offset in struct
    nullptr,  // default value
    size_function__Metadata__beam_altitude_angles,  // size() function pointer
    get_const_function__Metadata__beam_altitude_angles,  // get_const(index) function pointer
    get_function__Metadata__beam_altitude_angles,  // get(index) function pointer
    fetch_function__Metadata__beam_altitude_angles,  // fetch(index, &value) function pointer
    assign_function__Metadata__beam_altitude_angles,  // assign(index, value) function pointer
    resize_function__Metadata__beam_altitude_angles  // resize(index) function pointer
  },
  {
    "imu_to_sensor_transform",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs::msg::Metadata, imu_to_sensor_transform),  // bytes offset in struct
    nullptr,  // default value
    size_function__Metadata__imu_to_sensor_transform,  // size() function pointer
    get_const_function__Metadata__imu_to_sensor_transform,  // get_const(index) function pointer
    get_function__Metadata__imu_to_sensor_transform,  // get(index) function pointer
    fetch_function__Metadata__imu_to_sensor_transform,  // fetch(index, &value) function pointer
    assign_function__Metadata__imu_to_sensor_transform,  // assign(index, value) function pointer
    resize_function__Metadata__imu_to_sensor_transform  // resize(index) function pointer
  },
  {
    "lidar_to_sensor_transform",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs::msg::Metadata, lidar_to_sensor_transform),  // bytes offset in struct
    nullptr,  // default value
    size_function__Metadata__lidar_to_sensor_transform,  // size() function pointer
    get_const_function__Metadata__lidar_to_sensor_transform,  // get_const(index) function pointer
    get_function__Metadata__lidar_to_sensor_transform,  // get(index) function pointer
    fetch_function__Metadata__lidar_to_sensor_transform,  // fetch(index, &value) function pointer
    assign_function__Metadata__lidar_to_sensor_transform,  // assign(index, value) function pointer
    resize_function__Metadata__lidar_to_sensor_transform  // resize(index) function pointer
  },
  {
    "serial_no",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs::msg::Metadata, serial_no),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "firmware_rev",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs::msg::Metadata, firmware_rev),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "imu_port",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs::msg::Metadata, imu_port),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "lidar_port",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs::msg::Metadata, lidar_port),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Metadata_message_members = {
  "ouster_msgs::msg",  // message namespace
  "Metadata",  // message name
  11,  // number of fields
  sizeof(ouster_msgs::msg::Metadata),
  Metadata_message_member_array,  // message members
  Metadata_init_function,  // function to initialize message memory (memory has to be allocated)
  Metadata_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Metadata_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Metadata_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ouster_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ouster_msgs::msg::Metadata>()
{
  return &::ouster_msgs::msg::rosidl_typesupport_introspection_cpp::Metadata_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ouster_msgs, msg, Metadata)() {
  return &::ouster_msgs::msg::rosidl_typesupport_introspection_cpp::Metadata_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
