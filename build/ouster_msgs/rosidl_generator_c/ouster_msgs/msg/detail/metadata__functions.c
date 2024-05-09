// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ouster_msgs:msg/Metadata.idl
// generated code does not contain a copyright notice
#include "ouster_msgs/msg/detail/metadata__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


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

bool
ouster_msgs__msg__Metadata__init(ouster_msgs__msg__Metadata * msg)
{
  if (!msg) {
    return false;
  }
  // hostname
  if (!rosidl_runtime_c__String__init(&msg->hostname)) {
    ouster_msgs__msg__Metadata__fini(msg);
    return false;
  }
  // lidar_mode
  if (!rosidl_runtime_c__String__init(&msg->lidar_mode)) {
    ouster_msgs__msg__Metadata__fini(msg);
    return false;
  }
  // timestamp_mode
  if (!rosidl_runtime_c__String__init(&msg->timestamp_mode)) {
    ouster_msgs__msg__Metadata__fini(msg);
    return false;
  }
  // beam_azimuth_angles
  if (!rosidl_runtime_c__double__Sequence__init(&msg->beam_azimuth_angles, 0)) {
    ouster_msgs__msg__Metadata__fini(msg);
    return false;
  }
  // beam_altitude_angles
  if (!rosidl_runtime_c__double__Sequence__init(&msg->beam_altitude_angles, 0)) {
    ouster_msgs__msg__Metadata__fini(msg);
    return false;
  }
  // imu_to_sensor_transform
  if (!rosidl_runtime_c__double__Sequence__init(&msg->imu_to_sensor_transform, 0)) {
    ouster_msgs__msg__Metadata__fini(msg);
    return false;
  }
  // lidar_to_sensor_transform
  if (!rosidl_runtime_c__double__Sequence__init(&msg->lidar_to_sensor_transform, 0)) {
    ouster_msgs__msg__Metadata__fini(msg);
    return false;
  }
  // serial_no
  if (!rosidl_runtime_c__String__init(&msg->serial_no)) {
    ouster_msgs__msg__Metadata__fini(msg);
    return false;
  }
  // firmware_rev
  if (!rosidl_runtime_c__String__init(&msg->firmware_rev)) {
    ouster_msgs__msg__Metadata__fini(msg);
    return false;
  }
  // imu_port
  // lidar_port
  return true;
}

void
ouster_msgs__msg__Metadata__fini(ouster_msgs__msg__Metadata * msg)
{
  if (!msg) {
    return;
  }
  // hostname
  rosidl_runtime_c__String__fini(&msg->hostname);
  // lidar_mode
  rosidl_runtime_c__String__fini(&msg->lidar_mode);
  // timestamp_mode
  rosidl_runtime_c__String__fini(&msg->timestamp_mode);
  // beam_azimuth_angles
  rosidl_runtime_c__double__Sequence__fini(&msg->beam_azimuth_angles);
  // beam_altitude_angles
  rosidl_runtime_c__double__Sequence__fini(&msg->beam_altitude_angles);
  // imu_to_sensor_transform
  rosidl_runtime_c__double__Sequence__fini(&msg->imu_to_sensor_transform);
  // lidar_to_sensor_transform
  rosidl_runtime_c__double__Sequence__fini(&msg->lidar_to_sensor_transform);
  // serial_no
  rosidl_runtime_c__String__fini(&msg->serial_no);
  // firmware_rev
  rosidl_runtime_c__String__fini(&msg->firmware_rev);
  // imu_port
  // lidar_port
}

bool
ouster_msgs__msg__Metadata__are_equal(const ouster_msgs__msg__Metadata * lhs, const ouster_msgs__msg__Metadata * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // hostname
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->hostname), &(rhs->hostname)))
  {
    return false;
  }
  // lidar_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->lidar_mode), &(rhs->lidar_mode)))
  {
    return false;
  }
  // timestamp_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->timestamp_mode), &(rhs->timestamp_mode)))
  {
    return false;
  }
  // beam_azimuth_angles
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->beam_azimuth_angles), &(rhs->beam_azimuth_angles)))
  {
    return false;
  }
  // beam_altitude_angles
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->beam_altitude_angles), &(rhs->beam_altitude_angles)))
  {
    return false;
  }
  // imu_to_sensor_transform
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->imu_to_sensor_transform), &(rhs->imu_to_sensor_transform)))
  {
    return false;
  }
  // lidar_to_sensor_transform
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->lidar_to_sensor_transform), &(rhs->lidar_to_sensor_transform)))
  {
    return false;
  }
  // serial_no
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->serial_no), &(rhs->serial_no)))
  {
    return false;
  }
  // firmware_rev
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->firmware_rev), &(rhs->firmware_rev)))
  {
    return false;
  }
  // imu_port
  if (lhs->imu_port != rhs->imu_port) {
    return false;
  }
  // lidar_port
  if (lhs->lidar_port != rhs->lidar_port) {
    return false;
  }
  return true;
}

