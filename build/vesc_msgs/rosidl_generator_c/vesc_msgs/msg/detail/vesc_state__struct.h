// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vesc_msgs:msg/VescState.idl
// generated code does not contain a copyright notice

#ifndef VESC_MSGS__MSG__DETAIL__VESC_STATE__STRUCT_H_
#define VESC_MSGS__MSG__DETAIL__VESC_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'FAULT_CODE_NONE'.
/**
  * fault codes
 */
enum
{
  vesc_msgs__msg__VescState__FAULT_CODE_NONE = 0l
};

/// Constant 'FAULT_CODE_OVER_VOLTAGE'.
enum
{
  vesc_msgs__msg__VescState__FAULT_CODE_OVER_VOLTAGE = 1l
};

/// Constant 'FAULT_CODE_UNDER_VOLTAGE'.
enum
{
  vesc_msgs__msg__VescState__FAULT_CODE_UNDER_VOLTAGE = 2l
};

/// Constant 'FAULT_CODE_DRV8302'.
enum
{
  vesc_msgs__msg__VescState__FAULT_CODE_DRV8302 = 3l
};

/// Constant 'FAULT_CODE_ABS_OVER_CURRENT'.
enum
{
  vesc_msgs__msg__VescState__FAULT_CODE_ABS_OVER_CURRENT = 4l
};

/// Constant 'FAULT_CODE_OVER_TEMP_FET'.
enum
{
  vesc_msgs__msg__VescState__FAULT_CODE_OVER_TEMP_FET = 5l
};

/// Constant 'FAULT_CODE_OVER_TEMP_MOTOR'.
enum
{
  vesc_msgs__msg__VescState__FAULT_CODE_OVER_TEMP_MOTOR = 6l
};

/// Struct defined in msg/VescState in the package vesc_msgs.
/**
  * Vedder VESC open source motor controller state (telemetry)
 */
typedef struct vesc_msgs__msg__VescState
{
  /// follow the bledc firwmare: commands.c
  /// fet temperature
  double temp_fet;
  /// motor temperature
  double temp_motor;
  /// motor current (ampere) avg_motor_current
  double current_motor;
  /// input current (ampere) avg_input_current
  double current_input;
  double avg_id;
  double avg_iq;
  /// duty cycle (0 to 1) duty_cycle_now
  double duty_cycle;
  /// motor electrical speed (revolutions per minute) rpm
  double speed;
  /// input voltage (volt)
  double voltage_input;
  /// electric charge drawn from input (ampere-hours)
  double charge_drawn;
  /// electric charge regenerated to input (ampere-hour) amp_hours_charged
  double charge_regen;
  /// energy drawn from input (watt-hour)
  double energy_drawn;
  /// energy regenerated to input (watt_hours_charged)
  double energy_regen;
  /// net tachometer (counts) tachometer
  int32_t displacement;
  /// total tachnometer (counts) tachometer_abs
  int32_t distance_traveled;
  int32_t fault_code;
  double pid_pos_now;
  int32_t controller_id;
  double ntc_temp_mos1;
  double ntc_temp_mos2;
  double ntc_temp_mos3;
  double avg_vd;
  double avg_vq;
} vesc_msgs__msg__VescState;

// Struct for a sequence of vesc_msgs__msg__VescState.
typedef struct vesc_msgs__msg__VescState__Sequence
{
  vesc_msgs__msg__VescState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vesc_msgs__msg__VescState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VESC_MSGS__MSG__DETAIL__VESC_STATE__STRUCT_H_
