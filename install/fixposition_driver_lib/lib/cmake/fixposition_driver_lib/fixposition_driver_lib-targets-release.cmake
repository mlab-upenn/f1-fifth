#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "fixposition_driver_lib" for configuration "Release"
set_property(TARGET fixposition_driver_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(fixposition_driver_lib PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libfixposition_driver_lib.so"
  IMPORTED_SONAME_RELEASE "libfixposition_driver_lib.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS fixposition_driver_lib )
list(APPEND _IMPORT_CHECK_FILES_FOR_fixposition_driver_lib "${_IMPORT_PREFIX}/lib/libfixposition_driver_lib.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
