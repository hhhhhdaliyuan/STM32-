#include "BSP_LCD.h"

// 定义浅绿色（草地色），自定义一个比GREEN更淡的色
#define GRASS_LIGHT_GREEN  0xB7E0   // 你可以微调为 0xAFE5、0xCFF3 等更嫩的绿色
#define TREE_LEAF_COLOR    GREEN    // 树叶绿色
#define TREE_TRUNK_COLOR   0xA145   // 棕色，RGB565格式



void Draw_Crossroad_Background(void)
{
    // 竖屏模式，大小为 240x320
    // 道路宽度为80像素

    // 1. 四角草地（左上、右上、左下、右下）
    LcdFill(0, 0, 80, 120, GRASS_LIGHT_GREEN);             // 左上
    LcdFill(160, 0, 80, 120, GRASS_LIGHT_GREEN);           // 右上
    LcdFill(0, 200, 80, 120, GRASS_LIGHT_GREEN);           // 左下
    LcdFill(160, 200, 80, 120, GRASS_LIGHT_GREEN);         // 右下

    // 2. 四角画树
    Draw_Tree(34, 34, 18);     // 左上
    Draw_Tree(206, 34, 18);    // 右上
    Draw_Tree(34, 286, 18);    // 左下
    Draw_Tree(206, 286, 18);   // 右下
}

