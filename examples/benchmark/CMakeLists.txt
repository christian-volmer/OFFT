project(offt-benchmark)

add_executable(benchmark
    benchmark.cpp
)

target_link_libraries(benchmark PRIVATE offt)
target_include_directories(benchmark PRIVATE ../../libs)

set_property(TARGET benchmark PROPERTY CXX_STANDARD 11)
set_property(TARGET benchmark PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET benchmark PROPERTY CXX_EXTENSIONS OFF)
