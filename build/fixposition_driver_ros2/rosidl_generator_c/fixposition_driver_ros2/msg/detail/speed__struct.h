// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fixposition_driver_ros2:msg/Speed.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__SPEED__STRUCT_H_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__SPEED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'sensors'
#include "fixposition_driver_ros2/msg/detail/wheel_sensor__struct.h"

/// Struct defined in msg/Speed in the package fixposition_driver_ros2.
/**
  *    Copyright (c) 2023
  *    Fixposition AG
  *
  * Wheel speed input to Fixposition ROS Driver
 */
typedef struct fixposition_driver_ros2__msg__Speed
{
  /// Velocity values for one or several WheelSensors
  fixposition_driver_ros2__msg__WheelSensor__Sequence sensors;
} fixposition_driver_ros2__msg__Speed;

// Struct for a sequence of fixposition_driver_ros2__msg__Speed.
typedef struct fixposition_driver_ros2__msg__Speed__Sequence
{
  fixposition_driver_ros2__msg__Speed * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fixposition_driver_ros2__msg__Speed__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__SPEED__STRUCT_H_
