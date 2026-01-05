add_executable(cmake_testapp
        main.c
        rotary_encoder.c
        stm32c0xx_it.c
        stm32c0xx_hal_msp.c
        syscalls.c
        sysmem.c
)

target_link_libraries(cmake_testapp PUBLIC stm32)

target_include_directories(cmake_testapp PUBLIC
    ../inc
)