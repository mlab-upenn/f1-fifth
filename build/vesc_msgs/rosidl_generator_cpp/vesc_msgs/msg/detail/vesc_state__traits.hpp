// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vesc_msgs:msg/VescState.idl
// generated code does not contain a copyright notice

#ifndef VESC_MSGS__MSG__DETAIL__VESC_STATE__TRAITS_HPP_
#define VESC_MSGS__MSG__DETAIL__VESC_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vesc_msgs/msg/detail/vesc_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vesc_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VescState & msg,
  std::ostream & out)
{
  out << "{";
  // member: temp_fet
  {
    out << "temp_fet: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_fet, out);
    out << ", ";
  }

  // member: temp_motor
  {
    out << "temp_motor: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_motor, out);
    out << ", ";
  }

  // member: current_motor
  {
    out << "current_motor: ";
    rosidl_generator_traits::value_to_yaml(msg.current_motor, out);
    out << ", ";
  }

  // member: current_input
  {
    out << "current_input: ";
    rosidl_generator_traits::value_to_yaml(msg.current_input, out);
    out << ", ";
  }

  // member: avg_id
  {
    out << "avg_id: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_id, out);
    out << ", ";
  }

  // member: avg_iq
  {
    out << "avg_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_iq, out);
    out << ", ";
  }

  // member: duty_cycle
  {
    out << "duty_cycle: ";
    rosidl_generator_traits::value_to_yaml(msg.duty_cycle, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: voltage_input
  {
    out << "voltage_input: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_input, out);
    out << ", ";
  }

  // member: charge_drawn
  {
    out << "charge_drawn: ";
    rosidl_generator_traits::value_to_yaml(msg.charge_drawn, out);
    out << ", ";
  }

  // member: charge_regen
  {
    out << "charge_regen: ";
    rosidl_generator_traits::value_to_yaml(msg.charge_regen, out);
    out << ", ";
  }

  // member: energy_drawn
  {
    out << "energy_drawn: ";
    rosidl_generator_traits::value_to_yaml(msg.energy_drawn, out);
    out << ", ";
  }

  // member: energy_regen
  {
    out << "energy_regen: ";
    rosidl_generator_traits::value_to_yaml(msg.energy_regen, out);
    out << ", ";
  }

  // member: displacement
  {
    out << "displacement: ";
    rosidl_generator_traits::value_to_yaml(msg.displacement, out);
    out << ", ";
  }

  // member: distance_traveled
  {
    out << "distance_traveled: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_traveled, out);
    out << ", ";
  }

  // member: fault_code
  {
    out << "fault_code: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_code, out);
    out << ", ";
  }

  // member: pid_pos_now
  {
    out << "pid_pos_now: ";
    rosidl_generator_traits::value_to_yaml(msg.pid_pos_now, out);
    out << ", ";
  }

  // member: controller_id
  {
    out << "controller_id: ";
    rosidl_generator_traits::value_to_yaml(msg.controller_id, out);
    out << ", ";
  }

  // member: ntc_temp_mos1
  {
    out << "ntc_temp_mos1: ";
    rosidl_generator_traits::value_to_yaml(msg.ntc_temp_mos1, out);
    out << ", ";
  }

  // member: ntc_temp_mos2
  {
    out << "ntc_temp_mos2: ";
    rosidl_generator_traits::value_to_yaml(msg.ntc_temp_mos2, out);
    out << ", ";
  }

  // member: ntc_temp_mos3
  {
    out << "ntc_temp_mos3: ";
    rosidl_generator_traits::value_to_yaml(msg.ntc_temp_mos3, out);
    out << ", ";
  }

  // member: avg_vd
  {
    out << "avg_vd: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_vd, out);
    out << ", ";
  }

  // member: avg_vq
  {
    out << "avg_vq: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_vq, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VescState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: temp_fet
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp_fet: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_fet, out);
    out << "\n";
  }

  // member: temp_motor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp_motor: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_motor, out);
    out << "\n";
  }

  // member: current_motor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_motor: ";
    rosidl_generator_traits::value_to_yaml(msg.current_motor, out);
    out << "\n";
  }

  // member: current_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_input: ";
    rosidl_generator_traits::value_to_yaml(msg.current_input, out);
    out << "\n";
  }

  // member: avg_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "avg_id: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_id, out);
    out << "\n";
  }

  // member: avg_iq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "avg_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_iq, out);
    out << "\n";
  }

  // member: duty_cycle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duty_cycle: ";
    rosidl_generator_traits::value_to_yaml(msg.duty_cycle, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: voltage_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage_input: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_input, out);
    out << "\n";
  }

  // member: charge_drawn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charge_drawn: ";
    rosidl_generator_traits::value_to_yaml(msg.charge_drawn, out);
    out << "\n";
  }

  // member: charge_regen
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charge_regen: ";
    rosidl_generator_traits::value_to_yaml(msg.charge_regen, out);
    out << "\n";
  }

  // member: energy_drawn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "energy_drawn: ";
    rosidl_generator_traits::value_to_yaml(msg.energy_drawn, out);
    out << "\n";
  }

  // member: energy_regen
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "energy_regen: ";
    rosidl_generator_traits::value_to_yaml(msg.energy_regen, out);
    out << "\n";
  }

  // member: displacement
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "displacement: ";
    rosidl_generator_traits::value_to_yaml(msg.displacement, out);
    out << "\n";
  }

  // member: distance_traveled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_traveled: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_traveled, out);
    out << "\n";
  }

  // member: fault_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fault_code: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_code, out);
    out << "\n";
  }

  // member: pid_pos_now
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pid_pos_now: ";
    rosidl_generator_traits::value_to_yaml(msg.pid_pos_now, out);
    out << "\n";
  }

  // member: controller_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "controller_id: ";
    rosidl_generator_traits::value_to_yaml(msg.controller_id, out);
    out << "\n";
  }

  // member: ntc_temp_mos1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ntc_temp_mos1: ";
    rosidl_generator_traits::value_to_yaml(msg.ntc_temp_mos1, out);
    out << "\n";
  }

  // member: ntc_temp_mos2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ntc_temp_mos2: ";
    rosidl_generator_traits::value_to_yaml(msg.ntc_temp_mos2, out);
    out << "\n";
  }

  // member: ntc_temp_mos3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ntc_temp_mos3: ";
    rosidl_generator_traits::value_to_yaml(msg.ntc_temp_mos3, out);
    out << "\n";
  }

  // member: avg_vd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "avg_vd: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_vd, out);
    out << "\n";
  }

  // member: avg_vq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "avg_vq: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_vq, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VescState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace vesc_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vesc_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vesc_msgs::msg::VescState & msg,
  std::ostream & out, size_t indentation = 0)
{
  vesc_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vesc_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vesc_msgs::msg::VescState & msg)
{
  return vesc_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vesc_msgs::msg::VescState>()
{
  return "vesc_msgs::msg::VescState";
}

template<>
inline const char * name<vesc_msgs::msg::VescState>()
{
  return "vesc_msgs/msg/VescState";
}

template<>
struct has_fixed_size<vesc_msgs::msg::VescState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vesc_msgs::msg::VescState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vesc_msgs::msg::VescState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VESC_MSGS__MSG__DETAIL__VESC_STATE__TRAITS_HPP_
