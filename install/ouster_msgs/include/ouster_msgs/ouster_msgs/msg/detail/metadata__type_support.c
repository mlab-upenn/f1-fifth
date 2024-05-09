// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ouster_msgs:msg/Metadata.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ouster_msgs/msg/detail/metadata__rosidl_typesupport_introspection_c.h"
#include "ouster_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ouster_msgs/msg/detail/metadata__functions.h"
#include "ouster_msgs/msg/detail/metadata__struct.h"


// Include directives for member types
// Member `hostname`
// Member `lidar_mode`
// Member `timestamp_mode`
// Member `serial_no`
// Member `firmware_rev`
#include "rosidl_runtime_c/string_functions.h"
// Member `beam_azimuth_angles`
// Member `beam_altitude_angles`
// Member `imu_to_sensor_transform`
// Member `lidar_to_sensor_transform`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ouster_msgs__msg__Metadata__init(message_memory);
}

void ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_fini_function(void * message_memory)
{
  ouster_msgs__msg__Metadata__fini(message_memory);
}

size_t ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__size_function__Metadata__beam_azimuth_angles(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__beam_azimuth_angles(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__beam_azimuth_angles(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__fetch_function__Metadata__beam_azimuth_angles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__beam_azimuth_angles(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__assign_function__Metadata__beam_azimuth_angles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__beam_azimuth_angles(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__resize_function__Metadata__beam_azimuth_angles(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__size_function__Metadata__beam_altitude_angles(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__beam_altitude_angles(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__beam_altitude_angles(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__fetch_function__Metadata__beam_altitude_angles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__beam_altitude_angles(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__assign_function__Metadata__beam_altitude_angles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__beam_altitude_angles(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__resize_function__Metadata__beam_altitude_angles(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__size_function__Metadata__imu_to_sensor_transform(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__imu_to_sensor_transform(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__imu_to_sensor_transform(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__fetch_function__Metadata__imu_to_sensor_transform(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__imu_to_sensor_transform(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__assign_function__Metadata__imu_to_sensor_transform(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__imu_to_sensor_transform(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__resize_function__Metadata__imu_to_sensor_transform(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__size_function__Metadata__lidar_to_sensor_transform(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__lidar_to_sensor_transform(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__lidar_to_sensor_transform(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__fetch_function__Metadata__lidar_to_sensor_transform(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__lidar_to_sensor_transform(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__assign_function__Metadata__lidar_to_sensor_transform(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__lidar_to_sensor_transform(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__resize_function__Metadata__lidar_to_sensor_transform(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_message_member_array[11] = {
  {
    "hostname",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs__msg__Metadata, hostname),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lidar_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs__msg__Metadata, lidar_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timestamp_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs__msg__Metadata, timestamp_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "beam_azimuth_angles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs__msg__Metadata, beam_azimuth_angles),  // bytes offset in struct
    NULL,  // default value
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__size_function__Metadata__beam_azimuth_angles,  // size() function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__beam_azimuth_angles,  // get_const(index) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__beam_azimuth_angles,  // get(index) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__fetch_function__Metadata__beam_azimuth_angles,  // fetch(index, &value) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__assign_function__Metadata__beam_azimuth_angles,  // assign(index, value) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__resize_function__Metadata__beam_azimuth_angles  // resize(index) function pointer
  },
  {
    "beam_altitude_angles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs__msg__Metadata, beam_altitude_angles),  // bytes offset in struct
    NULL,  // default value
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__size_function__Metadata__beam_altitude_angles,  // size() function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__beam_altitude_angles,  // get_const(index) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__beam_altitude_angles,  // get(index) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__fetch_function__Metadata__beam_altitude_angles,  // fetch(index, &value) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__assign_function__Metadata__beam_altitude_angles,  // assign(index, value) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__resize_function__Metadata__beam_altitude_angles  // resize(index) function pointer
  },
  {
    "imu_to_sensor_transform",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs__msg__Metadata, imu_to_sensor_transform),  // bytes offset in struct
    NULL,  // default value
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__size_function__Metadata__imu_to_sensor_transform,  // size() function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__imu_to_sensor_transform,  // get_const(index) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__imu_to_sensor_transform,  // get(index) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__fetch_function__Metadata__imu_to_sensor_transform,  // fetch(index, &value) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__assign_function__Metadata__imu_to_sensor_transform,  // assign(index, value) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__resize_function__Metadata__imu_to_sensor_transform  // resize(index) function pointer
  },
  {
    "lidar_to_sensor_transform",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs__msg__Metadata, lidar_to_sensor_transform),  // bytes offset in struct
    NULL,  // default value
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__size_function__Metadata__lidar_to_sensor_transform,  // size() function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_const_function__Metadata__lidar_to_sensor_transform,  // get_const(index) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__get_function__Metadata__lidar_to_sensor_transform,  // get(index) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__fetch_function__Metadata__lidar_to_sensor_transform,  // fetch(index, &value) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__assign_function__Metadata__lidar_to_sensor_transform,  // assign(index, value) function pointer
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__resize_function__Metadata__lidar_to_sensor_transform  // resize(index) function pointer
  },
  {
    "serial_no",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs__msg__Metadata, serial_no),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "firmware_rev",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs__msg__Metadata, firmware_rev),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "imu_port",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs__msg__Metadata, imu_port),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lidar_port",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ouster_msgs__msg__Metadata, lidar_port),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_message_members = {
  "ouster_msgs__msg",  // message namespace
  "Metadata",  // message name
  11,  // number of fields
  sizeof(ouster_msgs__msg__Metadata),
  ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_message_member_array,  // message members
  ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_init_function,  // function to initialize message memory (memory has to be allocated)
  ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_message_type_support_handle = {
  0,
  &ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ouster_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ouster_msgs, msg, Metadata)() {
  if (!ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_message_type_support_handle.typesupport_identifier) {
    ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ouster_msgs__msg__Metadata__rosidl_typesupport_introspection_c__Metadata_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