bool
ouster_msgs__msg__Metadata__copy(
  const ouster_msgs__msg__Metadata * input,
  ouster_msgs__msg__Metadata * output)
{
  if (!input || !output) {
    return false;
  }
  // hostname
  if (!rosidl_runtime_c__String__copy(
      &(input->hostname), &(output->hostname)))
  {
    return false;
  }
  // lidar_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->lidar_mode), &(output->lidar_mode)))
  {
    return false;
  }
  // timestamp_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->timestamp_mode), &(output->timestamp_mode)))
  {
    return false;
  }
  // beam_azimuth_angles
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->beam_azimuth_angles), &(output->beam_azimuth_angles)))
  {
    return false;
  }
  // beam_altitude_angles
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->beam_altitude_angles), &(output->beam_altitude_angles)))
  {
    return false;
  }
  // imu_to_sensor_transform
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->imu_to_sensor_transform), &(output->imu_to_sensor_transform)))
  {
    return false;
  }
  // lidar_to_sensor_transform
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->lidar_to_sensor_transform), &(output->lidar_to_sensor_transform)))
  {
    return false;
  }
  // serial_no
  if (!rosidl_runtime_c__String__copy(
      &(input->serial_no), &(output->serial_no)))
  {
    return false;
  }
  // firmware_rev
  if (!rosidl_runtime_c__String__copy(
      &(input->firmware_rev), &(output->firmware_rev)))
  {
    return false;
  }
  // imu_port
  output->imu_port = input->imu_port;
  // lidar_port
  output->lidar_port = input->lidar_port;
  return true;
}

ouster_msgs__msg__Metadata *
ouster_msgs__msg__Metadata__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ouster_msgs__msg__Metadata * msg = (ouster_msgs__msg__Metadata *)allocator.allocate(sizeof(ouster_msgs__msg__Metadata), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ouster_msgs__msg__Metadata));
  bool success = ouster_msgs__msg__Metadata__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ouster_msgs__msg__Metadata__destroy(ouster_msgs__msg__Metadata * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ouster_msgs__msg__Metadata__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ouster_msgs__msg__Metadata__Sequence__init(ouster_msgs__msg__Metadata__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ouster_msgs__msg__Metadata * data = NULL;

  if (size) {
    data = (ouster_msgs__msg__Metadata *)allocator.zero_allocate(size, sizeof(ouster_msgs__msg__Metadata), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ouster_msgs__msg__Metadata__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ouster_msgs__msg__Metadata__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ouster_msgs__msg__Metadata__Sequence__fini(ouster_msgs__msg__Metadata__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ouster_msgs__msg__Metadata__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ouster_msgs__msg__Metadata__Sequence *
ouster_msgs__msg__Metadata__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ouster_msgs__msg__Metadata__Sequence * array = (ouster_msgs__msg__Metadata__Sequence *)allocator.allocate(sizeof(ouster_msgs__msg__Metadata__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ouster_msgs__msg__Metadata__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ouster_msgs__msg__Metadata__Sequence__destroy(ouster_msgs__msg__Metadata__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ouster_msgs__msg__Metadata__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ouster_msgs__msg__Metadata__Sequence__are_equal(const ouster_msgs__msg__Metadata__Sequence * lhs, const ouster_msgs__msg__Metadata__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ouster_msgs__msg__Metadata__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ouster_msgs__msg__Metadata__Sequence__copy(
  const ouster_msgs__msg__Metadata__Sequence * input,
  ouster_msgs__msg__Metadata__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ouster_msgs__msg__Metadata);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ouster_msgs__msg__Metadata * data =
      (ouster_msgs__msg__Metadata *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ouster_msgs__msg__Metadata__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ouster_msgs__msg__Metadata__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ouster_msgs__msg__Metadata__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
