//  ����ͨ��     USART1    

#ifndef __BSP_USART1_H
#define __BSP_USART1_H

#include <stdio.h>     
// ʹ��printf��scanf��getchar�Ⱥ���
//  Keil ���C/C++�й�ѡ"Use MicroLIB"

#include "stm32f10x.h"

void USART1_IOInit(void);
void NVIC_USART1Enable(void);
void USART1Init(uint32_t BAUDRATE);
void USART1_IRQHandler(void);
int fputc(int ch, FILE *f);
int fgetc(FILE *f);
void Show_Message( void );
extern volatile uint8_t usart1_cmd_flag;
extern volatile uint8_t usart1_cmd_val;

#endif


