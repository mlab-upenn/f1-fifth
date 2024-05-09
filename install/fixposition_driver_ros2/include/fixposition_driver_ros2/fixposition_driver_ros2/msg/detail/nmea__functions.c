// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fixposition_driver_ros2:msg/NMEA.idl
// generated code does not contain a copyright notice
#include "fixposition_driver_ros2/msg/detail/nmea__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"

bool
fixposition_driver_ros2__msg__NMEA__init(fixposition_driver_ros2__msg__NMEA * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    fixposition_driver_ros2__msg__NMEA__fini(msg);
    return false;
  }
  // latitude
  // longitude
  // altitude
  // speed
  // course
  // position_covariance
  // position_covariance_type
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    fixposition_driver_ros2__msg__NMEA__fini(msg);
    return false;
  }
  return true;
}

void
fixposition_driver_ros2__msg__NMEA__fini(fixposition_driver_ros2__msg__NMEA * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // latitude
  // longitude
  // altitude
  // speed
  // course
  // position_covariance
  // position_covariance_type
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
}

bool
fixposition_driver_ros2__msg__NMEA__are_equal(const fixposition_driver_ros2__msg__NMEA * lhs, const fixposition_driver_ros2__msg__NMEA * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // course
  if (lhs->course != rhs->course) {
    return false;
  }
  // position_covariance
  for (size_t i = 0; i < 9; ++i) {
    if (lhs->position_covariance[i] != rhs->position_covariance[i]) {
      return false;
    }
  }
  // position_covariance_type
  if (lhs->position_covariance_type != rhs->position_covariance_type) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  return true;
}

bool
fixposition_driver_ros2__msg__NMEA__copy(
  const fixposition_driver_ros2__msg__NMEA * input,
  fixposition_driver_ros2__msg__NMEA * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // latitude
  output->latitude = input->latitude;
  // longitude
  output->longitude = input->longitude;
  // altitude
  output->altitude = input->altitude;
  // speed
  output->speed = input->speed;
  // course
  output->course = input->course;
  // position_covariance
  for (size_t i = 0; i < 9; ++i) {
    output->position_covariance[i] = input->position_covariance[i];
  }
  // position_covariance_type
  output->position_covariance_type = input->position_covariance_type;
  // mode
  if (!rosidl_runtime_c__String__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  return true;
}

fixposition_driver_ros2__msg__NMEA *
fixposition_driver_ros2__msg__NMEA__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__NMEA * msg = (fixposition_driver_ros2__msg__NMEA *)allocator.allocate(sizeof(fixposition_driver_ros2__msg__NMEA), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fixposition_driver_ros2__msg__NMEA));
  bool success = fixposition_driver_ros2__msg__NMEA__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fixposition_driver_ros2__msg__NMEA__destroy(fixposition_driver_ros2__msg__NMEA * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fixposition_driver_ros2__msg__NMEA__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fixposition_driver_ros2__msg__NMEA__Sequence__init(fixposition_driver_ros2__msg__NMEA__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__NMEA * data = NULL;

  if (size) {
    data = (fixposition_driver_ros2__msg__NMEA *)allocator.zero_allocate(size, sizeof(fixposition_driver_ros2__msg__NMEA), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fixposition_driver_ros2__msg__NMEA__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fixposition_driver_ros2__msg__NMEA__fini(&data[i - 1]);
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
fixposition_driver_ros2__msg__NMEA__Sequence__fini(fixposition_driver_ros2__msg__NMEA__Sequence * array)
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
      fixposition_driver_ros2__msg__NMEA__fini(&array->data[i]);
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

fixposition_driver_ros2__msg__NMEA__Sequence *
fixposition_driver_ros2__msg__NMEA__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__NMEA__Sequence * array = (fixposition_driver_ros2__msg__NMEA__Sequence *)allocator.allocate(sizeof(fixposition_driver_ros2__msg__NMEA__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fixposition_driver_ros2__msg__NMEA__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fixposition_driver_ros2__msg__NMEA__Sequence__destroy(fixposition_driver_ros2__msg__NMEA__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fixposition_driver_ros2__msg__NMEA__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fixposition_driver_ros2__msg__NMEA__Sequence__are_equal(const fixposition_driver_ros2__msg__NMEA__Sequence * lhs, const fixposition_driver_ros2__msg__NMEA__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fixposition_driver_ros2__msg__NMEA__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fixposition_driver_ros2__msg__NMEA__Sequence__copy(
  const fixposition_driver_ros2__msg__NMEA__Sequence * input,
  fixposition_driver_ros2__msg__NMEA__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fixposition_driver_ros2__msg__NMEA);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fixposition_driver_ros2__msg__NMEA * data =
      (fixposition_driver_ros2__msg__NMEA *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fixposition_driver_ros2__msg__NMEA__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fixposition_driver_ros2__msg__NMEA__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fixposition_driver_ros2__msg__NMEA__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
