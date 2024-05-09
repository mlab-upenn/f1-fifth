// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ouster_sensor_msgs:srv/GetMetadata.idl
// generated code does not contain a copyright notice
#include "ouster_sensor_msgs/srv/detail/get_metadata__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
ouster_sensor_msgs__srv__GetMetadata_Request__init(ouster_sensor_msgs__srv__GetMetadata_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
ouster_sensor_msgs__srv__GetMetadata_Request__fini(ouster_sensor_msgs__srv__GetMetadata_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
ouster_sensor_msgs__srv__GetMetadata_Request__are_equal(const ouster_sensor_msgs__srv__GetMetadata_Request * lhs, const ouster_sensor_msgs__srv__GetMetadata_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
ouster_sensor_msgs__srv__GetMetadata_Request__copy(
  const ouster_sensor_msgs__srv__GetMetadata_Request * input,
  ouster_sensor_msgs__srv__GetMetadata_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

ouster_sensor_msgs__srv__GetMetadata_Request *
ouster_sensor_msgs__srv__GetMetadata_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ouster_sensor_msgs__srv__GetMetadata_Request * msg = (ouster_sensor_msgs__srv__GetMetadata_Request *)allocator.allocate(sizeof(ouster_sensor_msgs__srv__GetMetadata_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ouster_sensor_msgs__srv__GetMetadata_Request));
  bool success = ouster_sensor_msgs__srv__GetMetadata_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ouster_sensor_msgs__srv__GetMetadata_Request__destroy(ouster_sensor_msgs__srv__GetMetadata_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ouster_sensor_msgs__srv__GetMetadata_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ouster_sensor_msgs__srv__GetMetadata_Request__Sequence__init(ouster_sensor_msgs__srv__GetMetadata_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ouster_sensor_msgs__srv__GetMetadata_Request * data = NULL;

  if (size) {
    data = (ouster_sensor_msgs__srv__GetMetadata_Request *)allocator.zero_allocate(size, sizeof(ouster_sensor_msgs__srv__GetMetadata_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ouster_sensor_msgs__srv__GetMetadata_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ouster_sensor_msgs__srv__GetMetadata_Request__fini(&data[i - 1]);
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
ouster_sensor_msgs__srv__GetMetadata_Request__Sequence__fini(ouster_sensor_msgs__srv__GetMetadata_Request__Sequence * array)
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
      ouster_sensor_msgs__srv__GetMetadata_Request__fini(&array->data[i]);
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

ouster_sensor_msgs__srv__GetMetadata_Request__Sequence *
ouster_sensor_msgs__srv__GetMetadata_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ouster_sensor_msgs__srv__GetMetadata_Request__Sequence * array = (ouster_sensor_msgs__srv__GetMetadata_Request__Sequence *)allocator.allocate(sizeof(ouster_sensor_msgs__srv__GetMetadata_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ouster_sensor_msgs__srv__GetMetadata_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ouster_sensor_msgs__srv__GetMetadata_Request__Sequence__destroy(ouster_sensor_msgs__srv__GetMetadata_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ouster_sensor_msgs__srv__GetMetadata_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ouster_sensor_msgs__srv__GetMetadata_Request__Sequence__are_equal(const ouster_sensor_msgs__srv__GetMetadata_Request__Sequence * lhs, const ouster_sensor_msgs__srv__GetMetadata_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ouster_sensor_msgs__srv__GetMetadata_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ouster_sensor_msgs__srv__GetMetadata_Request__Sequence__copy(
  const ouster_sensor_msgs__srv__GetMetadata_Request__Sequence * input,
  ouster_sensor_msgs__srv__GetMetadata_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ouster_sensor_msgs__srv__GetMetadata_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ouster_sensor_msgs__srv__GetMetadata_Request * data =
      (ouster_sensor_msgs__srv__GetMetadata_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ouster_sensor_msgs__srv__GetMetadata_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ouster_sensor_msgs__srv__GetMetadata_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ouster_sensor_msgs__srv__GetMetadata_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `metadata`
#include "rosidl_runtime_c/string_functions.h"

bool
ouster_sensor_msgs__srv__GetMetadata_Response__init(ouster_sensor_msgs__srv__GetMetadata_Response * msg)
{
  if (!msg) {
    return false;
  }
  // metadata
  if (!rosidl_runtime_c__String__init(&msg->metadata)) {
    ouster_sensor_msgs__srv__GetMetadata_Response__fini(msg);
    return false;
  }
  return true;
}

void
ouster_sensor_msgs__srv__GetMetadata_Response__fini(ouster_sensor_msgs__srv__GetMetadata_Response * msg)
{
  if (!msg) {
    return;
  }
  // metadata
  rosidl_runtime_c__String__fini(&msg->metadata);
}

bool
ouster_sensor_msgs__srv__GetMetadata_Response__are_equal(const ouster_sensor_msgs__srv__GetMetadata_Response * lhs, const ouster_sensor_msgs__srv__GetMetadata_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // metadata
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->metadata), &(rhs->metadata)))
  {
    return false;
  }
  return true;
}

bool
ouster_sensor_msgs__srv__GetMetadata_Response__copy(
  const ouster_sensor_msgs__srv__GetMetadata_Response * input,
  ouster_sensor_msgs__srv__GetMetadata_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // metadata
  if (!rosidl_runtime_c__String__copy(
      &(input->metadata), &(output->metadata)))
  {
    return false;
  }
  return true;
}

ouster_sensor_msgs__srv__GetMetadata_Response *
ouster_sensor_msgs__srv__GetMetadata_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ouster_sensor_msgs__srv__GetMetadata_Response * msg = (ouster_sensor_msgs__srv__GetMetadata_Response *)allocator.allocate(sizeof(ouster_sensor_msgs__srv__GetMetadata_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ouster_sensor_msgs__srv__GetMetadata_Response));
  bool success = ouster_sensor_msgs__srv__GetMetadata_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ouster_sensor_msgs__srv__GetMetadata_Response__destroy(ouster_sensor_msgs__srv__GetMetadata_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ouster_sensor_msgs__srv__GetMetadata_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ouster_sensor_msgs__srv__GetMetadata_Response__Sequence__init(ouster_sensor_msgs__srv__GetMetadata_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ouster_sensor_msgs__srv__GetMetadata_Response * data = NULL;

  if (size) {
    data = (ouster_sensor_msgs__srv__GetMetadata_Response *)allocator.zero_allocate(size, sizeof(ouster_sensor_msgs__srv__GetMetadata_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ouster_sensor_msgs__srv__GetMetadata_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ouster_sensor_msgs__srv__GetMetadata_Response__fini(&data[i - 1]);
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
ouster_sensor_msgs__srv__GetMetadata_Response__Sequence__fini(ouster_sensor_msgs__srv__GetMetadata_Response__Sequence * array)
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
      ouster_sensor_msgs__srv__GetMetadata_Response__fini(&array->data[i]);
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

ouster_sensor_msgs__srv__GetMetadata_Response__Sequence *
ouster_sensor_msgs__srv__GetMetadata_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ouster_sensor_msgs__srv__GetMetadata_Response__Sequence * array = (ouster_sensor_msgs__srv__GetMetadata_Response__Sequence *)allocator.allocate(sizeof(ouster_sensor_msgs__srv__GetMetadata_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ouster_sensor_msgs__srv__GetMetadata_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ouster_sensor_msgs__srv__GetMetadata_Response__Sequence__destroy(ouster_sensor_msgs__srv__GetMetadata_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ouster_sensor_msgs__srv__GetMetadata_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ouster_sensor_msgs__srv__GetMetadata_Response__Sequence__are_equal(const ouster_sensor_msgs__srv__GetMetadata_Response__Sequence * lhs, const ouster_sensor_msgs__srv__GetMetadata_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ouster_sensor_msgs__srv__GetMetadata_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ouster_sensor_msgs__srv__GetMetadata_Response__Sequence__copy(
  const ouster_sensor_msgs__srv__GetMetadata_Response__Sequence * input,
  ouster_sensor_msgs__srv__GetMetadata_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ouster_sensor_msgs__srv__GetMetadata_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ouster_sensor_msgs__srv__GetMetadata_Response * data =
      (ouster_sensor_msgs__srv__GetMetadata_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ouster_sensor_msgs__srv__GetMetadata_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ouster_sensor_msgs__srv__GetMetadata_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ouster_sensor_msgs__srv__GetMetadata_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
