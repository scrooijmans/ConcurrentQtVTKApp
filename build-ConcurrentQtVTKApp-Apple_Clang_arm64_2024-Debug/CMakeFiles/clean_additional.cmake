# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ConcurrentQtVTKApp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ConcurrentQtVTKApp_autogen.dir/ParseCache.txt"
  "ConcurrentQtVTKApp_autogen"
  )
endif()
