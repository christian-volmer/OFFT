project(offt-demo)

add_executable(demo
    demo.cpp
)

target_link_libraries(demo PRIVATE offt)
target_include_directories(demo PRIVATE ../../libs)

set_property(TARGET demo PROPERTY CXX_STANDARD 11)
set_property(TARGET demo PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET demo PROPERTY CXX_EXTENSIONS OFF)
