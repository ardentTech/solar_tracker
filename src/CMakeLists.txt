add_executable(solar_tracker
        main.c
        rotary_encoder.c
        stm32c0xx_it.c
        stm32c0xx_hal_msp.c
        syscalls.c
        sysmem.c
)

target_link_libraries(solar_tracker PUBLIC stm32)

target_include_directories(solar_tracker PUBLIC
    ../inc
)