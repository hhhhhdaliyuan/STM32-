#include "traffic_light.h"
#include "lcd_ui.h"

extern TrafficLightSystem g_trafficSys;

void TIM5_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM5, TIM_IT_Update);

        TrafficLight_Update(&g_trafficSys);           // 交通灯状态机推进+倒计时
        LCDUI_DrawTrafficLights(&g_trafficSys);       // 刷新LCD红绿灯和倒计时
    }
}
