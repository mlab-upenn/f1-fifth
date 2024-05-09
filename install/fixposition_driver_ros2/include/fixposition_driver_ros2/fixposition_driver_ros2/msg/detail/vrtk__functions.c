// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fixposition_driver_ros2:msg/VRTK.idl
// generated code does not contain a copyright notice
#include "fixposition_driver_ros2/msg/detail/vrtk__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pose_frame`
// Member `kin_frame`
// Member `version`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_with_covariance__functions.h"
// Member `velocity`
#include "geometry_msgs/msg/detail/twist_with_covariance__functions.h"
// Member `acceleration`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
fixposition_driver_ros2__msg__VRTK__init(fixposition_driver_ros2__msg__VRTK * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    fixposition_driver_ros2__msg__VRTK__fini(msg);
    return false;
  }
  // pose_frame
  if (!rosidl_runtime_c__String__init(&msg->pose_frame)) {
    fixposition_driver_ros2__msg__VRTK__fini(msg);
    return false;
  }
  // kin_frame
  if (!rosidl_runtime_c__String__init(&msg->kin_frame)) {
    fixposition_driver_ros2__msg__VRTK__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseWithCovariance__init(&msg->pose)) {
    fixposition_driver_ros2__msg__VRTK__fini(msg);
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__TwistWithCovariance__init(&msg->velocity)) {
    fixposition_driver_ros2__msg__VRTK__fini(msg);
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__init(&msg->acceleration)) {
    fixposition_driver_ros2__msg__VRTK__fini(msg);
    return false;
  }
  // fusion_status
  // imu_bias_status
  // gnss1_status
  // gnss2_status
  // wheelspeed_status
  // version
  if (!rosidl_runtime_c__String__init(&msg->version)) {
    fixposition_driver_ros2__msg__VRTK__fini(msg);
    return false;
  }
  return true;
}

void
fixposition_driver_ros2__msg__VRTK__fini(fixposition_driver_ros2__msg__VRTK * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // pose_frame
  rosidl_runtime_c__String__fini(&msg->pose_frame);
  // kin_frame
  rosidl_runtime_c__String__fini(&msg->kin_frame);
  // pose
  geometry_msgs__msg__PoseWithCovariance__fini(&msg->pose);
  // velocity
  geometry_msgs__msg__TwistWithCovariance__fini(&msg->velocity);
  // acceleration
  geometry_msgs__msg__Vector3__fini(&msg->acceleration);
  // fusion_status
  // imu_bias_status
  // gnss1_status
  // gnss2_status
  // wheelspeed_status
  // version
  rosidl_runtime_c__String__fini(&msg->version);
}

bool
fixposition_driver_ros2__msg__VRTK__are_equal(const fixposition_driver_ros2__msg__VRTK * lhs, const fixposition_driver_ros2__msg__VRTK * rhs)
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
  // pose_frame
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->pose_frame), &(rhs->pose_frame)))
  {
    return false;
  }
  // kin_frame
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->kin_frame), &(rhs->kin_frame)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseWithCovariance__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__TwistWithCovariance__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->acceleration), &(rhs->acceleration)))
  {
    return false;
  }
  // fusion_status
  if (lhs->fusion_status != rhs->fusion_status) {
    return false;
  }
  // imu_bias_status
  if (lhs->imu_bias_status != rhs->imu_bias_status) {
    return false;
  }
  // gnss1_status
  if (lhs->gnss1_status != rhs->gnss1_status) {
    return false;
  }
  // gnss2_status
  if (lhs->gnss2_status != rhs->gnss2_status) {
    return false;
  }
  // wheelspeed_status
  if (lhs->wheelspeed_status != rhs->wheelspeed_status) {
    return false;
  }
  // version
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->version), &(rhs->version)))
  {
    return false;
  }
  return true;
}

bool
fixposition_driver_ros2__msg__VRTK__copy(
  const fixposition_driver_ros2__msg__VRTK * input,
  fixposition_driver_ros2__msg__VRTK * output)
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
  // pose_frame
  if (!rosidl_runtime_c__String__copy(
      &(input->pose_frame), &(output->pose_frame)))
  {
    return false;
  }
  // kin_frame
  if (!rosidl_runtime_c__String__copy(
      &(input->kin_frame), &(output->kin_frame)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseWithCovariance__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__TwistWithCovariance__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->acceleration), &(output->acceleration)))
  {
    return false;
  }
  // fusion_status
  output->fusion_status = input->fusion_status;
  // imu_bias_status
  output->imu_bias_status = input->imu_bias_status;
  // gnss1_status
  output->gnss1_status = input->gnss1_status;
  // gnss2_status
  output->gnss2_status = input->gnss2_status;
  // wheelspeed_status
  output->wheelspeed_status = input->wheelspeed_status;
  // version
  if (!rosidl_runtime_c__String__copy(
      &(input->version), &(output->version)))
  {
    return false;
  }
  return true;
}

fixposition_driver_ros2__msg__VRTK *
fixposition_driver_ros2__msg__VRTK__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__VRTK * msg = (fixposition_driver_ros2__msg__VRTK *)allocator.allocate(sizeof(fixposition_driver_ros2__msg__VRTK), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fixposition_driver_ros2__msg__VRTK));
  bool success = fixposition_driver_ros2__msg__VRTK__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fixposition_driver_ros2__msg__VRTK__destroy(fixposition_driver_ros2__msg__VRTK * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fixposition_driver_ros2__msg__VRTK__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fixposition_driver_ros2__msg__VRTK__Sequence__init(fixposition_driver_ros2__msg__VRTK__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__VRTK * data = NULL;

  if (size) {
    data = (fixposition_driver_ros2__msg__VRTK *)allocator.zero_allocate(size, sizeof(fixposition_driver_ros2__msg__VRTK), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fixposition_driver_ros2__msg__VRTK__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fixposition_driver_ros2__msg__VRTK__fini(&data[i - 1]);
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
fixposition_driver_ros2__msg__VRTK__Sequence__fini(fixposition_driver_ros2__msg__VRTK__Sequence * array)
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
      fixposition_driver_ros2__msg__VRTK__fini(&array->data[i]);
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

fixposition_driver_ros2__msg__VRTK__Sequence *
fixposition_driver_ros2__msg__VRTK__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fixposition_driver_ros2__msg__VRTK__Sequence * array = (fixposition_driver_ros2__msg__VRTK__Sequence *)allocator.allocate(sizeof(fixposition_driver_ros2__msg__VRTK__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fixposition_driver_ros2__msg__VRTK__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fixposition_driver_ros2__msg__VRTK__Sequence__destroy(fixposition_driver_ros2__msg__VRTK__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fixposition_driver_ros2__msg__VRTK__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fixposition_driver_ros2__msg__VRTK__Sequence__are_equal(const fixposition_driver_ros2__msg__VRTK__Sequence * lhs, const fixposition_driver_ros2__msg__VRTK__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fixposition_driver_ros2__msg__VRTK__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fixposition_driver_ros2__msg__VRTK__Sequence__copy(
  const fixposition_driver_ros2__msg__VRTK__Sequence * input,
  fixposition_driver_ros2__msg__VRTK__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fixposition_driver_ros2__msg__VRTK);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fixposition_driver_ros2__msg__VRTK * data =
      (fixposition_driver_ros2__msg__VRTK *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fixposition_driver_ros2__msg__VRTK__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fixposition_driver_ros2__msg__VRTK__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fixposition_driver_ros2__msg__VRTK__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
