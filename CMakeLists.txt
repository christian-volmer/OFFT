cmake_minimum_required(VERSION 3.10)

project(offt)

if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)

  # Enforce C++11 to ensure we are not using features from later standards
  add_compile_options(-std=c++11)
endif()

add_subdirectory(offt)
add_subdirectory(examples)

enable_testing()
add_test(NAME autotest COMMAND autotest)
