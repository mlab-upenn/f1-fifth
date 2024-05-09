// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ouster_msgs:srv/GetMetadata.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_MSGS__SRV__DETAIL__GET_METADATA__STRUCT_H_
#define OUSTER_MSGS__SRV__DETAIL__GET_METADATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'metadata_filepath'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetMetadata in the package ouster_msgs.
typedef struct ouster_msgs__srv__GetMetadata_Request
{
  rosidl_runtime_c__String metadata_filepath;
} ouster_msgs__srv__GetMetadata_Request;

// Struct for a sequence of ouster_msgs__srv__GetMetadata_Request.
typedef struct ouster_msgs__srv__GetMetadata_Request__Sequence
{
  ouster_msgs__srv__GetMetadata_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ouster_msgs__srv__GetMetadata_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'metadata'
#include "ouster_msgs/msg/detail/metadata__struct.h"

/// Struct defined in srv/GetMetadata in the package ouster_msgs.
typedef struct ouster_msgs__srv__GetMetadata_Response
{
  ouster_msgs__msg__Metadata metadata;
} ouster_msgs__srv__GetMetadata_Response;

// Struct for a sequence of ouster_msgs__srv__GetMetadata_Response.
typedef struct ouster_msgs__srv__GetMetadata_Response__Sequence
{
  ouster_msgs__srv__GetMetadata_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ouster_msgs__srv__GetMetadata_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OUSTER_MSGS__SRV__DETAIL__GET_METADATA__STRUCT_H_
