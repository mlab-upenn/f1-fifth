# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_fixposition_driver_ros2_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED fixposition_driver_ros2_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(fixposition_driver_ros2_FOUND FALSE)
  elseif(NOT fixposition_driver_ros2_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(fixposition_driver_ros2_FOUND FALSE)
  endif()
  return()
endif()
set(_fixposition_driver_ros2_CONFIG_INCLUDED TRUE)

# output package information
if(NOT fixposition_driver_ros2_FIND_QUIETLY)
  message(STATUS "Found fixposition_driver_ros2: 5.0.0 (${fixposition_driver_ros2_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'fixposition_driver_ros2' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${fixposition_driver_ros2_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(fixposition_driver_ros2_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "rosidl_cmake-extras.cmake;ament_cmake_export_dependencies-extras.cmake;ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_targets-extras.cmake;rosidl_cmake_export_typesupport_targets-extras.cmake;rosidl_cmake_export_typesupport_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${fixposition_driver_ros2_DIR}/${_extra}")
endforeach()
