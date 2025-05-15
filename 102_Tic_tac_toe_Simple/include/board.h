#pragma once
#define BOARD_SIZE 3
#define MAX_HISTORY 10
#include <stdbool.h>
#include <time.h>

typedef enum
{
    PLAYING,
    PLAYER1_WIN,
    PLAYER2_WIN,
    DRAW,
    StateError,
} GameState;

// 初始化棋盘
void init_board(char (*board)[BOARD_SIZE]);

// 打印棋盘
void print_board(char (*board)[BOARD_SIZE]);

// 棋盘判满
bool is_board_full(char (*board)[BOARD_SIZE]);

// 判断位置能否下棋
bool is_valid_move(char (*board)[BOARD_SIZE], int row, int col);

// 判断玩家是否胜利
int check_player_win(char (*board)[BOARD_SIZE], char player);

// 检查游戏状态，玩家1胜利，玩家2胜利，平局，继续下棋
GameState check_game_state(char (*board)[BOARD_SIZE], int player);

// 保存棋盘
void save_board(char (*board)[BOARD_SIZE]);
// 加载棋盘
int load_board(char (*board)[BOARD_SIZE]);
// 命名存档
int named_save(char (*board)[BOARD_SIZE], int player);

// 历史记录功能
typedef struct GameHistory
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int player;
    time_t timestamp;
} GameHistory;
void push_history(GameHistory *hist, int *count);
void show_history(const GameHistory *hist, int count);
