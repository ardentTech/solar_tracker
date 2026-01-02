#include "stm32c031xx.h"

int main(void) {
    // code was verified in STM32CubeIDE and is OK
    RCC->IOPENR |= 1U<<0;
    GPIOA->MODER |= 1U<<10;
    GPIOA->MODER &= ~(1U<<11);

    while (1) {
        GPIOA->ODR ^= 1U<<5;
        for (int i = 0; i < 1000000; i++) {}
    }
}