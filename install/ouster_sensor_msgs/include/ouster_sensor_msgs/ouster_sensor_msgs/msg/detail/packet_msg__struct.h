// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ouster_sensor_msgs:msg/PacketMsg.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_SENSOR_MSGS__MSG__DETAIL__PACKET_MSG__STRUCT_H_
#define OUSTER_SENSOR_MSGS__MSG__DETAIL__PACKET_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'buf'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PacketMsg in the package ouster_sensor_msgs.
typedef struct ouster_sensor_msgs__msg__PacketMsg
{
  rosidl_runtime_c__uint8__Sequence buf;
} ouster_sensor_msgs__msg__PacketMsg;

// Struct for a sequence of ouster_sensor_msgs__msg__PacketMsg.
typedef struct ouster_sensor_msgs__msg__PacketMsg__Sequence
{
  ouster_sensor_msgs__msg__PacketMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ouster_sensor_msgs__msg__PacketMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OUSTER_SENSOR_MSGS__MSG__DETAIL__PACKET_MSG__STRUCT_H_
