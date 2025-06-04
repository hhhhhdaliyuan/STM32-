#include "key.h"
#include "stm32f10x.h"

void KEY_Init(void) {
    // KEY1: PA0 上拉输入
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef gpioA;
    gpioA.GPIO_Pin = GPIO_Pin_0;
    gpioA.GPIO_Mode = GPIO_Mode_IPU;
    gpioA.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &gpioA);

    // KEY2: PC13 上拉输入
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef gpioC;
    gpioC.GPIO_Pin = GPIO_Pin_13;
    gpioC.GPIO_Mode = GPIO_Mode_IPU;
    gpioC.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &gpioC);
}

uint8_t KEY1_IsPressed(void) {
    return (GPIOA->IDR & GPIO_Pin_0) ? 1 : 0;
}

uint8_t KEY2_IsPressed(void) {
    return (GPIOC->IDR & GPIO_Pin_13) ? 1 : 0;
}
