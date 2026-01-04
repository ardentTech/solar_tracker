#include "main.h"
#include "rotary_encoder.h"

ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

// prototypes
// extern void SysTick_Handler(void);
void Error_Handler(AppError error);
void GPIO_PA5_Init(void);
void SystemClock_Config(void);
void GPIO_Init(void);

// implementations
void Error_Handler(const AppError error) {
    printf("unexpected error: %d\r\n", error);
    __disable_irq();
    while (1) {}
}

void GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    /* USER CODE BEGIN MX_GPIO_Init_1 */

    /* USER CODE END MX_GPIO_Init_1 */

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /*Configure GPIO pin : Y_CLK_Pin */
    GPIO_InitStruct.Pin = Y_CLK_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(Y_CLK_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pins : Y_DT_Pin X_DT_Pin X_CLK_Pin */
    GPIO_InitStruct.Pin = Y_DT_Pin | X_DT_Pin | X_CLK_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    // LED
    GPIO_InitStruct.Pin = LED_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_Pin_GPIO_Port, &GPIO_InitStruct);

    /* EXTI interrupt init*/
    HAL_NVIC_SetPriority(EXTI2_3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);

    HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

    /* USER CODE BEGIN MX_GPIO_Init_2 */

    /* USER CODE END MX_GPIO_Init_2 */
}

void SystemClock_Config(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_1);

    /** Initializes the RCC Oscillators according to the specified parameters
    * in the RCC_OscInitTypeDef structure.
    */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler(RCC_CLOCK_CONFIG_OSCILLATOR);
    }

    /** Initializes the CPU, AHB and APB buses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
    RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
        Error_Handler(RCC_CLOCK_CONFIG_CLOCK);
    }
}

// void SysTick_Handler(void) { HAL_IncTick(); }

int main(void) {
    HAL_Init();
    GPIO_Init();

    const RotaryEncoder pan_encoder = (RotaryEncoder){X_CLK_GPIO_Port, X_CLK_Pin, X_DT_GPIO_Port, X_DT_Pin, 0, 0};
    const RotaryEncoder tilt_encoder = (RotaryEncoder){Y_CLK_GPIO_Port, Y_CLK_Pin, Y_DT_GPIO_Port, Y_DT_Pin, 0, 0};

    while (1) {
        HAL_GPIO_TogglePin(LED_Pin_GPIO_Port, LED_Pin);
        HAL_Delay(750);
    }
}