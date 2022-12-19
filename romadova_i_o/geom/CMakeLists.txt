cmake_minimum_required (VERSION 3.8)

add_library(geom geometry.hpp geometry.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET geom PROPERTY CXX_STANDARD 20)
endif()
