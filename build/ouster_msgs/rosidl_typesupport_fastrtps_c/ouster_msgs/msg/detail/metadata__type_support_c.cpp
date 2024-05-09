// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ouster_msgs:msg/Metadata.idl
// generated code does not contain a copyright notice
#include "ouster_msgs/msg/detail/metadata__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ouster_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ouster_msgs/msg/detail/metadata__struct.h"
#include "ouster_msgs/msg/detail/metadata__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // beam_altitude_angles, beam_azimuth_angles, imu_to_sensor_transform, lidar_to_sensor_transform
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // beam_altitude_angles, beam_azimuth_angles, imu_to_sensor_transform, lidar_to_sensor_transform
#include "rosidl_runtime_c/string.h"  // firmware_rev, hostname, lidar_mode, serial_no, timestamp_mode
#include "rosidl_runtime_c/string_functions.h"  // firmware_rev, hostname, lidar_mode, serial_no, timestamp_mode

// forward declare type support functions


using _Metadata__ros_msg_type = ouster_msgs__msg__Metadata;

static bool _Metadata__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Metadata__ros_msg_type * ros_message = static_cast<const _Metadata__ros_msg_type *>(untyped_ros_message);
  // Field name: hostname
  {
    const rosidl_runtime_c__String * str = &ros_message->hostname;
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

  // Field name: lidar_mode
  {
    const rosidl_runtime_c__String * str = &ros_message->lidar_mode;
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

  // Field name: timestamp_mode
  {
    const rosidl_runtime_c__String * str = &ros_message->timestamp_mode;
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

  // Field name: beam_azimuth_angles
  {
    size_t size = ros_message->beam_azimuth_angles.size;
    auto array_ptr = ros_message->beam_azimuth_angles.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: beam_altitude_angles
  {
    size_t size = ros_message->beam_altitude_angles.size;
    auto array_ptr = ros_message->beam_altitude_angles.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: imu_to_sensor_transform
  {
    size_t size = ros_message->imu_to_sensor_transform.size;
    auto array_ptr = ros_message->imu_to_sensor_transform.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: lidar_to_sensor_transform
  {
    size_t size = ros_message->lidar_to_sensor_transform.size;
    auto array_ptr = ros_message->lidar_to_sensor_transform.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: serial_no
  {
    const rosidl_runtime_c__String * str = &ros_message->serial_no;
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

  // Field name: firmware_rev
  {
    const rosidl_runtime_c__String * str = &ros_message->firmware_rev;
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

  // Field name: imu_port
  {
    cdr << ros_message->imu_port;
  }

  // Field name: lidar_port
  {
    cdr << ros_message->lidar_port;
  }

  return true;
}

static bool _Metadata__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Metadata__ros_msg_type * ros_message = static_cast<_Metadata__ros_msg_type *>(untyped_ros_message);
  // Field name: hostname
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->hostname.data) {
      rosidl_runtime_c__String__init(&ros_message->hostname);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->hostname,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'hostname'\n");
      return false;
    }
  }

  // Field name: lidar_mode
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->lidar_mode.data) {
      rosidl_runtime_c__String__init(&ros_message->lidar_mode);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->lidar_mode,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'lidar_mode'\n");
      return false;
    }
  }

  // Field name: timestamp_mode
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->timestamp_mode.data) {
      rosidl_runtime_c__String__init(&ros_message->timestamp_mode);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->timestamp_mode,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'timestamp_mode'\n");
      return false;
    }
  }

  // Field name: beam_azimuth_angles
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->beam_azimuth_angles.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->beam_azimuth_angles);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->beam_azimuth_angles, size)) {
      fprintf(stderr, "failed to create array for field 'beam_azimuth_angles'");
      return false;
    }
    auto array_ptr = ros_message->beam_azimuth_angles.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: beam_altitude_angles
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->beam_altitude_angles.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->beam_altitude_angles);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->beam_altitude_angles, size)) {
      fprintf(stderr, "failed to create array for field 'beam_altitude_angles'");
      return false;
    }
    auto array_ptr = ros_message->beam_altitude_angles.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: imu_to_sensor_transform
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->imu_to_sensor_transform.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->imu_to_sensor_transform);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->imu_to_sensor_transform, size)) {
      fprintf(stderr, "failed to create array for field 'imu_to_sensor_transform'");
      return false;
    }
    auto array_ptr = ros_message->imu_to_sensor_transform.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: lidar_to_sensor_transform
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->lidar_to_sensor_transform.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->lidar_to_sensor_transform);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->lidar_to_sensor_transform, size)) {
      fprintf(stderr, "failed to create array for field 'lidar_to_sensor_transform'");
      return false;
    }
    auto array_ptr = ros_message->lidar_to_sensor_transform.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: serial_no
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->serial_no.data) {
      rosidl_runtime_c__String__init(&ros_message->serial_no);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->serial_no,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'serial_no'\n");
      return false;
    }
  }

  // Field name: firmware_rev
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->firmware_rev.data) {
      rosidl_runtime_c__String__init(&ros_message->firmware_rev);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->firmware_rev,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'firmware_rev'\n");
      return false;
    }
  }

  // Field name: imu_port
  {
    cdr >> ros_message->imu_port;
  }

  // Field name: lidar_port
  {
    cdr >> ros_message->lidar_port;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ouster_msgs
size_t get_serialized_size_ouster_msgs__msg__Metadata(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Metadata__ros_msg_type * ros_message = static_cast<const _Metadata__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name hostname
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->hostname.size + 1);
  // field.name lidar_mode
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->lidar_mode.size + 1);
  // field.name timestamp_mode
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->timestamp_mode.size + 1);
  // field.name beam_azimuth_angles
  {
    size_t array_size = ros_message->beam_azimuth_angles.size;
    auto array_ptr = ros_message->beam_azimuth_angles.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name beam_altitude_angles
  {
    size_t array_size = ros_message->beam_altitude_angles.size;
    auto array_ptr = ros_message->beam_altitude_angles.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name imu_to_sensor_transform
  {
    size_t array_size = ros_message->imu_to_sensor_transform.size;
    auto array_ptr = ros_message->imu_to_sensor_transform.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lidar_to_sensor_transform
  {
    size_t array_size = ros_message->lidar_to_sensor_transform.size;
    auto array_ptr = ros_message->lidar_to_sensor_transform.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name serial_no
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->serial_no.size + 1);
  // field.name firmware_rev
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->firmware_rev.size + 1);
  // field.name imu_port
  {
    size_t item_size = sizeof(ros_message->imu_port);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lidar_port
  {
    size_t item_size = sizeof(ros_message->lidar_port);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Metadata__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ouster_msgs__msg__Metadata(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ouster_msgs
size_t max_serialized_size_ouster_msgs__msg__Metadata(
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

  // member: hostname
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
  // member: lidar_mode
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
  // member: timestamp_mode
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
  // member: beam_azimuth_angles
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: beam_altitude_angles
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: imu_to_sensor_transform
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: lidar_to_sensor_transform
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: serial_no
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
  // member: firmware_rev
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
  // member: imu_port
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: lidar_port
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ouster_msgs__msg__Metadata;
    is_plain =
      (
      offsetof(DataType, lidar_port) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Metadata__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ouster_msgs__msg__Metadata(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Metadata = {
  "ouster_msgs::msg",
  "Metadata",
  _Metadata__cdr_serialize,
  _Metadata__cdr_deserialize,
  _Metadata__get_serialized_size,
  _Metadata__max_serialized_size
};

static rosidl_message_type_support_t _Metadata__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Metadata,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ouster_msgs, msg, Metadata)() {
  return &_Metadata__type_support;
}

#if defined(__cplusplus)
}
#endif
