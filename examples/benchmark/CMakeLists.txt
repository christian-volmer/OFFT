project(offt-benchmark)

add_executable(benchmark
    benchmark.cpp
    randomised_testing.cpp
    self_test.cpp
)

target_link_libraries(benchmark PRIVATE offt)
