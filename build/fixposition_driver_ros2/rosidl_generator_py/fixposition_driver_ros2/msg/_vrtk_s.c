// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from fixposition_driver_ros2:msg/VRTK.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "fixposition_driver_ros2/msg/detail/vrtk__struct.h"
#include "fixposition_driver_ros2/msg/detail/vrtk__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose_with_covariance__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose_with_covariance__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__twist_with_covariance__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__twist_with_covariance__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__vector3__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__vector3__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool fixposition_driver_ros2__msg__vrtk__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("fixposition_driver_ros2.msg._vrtk.VRTK", full_classname_dest, 38) == 0);
  }
  fixposition_driver_ros2__msg__VRTK * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // pose_frame
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose_frame");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->pose_frame, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // kin_frame
    PyObject * field = PyObject_GetAttrString(_pymsg, "kin_frame");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->kin_frame, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose_with_covariance__convert_from_py(field, &ros_message->pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "velocity");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__twist_with_covariance__convert_from_py(field, &ros_message->velocity)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // acceleration
    PyObject * field = PyObject_GetAttrString(_pymsg, "acceleration");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__vector3__convert_from_py(field, &ros_message->acceleration)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // fusion_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "fusion_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fusion_status = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // imu_bias_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "imu_bias_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->imu_bias_status = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // gnss1_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss1_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gnss1_status = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // gnss2_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss2_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gnss2_status = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // wheelspeed_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "wheelspeed_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->wheelspeed_status = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // version
    PyObject * field = PyObject_GetAttrString(_pymsg, "version");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->version, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * fixposition_driver_ros2__msg__vrtk__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of VRTK */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("fixposition_driver_ros2.msg._vrtk");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "VRTK");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  fixposition_driver_ros2__msg__VRTK * ros_message = (fixposition_driver_ros2__msg__VRTK *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pose_frame
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->pose_frame.data,
      strlen(ros_message->pose_frame.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose_frame", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // kin_frame
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->kin_frame.data,
      strlen(ros_message->kin_frame.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "kin_frame", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose_with_covariance__convert_to_py(&ros_message->pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // velocity
    PyObject * field = NULL;
    field = geometry_msgs__msg__twist_with_covariance__convert_to_py(&ros_message->velocity);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acceleration
    PyObject * field = NULL;
    field = geometry_msgs__msg__vector3__convert_to_py(&ros_message->acceleration);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "acceleration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fusion_status
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->fusion_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fusion_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // imu_bias_status
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->imu_bias_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "imu_bias_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss1_status
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gnss1_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss1_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss2_status
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gnss2_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss2_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // wheelspeed_status
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->wheelspeed_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "wheelspeed_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // version
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->version.data,
      strlen(ros_message->version.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "version", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
