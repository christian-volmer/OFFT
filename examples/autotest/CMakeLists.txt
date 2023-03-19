project(offt-autotest)

add_executable(autotest
    main.cpp
)

target_link_libraries(autotest PRIVATE offt)

add_test(autotest autotest)
