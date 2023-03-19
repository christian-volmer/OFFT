project(offt-benchmark)

add_executable(benchmark
    benchmark.cpp
)

target_link_libraries(benchmark PRIVATE offt)
