// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fixposition_driver_ros2:msg/WheelSensor.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__STRUCT_H_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'location'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/WheelSensor in the package fixposition_driver_ros2.
/**
  *    Copyright (c) 2023
  *    Fixposition AG
  *
  * Fixposition WheelSensor Message
  *
  * Standard metadata
 */
typedef struct fixposition_driver_ros2__msg__WheelSensor
{
  std_msgs__msg__Header header;
  /// Location of the wheelspeed measurement (one of: RC, FR, FL, RR, RL)
  rosidl_runtime_c__String location;
  /// Velocity values in as integer 32bit
  int32_t vx;
  int32_t vy;
  int32_t vz;
  /// Velocity validity
  bool vx_valid;
  bool vy_valid;
  bool vz_valid;
} fixposition_driver_ros2__msg__WheelSensor;

// Struct for a sequence of fixposition_driver_ros2__msg__WheelSensor.
typedef struct fixposition_driver_ros2__msg__WheelSensor__Sequence
{
  fixposition_driver_ros2__msg__WheelSensor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fixposition_driver_ros2__msg__WheelSensor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__WHEEL_SENSOR__STRUCT_H_
