#include "delay.h"
#include "stm32f10x.h"

// �򵥵������ʱ����λms
void Delay_ms(uint32_t ms) {
    uint32_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 8000; j++) {
            __NOP();
        }
    }
}
