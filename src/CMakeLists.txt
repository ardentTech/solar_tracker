add_executable(cmake_testapp
        main.c
)

target_link_libraries(cmake_testapp PUBLIC stm32)

target_include_directories(cmake_testapp PUBLIC
    ../inc
)