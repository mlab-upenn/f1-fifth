# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:fixposition_driver_ros2__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:fixposition_driver_ros2__rosidl_typesupport_fastrtps_c;__rosidl_generator_cpp:fixposition_driver_ros2__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:fixposition_driver_ros2__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_c:fixposition_driver_ros2__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:fixposition_driver_ros2__rosidl_typesupport_c;__rosidl_typesupport_introspection_cpp:fixposition_driver_ros2__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:fixposition_driver_ros2__rosidl_typesupport_cpp;__rosidl_generator_py:fixposition_driver_ros2__rosidl_generator_py")

# populate fixposition_driver_ros2_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "fixposition_driver_ros2::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'fixposition_driver_ros2' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND fixposition_driver_ros2_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
