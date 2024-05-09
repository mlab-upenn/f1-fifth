// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ouster_sensor_msgs:srv/SetConfig.idl
// generated code does not contain a copyright notice

#ifndef OUSTER_SENSOR_MSGS__SRV__DETAIL__SET_CONFIG__FUNCTIONS_H_
#define OUSTER_SENSOR_MSGS__SRV__DETAIL__SET_CONFIG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ouster_sensor_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "ouster_sensor_msgs/srv/detail/set_config__struct.h"

/// Initialize srv/SetConfig message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ouster_sensor_msgs__srv__SetConfig_Request
 * )) before or use
 * ouster_sensor_msgs__srv__SetConfig_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Request__init(ouster_sensor_msgs__srv__SetConfig_Request * msg);

/// Finalize srv/SetConfig message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
void
ouster_sensor_msgs__srv__SetConfig_Request__fini(ouster_sensor_msgs__srv__SetConfig_Request * msg);

/// Create srv/SetConfig message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ouster_sensor_msgs__srv__SetConfig_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
ouster_sensor_msgs__srv__SetConfig_Request *
ouster_sensor_msgs__srv__SetConfig_Request__create();

/// Destroy srv/SetConfig message.
/**
 * It calls
 * ouster_sensor_msgs__srv__SetConfig_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
void
ouster_sensor_msgs__srv__SetConfig_Request__destroy(ouster_sensor_msgs__srv__SetConfig_Request * msg);

/// Check for srv/SetConfig message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Request__are_equal(const ouster_sensor_msgs__srv__SetConfig_Request * lhs, const ouster_sensor_msgs__srv__SetConfig_Request * rhs);

/// Copy a srv/SetConfig message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Request__copy(
  const ouster_sensor_msgs__srv__SetConfig_Request * input,
  ouster_sensor_msgs__srv__SetConfig_Request * output);

/// Initialize array of srv/SetConfig messages.
/**
 * It allocates the memory for the number of elements and calls
 * ouster_sensor_msgs__srv__SetConfig_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Request__Sequence__init(ouster_sensor_msgs__srv__SetConfig_Request__Sequence * array, size_t size);

/// Finalize array of srv/SetConfig messages.
/**
 * It calls
 * ouster_sensor_msgs__srv__SetConfig_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
void
ouster_sensor_msgs__srv__SetConfig_Request__Sequence__fini(ouster_sensor_msgs__srv__SetConfig_Request__Sequence * array);

/// Create array of srv/SetConfig messages.
/**
 * It allocates the memory for the array and calls
 * ouster_sensor_msgs__srv__SetConfig_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
ouster_sensor_msgs__srv__SetConfig_Request__Sequence *
ouster_sensor_msgs__srv__SetConfig_Request__Sequence__create(size_t size);

/// Destroy array of srv/SetConfig messages.
/**
 * It calls
 * ouster_sensor_msgs__srv__SetConfig_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
void
ouster_sensor_msgs__srv__SetConfig_Request__Sequence__destroy(ouster_sensor_msgs__srv__SetConfig_Request__Sequence * array);

/// Check for srv/SetConfig message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Request__Sequence__are_equal(const ouster_sensor_msgs__srv__SetConfig_Request__Sequence * lhs, const ouster_sensor_msgs__srv__SetConfig_Request__Sequence * rhs);

/// Copy an array of srv/SetConfig messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Request__Sequence__copy(
  const ouster_sensor_msgs__srv__SetConfig_Request__Sequence * input,
  ouster_sensor_msgs__srv__SetConfig_Request__Sequence * output);

/// Initialize srv/SetConfig message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ouster_sensor_msgs__srv__SetConfig_Response
 * )) before or use
 * ouster_sensor_msgs__srv__SetConfig_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Response__init(ouster_sensor_msgs__srv__SetConfig_Response * msg);

/// Finalize srv/SetConfig message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
void
ouster_sensor_msgs__srv__SetConfig_Response__fini(ouster_sensor_msgs__srv__SetConfig_Response * msg);

/// Create srv/SetConfig message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ouster_sensor_msgs__srv__SetConfig_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
ouster_sensor_msgs__srv__SetConfig_Response *
ouster_sensor_msgs__srv__SetConfig_Response__create();

/// Destroy srv/SetConfig message.
/**
 * It calls
 * ouster_sensor_msgs__srv__SetConfig_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
void
ouster_sensor_msgs__srv__SetConfig_Response__destroy(ouster_sensor_msgs__srv__SetConfig_Response * msg);

/// Check for srv/SetConfig message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Response__are_equal(const ouster_sensor_msgs__srv__SetConfig_Response * lhs, const ouster_sensor_msgs__srv__SetConfig_Response * rhs);

/// Copy a srv/SetConfig message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Response__copy(
  const ouster_sensor_msgs__srv__SetConfig_Response * input,
  ouster_sensor_msgs__srv__SetConfig_Response * output);

/// Initialize array of srv/SetConfig messages.
/**
 * It allocates the memory for the number of elements and calls
 * ouster_sensor_msgs__srv__SetConfig_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Response__Sequence__init(ouster_sensor_msgs__srv__SetConfig_Response__Sequence * array, size_t size);

/// Finalize array of srv/SetConfig messages.
/**
 * It calls
 * ouster_sensor_msgs__srv__SetConfig_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
void
ouster_sensor_msgs__srv__SetConfig_Response__Sequence__fini(ouster_sensor_msgs__srv__SetConfig_Response__Sequence * array);

/// Create array of srv/SetConfig messages.
/**
 * It allocates the memory for the array and calls
 * ouster_sensor_msgs__srv__SetConfig_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
ouster_sensor_msgs__srv__SetConfig_Response__Sequence *
ouster_sensor_msgs__srv__SetConfig_Response__Sequence__create(size_t size);

/// Destroy array of srv/SetConfig messages.
/**
 * It calls
 * ouster_sensor_msgs__srv__SetConfig_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
void
ouster_sensor_msgs__srv__SetConfig_Response__Sequence__destroy(ouster_sensor_msgs__srv__SetConfig_Response__Sequence * array);

/// Check for srv/SetConfig message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Response__Sequence__are_equal(const ouster_sensor_msgs__srv__SetConfig_Response__Sequence * lhs, const ouster_sensor_msgs__srv__SetConfig_Response__Sequence * rhs);

/// Copy an array of srv/SetConfig messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ouster_sensor_msgs
bool
ouster_sensor_msgs__srv__SetConfig_Response__Sequence__copy(
  const ouster_sensor_msgs__srv__SetConfig_Response__Sequence * input,
  ouster_sensor_msgs__srv__SetConfig_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OUSTER_SENSOR_MSGS__SRV__DETAIL__SET_CONFIG__FUNCTIONS_H_
