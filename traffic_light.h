#ifndef __TRAFFIC_LIGHT_H
#define __TRAFFIC_LIGHT_H

#include "stm32f10x.h"
#include <stdint.h>

#define DIR_CNT 4
#define LIGHT_GREEN  TL_GREEN
#define LIGHT_YELLOW TL_YELLOW
#define LIGHT_RED    TL_RED


typedef enum {
    TL_RED = 0,
    TL_GREEN,
    TL_YELLOW
} LightColor;

typedef struct {
    LightColor color;
    uint8_t countdown;
} TrafficLight;

typedef struct {
    LightColor state;
    uint8_t timer;
} TL_StateMachine;

typedef enum {
    MODE_NORMAL = 0,
    MODE_ALLRED
} MainMode;

// 时序参数结构体
typedef struct {
    uint8_t ns_green;
    uint8_t ns_yellow;
    uint8_t ns_red;
    uint8_t ew_green;
    uint8_t ew_yellow;
    uint8_t ew_red;
} TrafficLightTiming;

typedef struct {
    MainMode mode;
    TL_StateMachine ns;
    TL_StateMachine ew;
    struct {
        uint8_t timer;
        TL_StateMachine ns_bak;
        TL_StateMachine ew_bak;
    } allred;

    // 参数集与当前选择
    TrafficLightTiming timing_default;
    TrafficLightTiming timing_extended;
    TrafficLightTiming *timing_current;

    TrafficLight lights[DIR_CNT];
} TrafficLightSystem;

void TrafficLight_Init(TrafficLightSystem* sys);
void TrafficLight_Update(TrafficLightSystem* sys);
void TrafficLight_EnterAllRed(TrafficLightSystem* sys, uint8_t sec);

// 切换时序模式
void TrafficLight_SetExtendedTiming(TrafficLightSystem* sys);
void TrafficLight_SetDefaultTiming(TrafficLightSystem* sys);

#endif