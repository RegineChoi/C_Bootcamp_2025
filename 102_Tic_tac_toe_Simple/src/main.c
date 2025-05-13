#include "../include/board.h"
#include "../include/error.h"
#include "../include/input.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // char test_board[3][3] = {
    //     {'O', 'O', ' '},
    //     {'X', 'X', ' '},
    //     {'O', ' ', ' '}};
    // char win_board[3][3] = {
    //     {'X', 'O', 'O'},
    //     {'X', 'X', 'O'},
    //     {'O', 'X', 'X'}};
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    GameState state = PLAYING;
    int current_player = 1;

    while (state == PLAYING)
    {
        print_board(board);
        printf("玩家%d的回合，请输入行号和列号【范围(1-%d)，示例：2 3】: ", current_player, BOARD_SIZE);
        int input_row;
        int input_col;

        if (!get_valid_input(&input_row, &input_col))
        {
            printf("输入格式错误，请重新输入\n");
            continue;
        }

        int row = input_row - 1;
        int col = input_col - 1;
        if (!is_valid_move(board, row, col))
        {
            printf("该位置不可用，请重新输入\n");
            continue;
        }

        // 落子
        board[row][col] = (current_player == 1) ? 'X' : 'O';

        // 更新状态
        state = check_game_state(board, current_player);
        current_player = (current_player == 1) ? 2 : 1;
    }

    print_board(board);
    switch (state)
    {
    case PLAYER1_WIN:
        printf("玩家1胜利\n");
        break;
    case PLAYER2_WIN:
        printf("玩家2胜利\n");
        break;
    case DRAW:
        printf("平局\n");
        break;
    case StateError:
        printf("玩家标识错误\n");
        break;
    default:
        break;
    }

    return EXIT_SUCCESS;
}