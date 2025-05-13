#include <stdio.h>

// 打印棋盘的内存地址
void debug_board(char (*board)[3])
{
    printf("棋盘首地址：%p\n", board);
    for (int i = 0; i < 3; i++)
    {
        printf("第%d的首地址：%p\n", i, board[i]);
        for (int j = 0; j < 3; j++)
        {
            printf("第%d第%d的地址：%p\n", i, j, &board[i][j]);
        }
    }
}

int main()
{
    char win_board[3][3] = {
        {'X', 'O', 'O'},
        {'X', 'X', 'O'},
        {'O', 'X', 'X'}};
    debug_board(win_board);
    return 0;
}