#ifndef __KEY_H
#define __KEY_H

#include <stdint.h>

void KEY_Init(void);
uint8_t KEY1_IsPressed(void); // PA0
uint8_t KEY2_IsPressed(void); // PC13

#endif
