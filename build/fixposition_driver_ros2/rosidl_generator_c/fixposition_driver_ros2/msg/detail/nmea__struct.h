// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fixposition_driver_ros2:msg/NMEA.idl
// generated code does not contain a copyright notice

#ifndef FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__STRUCT_H_
#define FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'COVARIANCE_TYPE_UNKNOWN'.
/**
  * If the covariance of the fix is known, fill it in completely. If the
  * GPS receiver provides the variance of each measurement, put them
  * along the diagonal. If only Dilution of Precision is available,
  * estimate an approximate covariance from that.
 */
enum
{
  fixposition_driver_ros2__msg__NMEA__COVARIANCE_TYPE_UNKNOWN = 0
};

/// Constant 'COVARIANCE_TYPE_APPROXIMATED'.
enum
{
  fixposition_driver_ros2__msg__NMEA__COVARIANCE_TYPE_APPROXIMATED = 1
};

/// Constant 'COVARIANCE_TYPE_DIAGONAL_KNOWN'.
enum
{
  fixposition_driver_ros2__msg__NMEA__COVARIANCE_TYPE_DIAGONAL_KNOWN = 2
};

/// Constant 'COVARIANCE_TYPE_KNOWN'.
enum
{
  fixposition_driver_ros2__msg__NMEA__COVARIANCE_TYPE_KNOWN = 3
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/NMEA in the package fixposition_driver_ros2.
/**
  *    Copyright (c) 2023
  *    Fixposition AG
  *
  * Fixposition NMEA Message
 */
typedef struct fixposition_driver_ros2__msg__NMEA
{
  /// Navigation Satellite fix for any Global Navigation Satellite System
  ///
  /// Specified using the WGS 84 reference ellipsoid
  /// header.stamp specifies the ROS time for this measurement (the
  ///        corresponding satellite time may be reported using the
  ///        sensor_msgs/TimeReference message).
  ///
  /// header.frame_id is the frame of reference reported by the satellite
  ///        receiver, usually the location of the antenna.  This is a
  ///        Euclidean frame relative to the vehicle, not a reference
  ///        ellipsoid.
  std_msgs__msg__Header header;
  /// Latitude. Positive is north of equator; negative is south.
  double latitude;
  /// Longitude. Positive is east of prime meridian; negative is west.
  double longitude;
  /// Altitude. Positive is above the WGS 84 ellipsoid.
  double altitude;
  /// Speed over ground
  double speed;
  /// Course over ground
  double course;
  /// Position covariance defined relative to a tangential plane
  /// through the reported position. The components are East, North, and
  /// Up (ENU), in row-major order.
  ///
  /// Beware: this coordinate system exhibits singularities at the poles.
  double position_covariance[9];
  uint8_t position_covariance_type;
  /// Positioning system mode indicator, R (RTK fixed), F (RTK float), A (no RTK), E, N
  rosidl_runtime_c__String mode;
} fixposition_driver_ros2__msg__NMEA;

// Struct for a sequence of fixposition_driver_ros2__msg__NMEA.
typedef struct fixposition_driver_ros2__msg__NMEA__Sequence
{
  fixposition_driver_ros2__msg__NMEA * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fixposition_driver_ros2__msg__NMEA__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FIXPOSITION_DRIVER_ROS2__MSG__DETAIL__NMEA__STRUCT_H_
