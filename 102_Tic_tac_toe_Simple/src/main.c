#include "../include/board.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char test_board[3][3] = {
        {'O', 'O', ' '},
        {'X', 'X', ' '},
        {'O', ' ', ' '}};
    char win_board[3][3] = {
        {'X', 'O', 'O'},
        {'X', 'X', 'O'},
        {'O', 'X', 'X'}};
    char load_board_test[BOARD_SIZE][BOARD_SIZE] = {0};

    int ret = load_board(load_board_test);
    if (ret != 1)
    {
        printf("加载失败，错误码：%d/n");
        return EXIT_FAILURE;
    }
    print_board(load_board_test);
    return EXIT_SUCCESS;

    return 0;
}