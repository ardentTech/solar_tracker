add_library(unity STATIC
    unity/src/unity.c
)

target_include_directories(unity PUBLIC
    unity/src
)

add_library(stm32 INTERFACE)

target_include_directories(stm32 INTERFACE
    stm32/Drivers/CMSIS/Include
    stm32/Drivers/CMSIS/Device/ST/STM32C0xx/Include
)

target_compile_definitions(stm32 INTERFACE
    STM32C031xx
)

target_sources(stm32 PUBLIC
    stm32/Drivers/CMSIS/Device/ST/STM32C0xx/Source/Templates/system_stm32c0xx.c
    stm32/Drivers/CMSIS/Device/ST/STM32C0xx/Source/Templates/gcc/startup_stm32c031xx.s
)