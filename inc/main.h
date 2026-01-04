//
// Created by jondbaker on 1/3/26.
//

#ifndef CMAKE_TESTAPP_MAIN_H
#define CMAKE_TESTAPP_MAIN_H

#include "stm32c0xx_hal.h"
#include "stm32c0xx_it.h"

#define LED_Pin GPIO_PIN_5
#define LED_Pin_GPIO_Port GPIOA

#define Y_CLK_Pin GPIO_PIN_10
#define Y_CLK_GPIO_Port GPIOA
#define Y_CLK_EXTI_IRQn EXTI4_15_IRQn
#define Y_DT_Pin GPIO_PIN_3
#define Y_DT_GPIO_Port GPIOB
#define Y_DT_EXTI_IRQn EXTI2_3_IRQn

#define X_DT_Pin GPIO_PIN_6
#define X_DT_GPIO_Port GPIOB
#define X_DT_EXTI_IRQn EXTI4_15_IRQn
#define X_CLK_Pin GPIO_PIN_7
#define X_CLK_GPIO_Port GPIOB
#define X_CLK_EXTI_IRQn EXTI4_15_IRQn

typedef enum {
    OTHER = 0,
    ADC_CALIBRATION,
    ADC_CONFIG_CHANNEL,
    ADC_CONVERSION,
    ADC_INIT,
    ADC_START,
    ADC_START_TIMEOUT,
    COM_INIT,
    DMA_INIT,
    RCC_CLOCK_CONFIG_CLOCK,
    RCC_CLOCK_CONFIG_OSCILLATOR,
    TIM_CONFIG,
    TIM_CONFIG_CHANNEL,
    TIM_PWM_INIT,
    TIM_PWM_START,
    TIM_SYNC,
} AppError;

#endif //CMAKE_TESTAPP_MAIN_H