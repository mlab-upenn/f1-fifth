// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ouster_sensor_msgs:msg/PacketMsg.idl
// generated code does not contain a copyright notice
#include "ouster_sensor_msgs/msg/detail/packet_msg__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ouster_sensor_msgs/msg/detail/packet_msg__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ouster_sensor_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ouster_sensor_msgs
cdr_serialize(
  const ouster_sensor_msgs::msg::PacketMsg & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: buf
  {
    cdr << ros_message.buf;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ouster_sensor_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ouster_sensor_msgs::msg::PacketMsg & ros_message)
{
  // Member: buf
  {
    cdr >> ros_message.buf;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ouster_sensor_msgs
get_serialized_size(
  const ouster_sensor_msgs::msg::PacketMsg & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: buf
  {
    size_t array_size = ros_message.buf.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.buf[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ouster_sensor_msgs
max_serialized_size_PacketMsg(
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


  // Member: buf
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ouster_sensor_msgs::msg::PacketMsg;
    is_plain =
      (
      offsetof(DataType, buf) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _PacketMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ouster_sensor_msgs::msg::PacketMsg *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PacketMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ouster_sensor_msgs::msg::PacketMsg *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PacketMsg__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ouster_sensor_msgs::msg::PacketMsg *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PacketMsg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PacketMsg(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PacketMsg__callbacks = {
  "ouster_sensor_msgs::msg",
  "PacketMsg",
  _PacketMsg__cdr_serialize,
  _PacketMsg__cdr_deserialize,
  _PacketMsg__get_serialized_size,
  _PacketMsg__max_serialized_size
};

static rosidl_message_type_support_t _PacketMsg__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PacketMsg__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ouster_sensor_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ouster_sensor_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<ouster_sensor_msgs::msg::PacketMsg>()
{
  return &ouster_sensor_msgs::msg::typesupport_fastrtps_cpp::_PacketMsg__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ouster_sensor_msgs, msg, PacketMsg)() {
  return &ouster_sensor_msgs::msg::typesupport_fastrtps_cpp::_PacketMsg__handle;
}

#ifdef __cplusplus
}
#endif
