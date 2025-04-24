#pragma once
#include "board.h"

#define SAVE_FILE "Tictactoe.sav"

typedef struct
{
    int version;
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player;
} GameSave;

// 保存游戏
int save_game(const GameSave *save);

// 加载游戏
int load_game(GameSave *save);