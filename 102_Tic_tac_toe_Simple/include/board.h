#pragma once
#define BOARD_SIZE 3

void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int is_board_full(char board[BOARD_SIZE][BOARD_SIZE]);
int check_player_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
void save_board(char board[BOARD_SIZE][BOARD_SIZE]);
int load_board(char *board[BOARD_SIZE]);