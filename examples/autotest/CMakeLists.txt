project(offt-autotest)

add_executable(autotest
    main.cpp
)

target_link_libraries(autotest PRIVATE offt)
target_include_directories(autotest PRIVATE ../../libs)

set_property(TARGET autotest PROPERTY CXX_STANDARD 11)
set_property(TARGET autotest PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET autotest PROPERTY CXX_EXTENSIONS OFF)

add_test(autotest autotest)
