#include "stm32f10x.h"
#include "BSP_LCD.h"
#include "BSP_USART1.h"
#include "traffic_light.h"
#include "lcd_ui.h"
#include <stdio.h>
#include "key.h"
TrafficLightSystem traffic_system;
TrafficLightSystem *sys = &traffic_system;
extern TrafficLightSystem *sys;
TrafficLightSystem g_trafficSys;
uint8_t key1_last = 0;
extern volatile uint8_t usart1_cmd_flag;
extern volatile uint8_t usart1_cmd_val;

int main(void)
{
	 KEY_Init();
	  SystemInit();
    TIM5_Init();       
	 sys = &g_trafficSys;
	 TrafficLight_Init(sys);
    // 初始化硬件
    LCD_Init();
    LCD_Clear(WHITE);
	
     USART1Init(9600); // 初始化串口1
  Show_Message();

    TrafficLight_Init(&g_trafficSys);
LCDUI_DrawCrossRoad(); // 只执行一次，画背景和路面
    uint8_t key1_last = 0;
    uint8_t key2_last = 0;
    uint8_t cycle_mode = 0;
    while(1)
    {  
		//禁止通行
			uint8_t key1_now = KEY1_IsPressed();
        if (key1_now && !key1_last) {
            TrafficLight_EnterAllRed(sys, 21);
        }
        key1_last = key1_now;

        uint8_t key2_now = KEY2_IsPressed();
        if (key2_now && !key2_last) {
            if (!cycle_mode) {
                TrafficLight_SetExtendedTiming(sys);
                cycle_mode = 1;
            } else {
                TrafficLight_SetDefaultTiming(sys);
                cycle_mode = 0;
            }
        }
        key2_last = key2_now;

				// 串口命令处理
        if (usart1_cmd_flag) {
            if (usart1_cmd_val == '1') {
                TrafficLight_EnterNSPass(sys, 16);
            } else if (usart1_cmd_val == '2') {
                TrafficLight_EnterEWPass(sys, 16);
            }
            usart1_cmd_flag = 0; // 清除标志
        }
        // 延时
        Delay_ms(10);
    }
}

