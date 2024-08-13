#include "Gpio.h"

// Função para inicializar os pinos GPIO

void GPIO_Init(void) {
    // Habilita o clock para o GPIOA
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitTypeDef GPIO_InitD = {0};
    GPIO_InitTypeDef GPIO_InitB = {0};
    GPIO_InitTypeDef GIPO_InitB_input={0};
    // Configura os pino PA 0-7 como saída push-pull
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|
    GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    // Configura os pino PD 0-2 como saída push-pull
    GPIO_InitD.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
    GPIO_InitD.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitD.Pull = GPIO_NOPULL;
    GPIO_InitD.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOD, &GPIO_InitD);

    // Configura os pino PB 0-3 como saída push-pull -Linhas keypad
    GPIO_InitB.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitB.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitB.Pull = GPIO_NOPULL;
    GPIO_InitB.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitB);

    // Configura os pino PB 4-7 como entrada pull-up -Colunas keypad
    GIPO_InitB_input.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
    GIPO_InitB_input.Mode = GPIO_MODE_INPUT;
    GIPO_InitB_input.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOB, &GIPO_InitB_input);

}

