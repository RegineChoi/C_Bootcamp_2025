#include "../include/player.h"
#include <stdio.h>

// 玩家下棋
void get_move(int *row, int *col)
{
    while (1)
    {
        printf("请输入要落子的位置：(格式：行 列，示例：1 2)> ");
        if (scanf("%d %d", row, col) == 2)
        {
            (*row)--;
            (*col)--;
            if (*row >= 0 && *row < SIZE && *col >= 0 && *col < SIZE)
                return;
        }
        printf("输入有误！请输入1 ~ %d的数字\n", SIZE);
        while (getchar() != '\n')
            ;
    }
}