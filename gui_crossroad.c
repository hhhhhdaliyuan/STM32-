#include "BSP_LCD.h"

// ����ǳ��ɫ���ݵ�ɫ�����Զ���һ����GREEN������ɫ
#define GRASS_LIGHT_GREEN  0xB7E0   // �����΢��Ϊ 0xAFE5��0xCFF3 �ȸ��۵���ɫ
#define TREE_LEAF_COLOR    GREEN    // ��Ҷ��ɫ
#define TREE_TRUNK_COLOR   0xA145   // ��ɫ��RGB565��ʽ



void Draw_Crossroad_Background(void)
{
    // ����ģʽ����СΪ 240x320
    // ��·���Ϊ80����

    // 1. �Ľǲݵأ����ϡ����ϡ����¡����£�
    LcdFill(0, 0, 80, 120, GRASS_LIGHT_GREEN);             // ����
    LcdFill(160, 0, 80, 120, GRASS_LIGHT_GREEN);           // ����
    LcdFill(0, 200, 80, 120, GRASS_LIGHT_GREEN);           // ����
    LcdFill(160, 200, 80, 120, GRASS_LIGHT_GREEN);         // ����

    // 2. �Ľǻ���
    Draw_Tree(34, 34, 18);     // ����
    Draw_Tree(206, 34, 18);    // ����
    Draw_Tree(34, 286, 18);    // ����
    Draw_Tree(206, 286, 18);   // ����
}

