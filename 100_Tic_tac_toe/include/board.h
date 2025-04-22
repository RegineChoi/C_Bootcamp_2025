#pragma once
#include "global_config.h"

// 设置玩家棋子和电脑棋子的颜色
void set_color(int color);

// 棋盘初始化
void init_board(char board[BOARD_SIZE][BOARD_SIZE]);

//    |   |
// ---|---|---
//    |   |
// ---|---|---
//    |   |
// // 棋盘显示
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);

// 判断胜负
int check_win(char board[BOARD_SIZE][BOARD_SIZE]);