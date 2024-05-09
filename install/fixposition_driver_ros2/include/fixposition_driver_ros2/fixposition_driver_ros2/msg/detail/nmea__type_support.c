// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fixposition_driver_ros2:msg/NMEA.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fixposition_driver_ros2/msg/detail/nmea__rosidl_typesupport_introspection_c.h"
#include "fixposition_driver_ros2/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fixposition_driver_ros2/msg/detail/nmea__functions.h"
#include "fixposition_driver_ros2/msg/detail/nmea__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fixposition_driver_ros2__msg__NMEA__init(message_memory);
}

void fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_fini_function(void * message_memory)
{
  fixposition_driver_ros2__msg__NMEA__fini(message_memory);
}

size_t fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__size_function__NMEA__position_covariance(
  const void * untyped_member)
{
  (void)untyped_member;
  return 9;
}

const void * fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__get_const_function__NMEA__position_covariance(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__get_function__NMEA__position_covariance(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__fetch_function__NMEA__position_covariance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__get_const_function__NMEA__position_covariance(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__assign_function__NMEA__position_covariance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__get_function__NMEA__position_covariance(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_message_member_array[9] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__NMEA, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "latitude",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__NMEA, latitude),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "longitude",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__NMEA, longitude),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "altitude",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__NMEA, altitude),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__NMEA, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "course",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__NMEA, course),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position_covariance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    9,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__NMEA, position_covariance),  // bytes offset in struct
    NULL,  // default value
    fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__size_function__NMEA__position_covariance,  // size() function pointer
    fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__get_const_function__NMEA__position_covariance,  // get_const(index) function pointer
    fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__get_function__NMEA__position_covariance,  // get(index) function pointer
    fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__fetch_function__NMEA__position_covariance,  // fetch(index, &value) function pointer
    fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__assign_function__NMEA__position_covariance,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position_covariance_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__NMEA, position_covariance_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__NMEA, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_message_members = {
  "fixposition_driver_ros2__msg",  // message namespace
  "NMEA",  // message name
  9,  // number of fields
  sizeof(fixposition_driver_ros2__msg__NMEA),
  fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_message_member_array,  // message members
  fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_init_function,  // function to initialize message memory (memory has to be allocated)
  fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_message_type_support_handle = {
  0,
  &fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fixposition_driver_ros2
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fixposition_driver_ros2, msg, NMEA)() {
  fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_message_type_support_handle.typesupport_identifier) {
    fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fixposition_driver_ros2__msg__NMEA__rosidl_typesupport_introspection_c__NMEA_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
