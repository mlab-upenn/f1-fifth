// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fixposition_driver_ros2:msg/WheelSensor.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fixposition_driver_ros2/msg/detail/wheel_sensor__rosidl_typesupport_introspection_c.h"
#include "fixposition_driver_ros2/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fixposition_driver_ros2/msg/detail/wheel_sensor__functions.h"
#include "fixposition_driver_ros2/msg/detail/wheel_sensor__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `location`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fixposition_driver_ros2__msg__WheelSensor__init(message_memory);
}

void fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_fini_function(void * message_memory)
{
  fixposition_driver_ros2__msg__WheelSensor__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__WheelSensor, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "location",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__WheelSensor, location),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__WheelSensor, vx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__WheelSensor, vy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vz",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__WheelSensor, vz),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vx_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__WheelSensor, vx_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vy_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__WheelSensor, vy_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vz_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fixposition_driver_ros2__msg__WheelSensor, vz_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_message_members = {
  "fixposition_driver_ros2__msg",  // message namespace
  "WheelSensor",  // message name
  8,  // number of fields
  sizeof(fixposition_driver_ros2__msg__WheelSensor),
  fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_message_member_array,  // message members
  fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_init_function,  // function to initialize message memory (memory has to be allocated)
  fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_message_type_support_handle = {
  0,
  &fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fixposition_driver_ros2
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fixposition_driver_ros2, msg, WheelSensor)() {
  fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_message_type_support_handle.typesupport_identifier) {
    fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fixposition_driver_ros2__msg__WheelSensor__rosidl_typesupport_introspection_c__WheelSensor_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
