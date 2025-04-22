#include "../include/ai.h"
#include <stdlib.h> //随机数需要
#include <time.h>   //随机数的种子需要（当前电脑时间的时间戳）

// 电脑下棋
void ai_move(char board[BOARD_SIZE][BOARD_SIZE], int *row, int *col)
{
    do
    {
        if (BOARD_SIZE % 2 == 1 && board[BOARD_SIZE / 2][BOARD_SIZE / 2] == ' ')
        {
            *row = BOARD_SIZE / 2;
            *col = BOARD_SIZE / 2;
            return;
        }
        *row = rand() % BOARD_SIZE;
        *col = rand() % BOARD_SIZE;
    } while (board[*row][*col] != ' ');
}