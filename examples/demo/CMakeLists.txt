project(offt-demo)

add_executable(demo
    demo.cpp
)

target_link_libraries(demo PRIVATE offt)
