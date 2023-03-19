cmake_minimum_required(VERSION 3.10)

project(offt)

if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set_property(GLOBAL PROPERTY CMAKE_CXX_STANDARD 11)
set_property(GLOBAL PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(offt)
add_subdirectory(examples)
