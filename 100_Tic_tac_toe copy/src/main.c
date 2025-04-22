#pragma once
#include "../include/global_config.h"
#include "../include/ai.h"
#include "../include/board.h"
#include "../include/player.h"

int main()
{
    char board[SIZE][SIZE];
    char current_player = HUMAN;
    int game_status = 0;

    init_board(board);
    srand(time(NULL));
    while (1)
    {
        print_board(board);
        if (current_player == HUMAN)
        {
            // 玩家下棋
            int row = 0;
            int col = 0;
            get_move(&row, &col);

            if (board[row][col] == ' ')
            {
                board[row][col] = HUMAN;
            }
            else
            {
                printf("该位置已被占用,重新输入\n");
                continue;
            }
        }
        else
        {
            // 电脑下棋
            int row = 0;
            int col = 0;
            ai_move(board, &row, &col);
            board[row][col] = COMPUTER;
            printf("电脑下在：%d行 %d列\n", row + 1, col + 1);
        }

        game_status = check_win(board);

        if (game_status == 1)
        {
            print_board(board);
            printf("%s获胜！\n", (current_player == HUMAN) ? "玩家" : "电脑");
            break;
        }
        else if (game_status == 2)
        {
            print_board(board);
            printf("平局！\n");
            break;
        }
        current_player = (current_player == HUMAN) ? COMPUTER : HUMAN;
    }
    system("pause");
    return 0;
}