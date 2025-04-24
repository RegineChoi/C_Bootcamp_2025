#include "../include/global_config.h"
#include "../include/ai.h"
#include "../include/board.h"
#include "../include/player.h"
#include "../include/save.h"
#include <stdio.h>
#include <stdbool.h> //布尔函数
#include <ctype.h>   //判断字符类型
#include <stdlib.h>  //随机数需要
#include <time.h>    //随机数的种子需要（当前电脑时间的时间戳）
#include <Windows.h> // Windows下设置颜色

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player = HUMAN;
    int game_status = 0;

    init_board(board);
    srand(time(NULL));
    while (1)
    {
        print_board(board);

        // 新增存档菜单
        printf("输入操作：\n"
               "S - 保存游戏\n"
               "L - 读取存档\n"
               "其他 - 继续游戏\n");
        char cmd_input;
        if (scanf("%c", &cmd_input) == 1)
        {

            if (cmd_input == 'S' || cmd_input == 's')
            {
                GameSave save = {.version = 1,
                                 .current_player = current_player};
                memcpy(save.board, board, sizeof(board)); // 复制棋盘状态
                if (save_game(&save))
                {
                    printf("存档成功！\n");
                }
                else
                    printf("存档失败！\n");
            }

            else if (cmd_input == 'L' || cmd_input == 'l')
            {
                GameSave save;
                if (load_game(&save))
                {
                    memcpy(board, save.board, sizeof(board));
                    current_player = save.current_player;
                    printf("读档成功\n");
                    print_board(board);
                }
                else
                    printf("读档失败\n");
            }
        }

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