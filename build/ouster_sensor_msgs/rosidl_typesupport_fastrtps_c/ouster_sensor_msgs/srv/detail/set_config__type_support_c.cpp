// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ouster_sensor_msgs:srv/SetConfig.idl
// generated code does not contain a copyright notice
#include "ouster_sensor_msgs/srv/detail/set_config__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ouster_sensor_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ouster_sensor_msgs/srv/detail/set_config__struct.h"
#include "ouster_sensor_msgs/srv/detail/set_config__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // config_file
#include "rosidl_runtime_c/string_functions.h"  // config_file

// forward declare type support functions


using _SetConfig_Request__ros_msg_type = ouster_sensor_msgs__srv__SetConfig_Request;

static bool _SetConfig_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SetConfig_Request__ros_msg_type * ros_message = static_cast<const _SetConfig_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: config_file
  {
    const rosidl_runtime_c__String * str = &ros_message->config_file;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _SetConfig_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SetConfig_Request__ros_msg_type * ros_message = static_cast<_SetConfig_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: config_file
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->config_file.data) {
      rosidl_runtime_c__String__init(&ros_message->config_file);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->config_file,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'config_file'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ouster_sensor_msgs
size_t get_serialized_size_ouster_sensor_msgs__srv__SetConfig_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SetConfig_Request__ros_msg_type * ros_message = static_cast<const _SetConfig_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name config_file
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->config_file.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _SetConfig_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ouster_sensor_msgs__srv__SetConfig_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ouster_sensor_msgs
size_t max_serialized_size_ouster_sensor_msgs__srv__SetConfig_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: config_file
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ouster_sensor_msgs__srv__SetConfig_Request;
    is_plain =
      (
      offsetof(DataType, config_file) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SetConfig_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ouster_sensor_msgs__srv__SetConfig_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SetConfig_Request = {
  "ouster_sensor_msgs::srv",
  "SetConfig_Request",
  _SetConfig_Request__cdr_serialize,
  _SetConfig_Request__cdr_deserialize,
  _SetConfig_Request__get_serialized_size,
  _SetConfig_Request__max_serialized_size
};

static rosidl_message_type_support_t _SetConfig_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SetConfig_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ouster_sensor_msgs, srv, SetConfig_Request)() {
  return &_SetConfig_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "ouster_sensor_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "ouster_sensor_msgs/srv/detail/set_config__struct.h"
// already included above
// #include "ouster_sensor_msgs/srv/detail/set_config__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // config
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // config

// forward declare type support functions


using _SetConfig_Response__ros_msg_type = ouster_sensor_msgs__srv__SetConfig_Response;

static bool _SetConfig_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SetConfig_Response__ros_msg_type * ros_message = static_cast<const _SetConfig_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: config
  {
    const rosidl_runtime_c__String * str = &ros_message->config;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _SetConfig_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SetConfig_Response__ros_msg_type * ros_message = static_cast<_SetConfig_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: config
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->config.data) {
      rosidl_runtime_c__String__init(&ros_message->config);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->config,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'config'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ouster_sensor_msgs
size_t get_serialized_size_ouster_sensor_msgs__srv__SetConfig_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SetConfig_Response__ros_msg_type * ros_message = static_cast<const _SetConfig_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name config
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->config.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _SetConfig_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ouster_sensor_msgs__srv__SetConfig_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ouster_sensor_msgs
size_t max_serialized_size_ouster_sensor_msgs__srv__SetConfig_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: config
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ouster_sensor_msgs__srv__SetConfig_Response;
    is_plain =
      (
      offsetof(DataType, config) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SetConfig_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ouster_sensor_msgs__srv__SetConfig_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SetConfig_Response = {
  "ouster_sensor_msgs::srv",
  "SetConfig_Response",
  _SetConfig_Response__cdr_serialize,
  _SetConfig_Response__cdr_deserialize,
  _SetConfig_Response__get_serialized_size,
  _SetConfig_Response__max_serialized_size
};

static rosidl_message_type_support_t _SetConfig_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SetConfig_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ouster_sensor_msgs, srv, SetConfig_Response)() {
  return &_SetConfig_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "ouster_sensor_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ouster_sensor_msgs/srv/set_config.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t SetConfig__callbacks = {
  "ouster_sensor_msgs::srv",
  "SetConfig",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ouster_sensor_msgs, srv, SetConfig_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ouster_sensor_msgs, srv, SetConfig_Response)(),
};

static rosidl_service_type_support_t SetConfig__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &SetConfig__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ouster_sensor_msgs, srv, SetConfig)() {
  return &SetConfig__handle;
}

#if defined(__cplusplus)
}
#endif
