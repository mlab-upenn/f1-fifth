// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fixposition_driver_ros2:msg/Speed.idl
// generated code does not contain a copyright notice
#include "fixposition_driver_ros2/msg/detail/speed__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sensors`
#include "fixposition_driver_ros2/msg/detail/wheel_sensor__functions.h"

bool
fixposition_driver_ros2__msg__Speed__init(fixposition_driver_ros2__msg__Speed * msg)
{
  if (!msg) {
    return false;
  }
  // sensors
  if (!fixposition_driver_ros2__msg__WheelSensor__Sequence__init(&msg->sensors, 0)) {
    fixposition_driver_ros2__msg__Speed__fini(msg);
    return false;
  }
  return true;
}

void
fixposition_driver_ros2__msg__Speed__fini(fixposition_driver_ros2__msg__Speed * msg)
{
  if (!msg) {
    return;
  }
  // sensors
  fixposition_driver_ros2__msg__WheelSensor__Sequence__fini(&msg->sensors);
}

bool
fixposition_driver_ros2__msg__Speed__are_equal(const fixposition_driver_ros2__msg__Speed * lhs, const fixposition_driver_ros2__msg__Speed * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sensors
  if (!fixposition_driver_ros2__msg__WheelSensor__Sequence__are_equal(
      &(lhs->sensors), &(rhs->sensors)))
  {
    return false;
  }
  return true;
}

bool
fixposition_driver_ros2__msg__Speed__copy(
  const fixposition_driver_ros2__msg__Speed * input,
  fixposition_driver_ros2__msg__Speed * output)
{
  if (!input || !output) {
    return false;
  }
  // sensors
  if (!fixposition_driver_ros2__msg__WheelSensor__Sequence__copy(
      &(input->sensors), &(output->sensors)))
  {
    return false;
  }
  return true;
}

fixposition_driver_ros2__msg__Speed *
fixposition_driver_ros2__msg__Speed__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__Speed * msg = (fixposition_driver_ros2__msg__Speed *)allocator.allocate(sizeof(fixposition_driver_ros2__msg__Speed), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fixposition_driver_ros2__msg__Speed));
  bool success = fixposition_driver_ros2__msg__Speed__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fixposition_driver_ros2__msg__Speed__destroy(fixposition_driver_ros2__msg__Speed * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fixposition_driver_ros2__msg__Speed__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fixposition_driver_ros2__msg__Speed__Sequence__init(fixposition_driver_ros2__msg__Speed__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__Speed * data = NULL;

  if (size) {
    data = (fixposition_driver_ros2__msg__Speed *)allocator.zero_allocate(size, sizeof(fixposition_driver_ros2__msg__Speed), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fixposition_driver_ros2__msg__Speed__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fixposition_driver_ros2__msg__Speed__fini(&data[i - 1]);
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
fixposition_driver_ros2__msg__Speed__Sequence__fini(fixposition_driver_ros2__msg__Speed__Sequence * array)
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
      fixposition_driver_ros2__msg__Speed__fini(&array->data[i]);
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

fixposition_driver_ros2__msg__Speed__Sequence *
fixposition_driver_ros2__msg__Speed__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__Speed__Sequence * array = (fixposition_driver_ros2__msg__Speed__Sequence *)allocator.allocate(sizeof(fixposition_driver_ros2__msg__Speed__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fixposition_driver_ros2__msg__Speed__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fixposition_driver_ros2__msg__Speed__Sequence__destroy(fixposition_driver_ros2__msg__Speed__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fixposition_driver_ros2__msg__Speed__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fixposition_driver_ros2__msg__Speed__Sequence__are_equal(const fixposition_driver_ros2__msg__Speed__Sequence * lhs, const fixposition_driver_ros2__msg__Speed__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fixposition_driver_ros2__msg__Speed__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fixposition_driver_ros2__msg__Speed__Sequence__copy(
  const fixposition_driver_ros2__msg__Speed__Sequence * input,
  fixposition_driver_ros2__msg__Speed__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fixposition_driver_ros2__msg__Speed);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fixposition_driver_ros2__msg__Speed * data =
      (fixposition_driver_ros2__msg__Speed *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fixposition_driver_ros2__msg__Speed__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fixposition_driver_ros2__msg__Speed__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fixposition_driver_ros2__msg__Speed__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
