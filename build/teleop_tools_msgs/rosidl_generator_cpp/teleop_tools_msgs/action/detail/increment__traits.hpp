// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from teleop_tools_msgs:action/Increment.idl
// generated code does not contain a copyright notice

#ifndef TELEOP_TOOLS_MSGS__ACTION__DETAIL__INCREMENT__TRAITS_HPP_
#define TELEOP_TOOLS_MSGS__ACTION__DETAIL__INCREMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "teleop_tools_msgs/action/detail/increment__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace teleop_tools_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Increment_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: increment_by
  {
    if (msg.increment_by.size() == 0) {
      out << "increment_by: []";
    } else {
      out << "increment_by: [";
      size_t pending_items = msg.increment_by.size();
      for (auto item : msg.increment_by) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Increment_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: increment_by
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.increment_by.size() == 0) {
      out << "increment_by: []\n";
    } else {
      out << "increment_by:\n";
      for (auto item : msg.increment_by) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Increment_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace teleop_tools_msgs

namespace rosidl_generator_traits
{

[[deprecated("use teleop_tools_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const teleop_tools_msgs::action::Increment_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  teleop_tools_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use teleop_tools_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const teleop_tools_msgs::action::Increment_Goal & msg)
{
  return teleop_tools_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<teleop_tools_msgs::action::Increment_Goal>()
{
  return "teleop_tools_msgs::action::Increment_Goal";
}

template<>
inline const char * name<teleop_tools_msgs::action::Increment_Goal>()
{
  return "teleop_tools_msgs/action/Increment_Goal";
}

template<>
struct has_fixed_size<teleop_tools_msgs::action::Increment_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<teleop_tools_msgs::action::Increment_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<teleop_tools_msgs::action::Increment_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace teleop_tools_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Increment_Result & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Increment_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Increment_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace teleop_tools_msgs

namespace rosidl_generator_traits
{

[[deprecated("use teleop_tools_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const teleop_tools_msgs::action::Increment_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  teleop_tools_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use teleop_tools_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const teleop_tools_msgs::action::Increment_Result & msg)
{
  return teleop_tools_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<teleop_tools_msgs::action::Increment_Result>()
{
  return "teleop_tools_msgs::action::Increment_Result";
}

template<>
inline const char * name<teleop_tools_msgs::action::Increment_Result>()
{
  return "teleop_tools_msgs/action/Increment_Result";
}

template<>
struct has_fixed_size<teleop_tools_msgs::action::Increment_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<teleop_tools_msgs::action::Increment_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<teleop_tools_msgs::action::Increment_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace teleop_tools_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Increment_Feedback & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Increment_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Increment_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace teleop_tools_msgs

namespace rosidl_generator_traits
{

[[deprecated("use teleop_tools_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const teleop_tools_msgs::action::Increment_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  teleop_tools_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use teleop_tools_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const teleop_tools_msgs::action::Increment_Feedback & msg)
{
  return teleop_tools_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<teleop_tools_msgs::action::Increment_Feedback>()
{
  return "teleop_tools_msgs::action::Increment_Feedback";
}

template<>
inline const char * name<teleop_tools_msgs::action::Increment_Feedback>()
{
  return "teleop_tools_msgs/action/Increment_Feedback";
}

template<>
struct has_fixed_size<teleop_tools_msgs::action::Increment_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<teleop_tools_msgs::action::Increment_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<teleop_tools_msgs::action::Increment_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "teleop_tools_msgs/action/detail/increment__traits.hpp"

namespace teleop_tools_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Increment_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Increment_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Increment_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace teleop_tools_msgs

namespace rosidl_generator_traits
{

[[deprecated("use teleop_tools_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const teleop_tools_msgs::action::Increment_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  teleop_tools_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use teleop_tools_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const teleop_tools_msgs::action::Increment_SendGoal_Request & msg)
{
  return teleop_tools_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<teleop_tools_msgs::action::Increment_SendGoal_Request>()
{
  return "teleop_tools_msgs::action::Increment_SendGoal_Request";
}

template<>
inline const char * name<teleop_tools_msgs::action::Increment_SendGoal_Request>()
{
  return "teleop_tools_msgs/action/Increment_SendGoal_Request";
}

template<>
struct has_fixed_size<teleop_tools_msgs::action::Increment_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<teleop_tools_msgs::action::Increment_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<teleop_tools_msgs::action::Increment_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<teleop_tools_msgs::action::Increment_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<teleop_tools_msgs::action::Increment_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace teleop_tools_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Increment_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Increment_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Increment_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace teleop_tools_msgs

namespace rosidl_generator_traits
{

[[deprecated("use teleop_tools_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const teleop_tools_msgs::action::Increment_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  teleop_tools_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use teleop_tools_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const teleop_tools_msgs::action::Increment_SendGoal_Response & msg)
{
  return teleop_tools_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<teleop_tools_msgs::action::Increment_SendGoal_Response>()
{
  return "teleop_tools_msgs::action::Increment_SendGoal_Response";
}

template<>
inline const char * name<teleop_tools_msgs::action::Increment_SendGoal_Response>()
{
  return "teleop_tools_msgs/action/Increment_SendGoal_Response";
}

template<>
struct has_fixed_size<teleop_tools_msgs::action::Increment_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<teleop_tools_msgs::action::Increment_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<teleop_tools_msgs::action::Increment_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<teleop_tools_msgs::action::Increment_SendGoal>()
{
  return "teleop_tools_msgs::action::Increment_SendGoal";
}

template<>
inline const char * name<teleop_tools_msgs::action::Increment_SendGoal>()
{
  return "teleop_tools_msgs/action/Increment_SendGoal";
}

template<>
struct has_fixed_size<teleop_tools_msgs::action::Increment_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<teleop_tools_msgs::action::Increment_SendGoal_Request>::value &&
    has_fixed_size<teleop_tools_msgs::action::Increment_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<teleop_tools_msgs::action::Increment_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<teleop_tools_msgs::action::Increment_SendGoal_Request>::value &&
    has_bounded_size<teleop_tools_msgs::action::Increment_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<teleop_tools_msgs::action::Increment_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<teleop_tools_msgs::action::Increment_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<teleop_tools_msgs::action::Increment_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace teleop_tools_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Increment_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Increment_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Increment_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace teleop_tools_msgs

namespace rosidl_generator_traits
{

[[deprecated("use teleop_tools_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const teleop_tools_msgs::action::Increment_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  teleop_tools_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use teleop_tools_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const teleop_tools_msgs::action::Increment_GetResult_Request & msg)
{
  return teleop_tools_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<teleop_tools_msgs::action::Increment_GetResult_Request>()
{
  return "teleop_tools_msgs::action::Increment_GetResult_Request";
}

template<>
inline const char * name<teleop_tools_msgs::action::Increment_GetResult_Request>()
{
  return "teleop_tools_msgs/action/Increment_GetResult_Request";
}

template<>
struct has_fixed_size<teleop_tools_msgs::action::Increment_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<teleop_tools_msgs::action::Increment_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<teleop_tools_msgs::action::Increment_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "teleop_tools_msgs/action/detail/increment__traits.hpp"

namespace teleop_tools_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Increment_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Increment_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Increment_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace teleop_tools_msgs

namespace rosidl_generator_traits
{

[[deprecated("use teleop_tools_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const teleop_tools_msgs::action::Increment_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  teleop_tools_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use teleop_tools_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const teleop_tools_msgs::action::Increment_GetResult_Response & msg)
{
  return teleop_tools_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<teleop_tools_msgs::action::Increment_GetResult_Response>()
{
  return "teleop_tools_msgs::action::Increment_GetResult_Response";
}

template<>
inline const char * name<teleop_tools_msgs::action::Increment_GetResult_Response>()
{
  return "teleop_tools_msgs/action/Increment_GetResult_Response";
}

template<>
struct has_fixed_size<teleop_tools_msgs::action::Increment_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<teleop_tools_msgs::action::Increment_Result>::value> {};

template<>
struct has_bounded_size<teleop_tools_msgs::action::Increment_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<teleop_tools_msgs::action::Increment_Result>::value> {};

template<>
struct is_message<teleop_tools_msgs::action::Increment_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<teleop_tools_msgs::action::Increment_GetResult>()
{
  return "teleop_tools_msgs::action::Increment_GetResult";
}

template<>
inline const char * name<teleop_tools_msgs::action::Increment_GetResult>()
{
  return "teleop_tools_msgs/action/Increment_GetResult";
}

template<>
struct has_fixed_size<teleop_tools_msgs::action::Increment_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<teleop_tools_msgs::action::Increment_GetResult_Request>::value &&
    has_fixed_size<teleop_tools_msgs::action::Increment_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<teleop_tools_msgs::action::Increment_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<teleop_tools_msgs::action::Increment_GetResult_Request>::value &&
    has_bounded_size<teleop_tools_msgs::action::Increment_GetResult_Response>::value
  >
{
};

template<>
struct is_service<teleop_tools_msgs::action::Increment_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<teleop_tools_msgs::action::Increment_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<teleop_tools_msgs::action::Increment_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "teleop_tools_msgs/action/detail/increment__traits.hpp"

namespace teleop_tools_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Increment_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Increment_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Increment_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace teleop_tools_msgs

namespace rosidl_generator_traits
{

[[deprecated("use teleop_tools_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const teleop_tools_msgs::action::Increment_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  teleop_tools_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use teleop_tools_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const teleop_tools_msgs::action::Increment_FeedbackMessage & msg)
{
  return teleop_tools_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<teleop_tools_msgs::action::Increment_FeedbackMessage>()
{
  return "teleop_tools_msgs::action::Increment_FeedbackMessage";
}

template<>
inline const char * name<teleop_tools_msgs::action::Increment_FeedbackMessage>()
{
  return "teleop_tools_msgs/action/Increment_FeedbackMessage";
}

template<>
struct has_fixed_size<teleop_tools_msgs::action::Increment_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<teleop_tools_msgs::action::Increment_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<teleop_tools_msgs::action::Increment_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<teleop_tools_msgs::action::Increment_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<teleop_tools_msgs::action::Increment_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<teleop_tools_msgs::action::Increment>
  : std::true_type
{
};

template<>
struct is_action_goal<teleop_tools_msgs::action::Increment_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<teleop_tools_msgs::action::Increment_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<teleop_tools_msgs::action::Increment_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // TELEOP_TOOLS_MSGS__ACTION__DETAIL__INCREMENT__TRAITS_HPP_
