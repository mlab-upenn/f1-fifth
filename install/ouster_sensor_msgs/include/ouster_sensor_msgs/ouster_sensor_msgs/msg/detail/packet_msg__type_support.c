// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ouster_sensor_msgs:msg/PacketMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ouster_sensor_msgs/msg/detail/packet_msg__rosidl_typesupport_introspection_c.h"
#include "ouster_sensor_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ouster_sensor_msgs/msg/detail/packet_msg__functions.h"
#include "ouster_sensor_msgs/msg/detail/packet_msg__struct.h"


// Include directives for member types
// Member `buf`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ouster_sensor_msgs__msg__PacketMsg__init(message_memory);
}

void ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_fini_function(void * message_memory)
{
  ouster_sensor_msgs__msg__PacketMsg__fini(message_memory);
}

size_t ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__size_function__PacketMsg__buf(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__get_const_function__PacketMsg__buf(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__get_function__PacketMsg__buf(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__fetch_function__PacketMsg__buf(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__get_const_function__PacketMsg__buf(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__assign_function__PacketMsg__buf(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__get_function__PacketMsg__buf(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__resize_function__PacketMsg__buf(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_message_member_array[1] = {
  {
    "buf",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_sensor_msgs__msg__PacketMsg, buf),  // bytes offset in struct
    NULL,  // default value
    ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__size_function__PacketMsg__buf,  // size() function pointer
    ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__get_const_function__PacketMsg__buf,  // get_const(index) function pointer
    ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__get_function__PacketMsg__buf,  // get(index) function pointer
    ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__fetch_function__PacketMsg__buf,  // fetch(index, &value) function pointer
    ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__assign_function__PacketMsg__buf,  // assign(index, value) function pointer
    ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__resize_function__PacketMsg__buf  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_message_members = {
  "ouster_sensor_msgs__msg",  // message namespace
  "PacketMsg",  // message name
  1,  // number of fields
  sizeof(ouster_sensor_msgs__msg__PacketMsg),
  ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_message_member_array,  // message members
  ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_message_type_support_handle = {
  0,
  &ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ouster_sensor_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ouster_sensor_msgs, msg, PacketMsg)() {
  if (!ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_message_type_support_handle.typesupport_identifier) {
    ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ouster_sensor_msgs__msg__PacketMsg__rosidl_typesupport_introspection_c__PacketMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
