#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "fixposition_gnss_tf" for configuration "Release"
set_property(TARGET fixposition_gnss_tf APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(fixposition_gnss_tf PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libfixposition_gnss_tf.so"
  IMPORTED_SONAME_RELEASE "libfixposition_gnss_tf.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS fixposition_gnss_tf )
list(APPEND _IMPORT_CHECK_FILES_FOR_fixposition_gnss_tf "${_IMPORT_PREFIX}/lib/libfixposition_gnss_tf.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
