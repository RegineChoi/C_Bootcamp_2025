#include "../include/game.h"
#include "../include/input.h"
#include "../include/error.h"

void show_save_menu(char (*board)[BOARD_SIZE], int current_player)
{
    printf("\n----- 存档管理 -----\n");
    printf("1. 快速存档\n");
    printf("2. 命名存档\n");
    printf("3. 返回游戏\n");

    int choice;
    if (get_menu_input(&choice) && choice >= 1 && choice <= 3)
    {
        switch (choice)
        {
        case 1:
            save_board(board);
            break;
        case 2:
        // named_save(board)
        default:
            break;
        }
    }
    else
    {
        print_error(ERR_INVALID_INPUT,"存档菜单管理");
    }
}