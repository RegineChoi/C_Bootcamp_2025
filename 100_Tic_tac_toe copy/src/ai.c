#include "../include/ai.h"
#include <stdlib.h> //随机数需要
#include <time.h>   //随机数的种子需要（当前电脑时间的时间戳）

// 电脑下棋
void ai_move(char board[SIZE][SIZE], int *row, int *col)
{
    do
    {
        if (SIZE % 2 == 1 && board[SIZE / 2][SIZE / 2] == ' ')
        {
            *row = SIZE / 2;
            *col = SIZE / 2;
            return;
        }
        *row = rand() % SIZE;
        *col = rand() % SIZE;
    } while (board[*row][*col] != ' ');
}