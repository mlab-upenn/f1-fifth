// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fixposition_driver_ros2:msg/WheelSensor.idl
// generated code does not contain a copyright notice
#include "fixposition_driver_ros2/msg/detail/wheel_sensor__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `location`
#include "rosidl_runtime_c/string_functions.h"

bool
fixposition_driver_ros2__msg__WheelSensor__init(fixposition_driver_ros2__msg__WheelSensor * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    fixposition_driver_ros2__msg__WheelSensor__fini(msg);
    return false;
  }
  // location
  if (!rosidl_runtime_c__String__init(&msg->location)) {
    fixposition_driver_ros2__msg__WheelSensor__fini(msg);
    return false;
  }
  // vx
  // vy
  // vz
  // vx_valid
  // vy_valid
  // vz_valid
  return true;
}

void
fixposition_driver_ros2__msg__WheelSensor__fini(fixposition_driver_ros2__msg__WheelSensor * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // location
  rosidl_runtime_c__String__fini(&msg->location);
  // vx
  // vy
  // vz
  // vx_valid
  // vy_valid
  // vz_valid
}

bool
fixposition_driver_ros2__msg__WheelSensor__are_equal(const fixposition_driver_ros2__msg__WheelSensor * lhs, const fixposition_driver_ros2__msg__WheelSensor * rhs)
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
  // location
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->location), &(rhs->location)))
  {
    return false;
  }
  // vx
  if (lhs->vx != rhs->vx) {
    return false;
  }
  // vy
  if (lhs->vy != rhs->vy) {
    return false;
  }
  // vz
  if (lhs->vz != rhs->vz) {
    return false;
  }
  // vx_valid
  if (lhs->vx_valid != rhs->vx_valid) {
    return false;
  }
  // vy_valid
  if (lhs->vy_valid != rhs->vy_valid) {
    return false;
  }
  // vz_valid
  if (lhs->vz_valid != rhs->vz_valid) {
    return false;
  }
  return true;
}

bool
fixposition_driver_ros2__msg__WheelSensor__copy(
  const fixposition_driver_ros2__msg__WheelSensor * input,
  fixposition_driver_ros2__msg__WheelSensor * output)
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
  // location
  if (!rosidl_runtime_c__String__copy(
      &(input->location), &(output->location)))
  {
    return false;
  }
  // vx
  output->vx = input->vx;
  // vy
  output->vy = input->vy;
  // vz
  output->vz = input->vz;
  // vx_valid
  output->vx_valid = input->vx_valid;
  // vy_valid
  output->vy_valid = input->vy_valid;
  // vz_valid
  output->vz_valid = input->vz_valid;
  return true;
}

fixposition_driver_ros2__msg__WheelSensor *
fixposition_driver_ros2__msg__WheelSensor__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__WheelSensor * msg = (fixposition_driver_ros2__msg__WheelSensor *)allocator.allocate(sizeof(fixposition_driver_ros2__msg__WheelSensor), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fixposition_driver_ros2__msg__WheelSensor));
  bool success = fixposition_driver_ros2__msg__WheelSensor__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fixposition_driver_ros2__msg__WheelSensor__destroy(fixposition_driver_ros2__msg__WheelSensor * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fixposition_driver_ros2__msg__WheelSensor__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fixposition_driver_ros2__msg__WheelSensor__Sequence__init(fixposition_driver_ros2__msg__WheelSensor__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__WheelSensor * data = NULL;

  if (size) {
    data = (fixposition_driver_ros2__msg__WheelSensor *)allocator.zero_allocate(size, sizeof(fixposition_driver_ros2__msg__WheelSensor), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fixposition_driver_ros2__msg__WheelSensor__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fixposition_driver_ros2__msg__WheelSensor__fini(&data[i - 1]);
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
fixposition_driver_ros2__msg__WheelSensor__Sequence__fini(fixposition_driver_ros2__msg__WheelSensor__Sequence * array)
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
      fixposition_driver_ros2__msg__WheelSensor__fini(&array->data[i]);
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

fixposition_driver_ros2__msg__WheelSensor__Sequence *
fixposition_driver_ros2__msg__WheelSensor__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__WheelSensor__Sequence * array = (fixposition_driver_ros2__msg__WheelSensor__Sequence *)allocator.allocate(sizeof(fixposition_driver_ros2__msg__WheelSensor__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fixposition_driver_ros2__msg__WheelSensor__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fixposition_driver_ros2__msg__WheelSensor__Sequence__destroy(fixposition_driver_ros2__msg__WheelSensor__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fixposition_driver_ros2__msg__WheelSensor__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fixposition_driver_ros2__msg__WheelSensor__Sequence__are_equal(const fixposition_driver_ros2__msg__WheelSensor__Sequence * lhs, const fixposition_driver_ros2__msg__WheelSensor__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fixposition_driver_ros2__msg__WheelSensor__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fixposition_driver_ros2__msg__WheelSensor__Sequence__copy(
  const fixposition_driver_ros2__msg__WheelSensor__Sequence * input,
  fixposition_driver_ros2__msg__WheelSensor__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fixposition_driver_ros2__msg__WheelSensor);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fixposition_driver_ros2__msg__WheelSensor * data =
      (fixposition_driver_ros2__msg__WheelSensor *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fixposition_driver_ros2__msg__WheelSensor__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fixposition_driver_ros2__msg__WheelSensor__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fixposition_driver_ros2__msg__WheelSensor__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
