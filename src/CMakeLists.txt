add_executable(cmake_testapp
        main.c
)

target_link_libraries(cmake_testapp PUBLIC stm32)