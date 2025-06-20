# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appTemperature_Converter_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appTemperature_Converter_autogen.dir\\ParseCache.txt"
  "appTemperature_Converter_autogen"
  )
endif()
