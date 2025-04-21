#include <stdio.h>
#include <stdbool.h> //布尔函数
#include <ctype.h>   //判断字符类型
#include <stdlib.h>  //随机数需要
#include <time.h>    //随机数的种子需要（当前电脑时间的时间戳）

#define SIZE 3

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

//    |   |
// ---|---|---
//    |   |
// ---|---|---
//    |   |
// // 棋盘显示
void print_board(char board[SIZE][SIZE])
{
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
            printf(" %c ", board[i][j]);
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

int main()
{
    char board[SIZE][SIZE];
    init_board(board);
    print_board(board);

    int row = 0;
    int col = 0;
    get_move(&row, &col);
    system("pause");
    return 0;
}
