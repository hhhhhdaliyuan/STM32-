#ifndef __LCD_UI_H
#define __LCD_UI_H

#include "traffic_light.h"
#include <stdint.h>
#define DIR_CNT 4

extern TrafficLightSystem *sys; // ֻ����
void LCDUI_DrawCrossRoad(void);
void LCDUI_DrawTrafficLights(TrafficLightSystem *sys);

// ���ؼ���ת����ʱ���ֽӿ�
void LCDUI_ShowNum_Dir(uint16_t x, uint16_t y, int num, uint16_t color, uint16_t bgcolor, uint8_t dir_idx);
#endif
