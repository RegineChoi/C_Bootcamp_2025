#include "../include/board.h"
#include <stdio.h>
#include <stdbool.h>

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    // 打印列号标签
    printf("   ");
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        printf(" %d ", j + 1);
        if (j < BOARD_SIZE - 1)
            printf(" ");
    }
    printf("\n");
    // 打印棋盘
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // 打印行号标签
        printf(" %d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            // 打印每个单元格的数值
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1)
            {
                // 打印列分隔符
                printf("|");
            }
        }
        printf("\n");

        if (i < BOARD_SIZE - 1)
        {
            // 对齐行号部分
            printf("   ");
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                // 打印行分隔符
                printf("---");
                if (j < BOARD_SIZE - 1)
                {
                    printf("|");
                }
            }
        }
        printf("\n");
    }
}
int is_board_full(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

int check_player_win(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    if (player != 'X' && player != 'O')
    {
        fprintf(stderr, "错误：非法玩家错误标志符“%c”", player);
        return 0;
    }
    // 检查行
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }

    // 检查列
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }

    // 检查主对角线
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    // 检查副对角线
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    return 0;
}

void save_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    FILE *fp = fopen("save.bin", "wb");
    if (!fp)
    {
        printf("错误：存档文件不存在\n");
        return;
    }
    fwrite(board, sizeof(char), BOARD_SIZE * BOARD_SIZE, fp);
    fclose(fp);
    printf("保存成功\n");
}

int load_board(char (*board)[BOARD_SIZE])
{
    FILE *fp = fopen("save.bin", "rb");
    if (!fp)
    {
        fprintf(stderr, "错误：存档文件不存在\n");
        return -1;
    }

    // 获取文件大小
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    if (size != BOARD_SIZE * BOARD_SIZE)
    {
        fprintf(stderr, "错误：存档文件损坏\n");
        fclose(fp);
        return -2;
    }

    size_t read = fread(board, sizeof(char), BOARD_SIZE * BOARD_SIZE, fp);
    fclose(fp);

    return (read == BOARD_SIZE * BOARD_SIZE) ? 1 : -3;
}