#include "../include/board.h"
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h> // Windows下设置颜色

// 设置玩家棋子和电脑棋子的颜色
void set_color(int color)
{
    static HANDLE hConsole = NULL;
    if (!hConsole)
    {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }
    SetConsoleTextAttribute(hConsole, color);
}

// 棋盘初始化
void init_board(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// // 棋盘显示
void print_board(char board[SIZE][SIZE])
{
    // 设置三种颜色：棋盘颜色、玩家的棋子颜色、电脑的棋子颜色
    const int DEFAULT_COLOR = 7;   // 灰白色
    const int HUMAN_COLOR = 12;    // 红色
    const int COMPUTER_COLOR = 10; // 绿色

    int i = 0;
    int j = 0;
    printf("   ");
    for (j = 0; j < SIZE; j++)
    {
        printf(" %d ", j + 1);
        if (j < SIZE - 1)
            printf(" ");
    }
    printf("\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d  ", i + 1);
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == HUMAN)
            {
                set_color(HUMAN_COLOR);
            }
            else if (board[i][j] == COMPUTER)
            {
                set_color(COMPUTER_COLOR);
            }
            else
                set_color(DEFAULT_COLOR);

            printf(" %c ", board[i][j]);
            set_color(DEFAULT_COLOR);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        printf("   ");
        if (i < SIZE - 1)
        {
            for (j = 0; j < SIZE; j++)
            {
                printf("---");
                if (j < SIZE - 1)
                    printf("|");
            }
        }
        printf("\n");
    }

    printf("\n");
}

// 判断胜负
int check_win(char board[SIZE][SIZE])
{
    // 检查行
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == ' ')
            continue;
        bool win = true; // 假设这一行已经连成一行
        for (int j = 1; j < SIZE; j++)
        {
            if (board[i][j] != board[i][0])
            {
                win = false;
                break;
            }
        }
        if (win)
            return 1;
    }

    // 检查列
    for (int j = 0; j < SIZE; j++)
    {

        if (board[0][j] == ' ')
            continue;
        bool win = true;
        for (int i = 1; i < SIZE; i++)
        {
            if (board[i][j] != board[0][j])
            {
                win = false;
                break;
            }
        }
        if (win)
            return 1;
    }

    // 检查主对角线
    if (board[0][0] != ' ')
    {
        bool win = true;
        for (int i = 1; i < SIZE; i++)
        {
            if (board[i][i] != board[0][0])
            {
                win = false;
                break;
            }
        }
        if (win)
            return 1;
    }

    // 检查副对角线
    if (board[0][SIZE - 1] != ' ')
    {
        bool win = true;
        for (int i = 1; i < SIZE; i++)
        {
            if (board[i][SIZE - 1 - i] != board[0][SIZE - 1])
            {
                win = false;
                break;
            }
        }
        if (win)
            return 1;
    }

    // 检查平局
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
                return 0; // 有空位继续游戏
        }
    }

    return 2; // 平局
}