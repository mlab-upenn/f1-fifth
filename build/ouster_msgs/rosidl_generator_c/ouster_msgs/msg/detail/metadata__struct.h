// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ouster_msgs:msg/Metadata.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_MSGS__MSG__DETAIL__METADATA__STRUCT_H_
#define OUSTER_MSGS__MSG__DETAIL__METADATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'hostname'
// Member 'lidar_mode'
// Member 'timestamp_mode'
// Member 'serial_no'
// Member 'firmware_rev'
#include "rosidl_runtime_c/string.h"
// Member 'beam_azimuth_angles'
// Member 'beam_altitude_angles'
// Member 'imu_to_sensor_transform'
// Member 'lidar_to_sensor_transform'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Metadata in the package ouster_msgs.
typedef struct ouster_msgs__msg__Metadata
{
  rosidl_runtime_c__String hostname;
  rosidl_runtime_c__String lidar_mode;
  rosidl_runtime_c__String timestamp_mode;
  rosidl_runtime_c__double__Sequence beam_azimuth_angles;
  rosidl_runtime_c__double__Sequence beam_altitude_angles;
  rosidl_runtime_c__double__Sequence imu_to_sensor_transform;
  rosidl_runtime_c__double__Sequence lidar_to_sensor_transform;
  rosidl_runtime_c__String serial_no;
  rosidl_runtime_c__String firmware_rev;
  int8_t imu_port;
  int8_t lidar_port;
} ouster_msgs__msg__Metadata;

// Struct for a sequence of ouster_msgs__msg__Metadata.
typedef struct ouster_msgs__msg__Metadata__Sequence
{
  ouster_msgs__msg__Metadata * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ouster_msgs__msg__Metadata__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OUSTER_MSGS__MSG__DETAIL__METADATA__STRUCT_H_
