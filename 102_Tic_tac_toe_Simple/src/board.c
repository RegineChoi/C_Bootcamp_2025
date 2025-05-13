#include "../include/board.h"
#include "../include/error.h"
#include <stdio.h>
#include <time.h>

// 初始化棋盘
void init_board(char (*board)[BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// 打印棋盘
void print_board(char (*board)[BOARD_SIZE])
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

// 判断位置能否下棋
bool is_valid_move(char (*board)[BOARD_SIZE], int row, int col)
{
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
        return false;
    else
        return board[row][col] == ' ';
}

// 检查游戏状态，玩家1胜利，玩家2胜利，平局，继续下棋
GameState check_game_state(char (*board)[BOARD_SIZE], int player)
{
    if (player < 1 || player > 2)
    {
        print_error(ERR_INVALID_PLAYER, "玩家标识越界");
        return StateError;
    }

    char symbol = (player == 1) ? 'X' : 'O';
    if (check_player_win(board, symbol))
        return (player == 1) ? PLAYER1_WIN : PLAYER2_WIN;

    // 检查是否平局
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
                return PLAYING;
        }
    }
    return DRAW;
}

// 棋盘判满
bool is_board_full(char (*board)[BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

// 判断玩家是否胜利
int check_player_win(char (*board)[BOARD_SIZE], char player)
{
    if (player != 'X' && player != 'O')
    {
        fprintf(stderr, "错误：非法玩家错误标志符“%c”", player);
        return 0;
    }
    // 检查行
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }

    // 检查列
    for (int j = 0; j < BOARD_SIZE; j++)
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

// 保存棋盘
void save_board(char (*board)[BOARD_SIZE])
{
    FILE *fp = fopen("save.bin", "wb");
    if (!fp)
    {
        print_error(ERR_FILE_NOT_FOUND, "文件存档");
        return;
    }

    // 定义文件头
    struct header
    {
        char magic[4];
        time_t timestamp
    } Header = {{'T', 'I', 'C', 'T'}, time(NULL)};

    // 写入文件头
    if (fwrite(&Header, sizeof(Header), 1, fp) != 1)
    {
        print_error(ERR_WRITE_FAILURE, "写入文件头");
        fclose(fp);
        return;
    }

    if (fwrite(board, sizeof(char), BOARD_SIZE * BOARD_SIZE, fp) != BOARD_SIZE * BOARD_SIZE)
    {
        print_error(ERR_WRITE_FAILURE, "写入棋盘数据");
    }
    fclose(fp);
}

// 加载棋盘
int load_board(char (*board)[BOARD_SIZE])
{
    FILE *fp = fopen("save.bin", "rb");
    if (!fp)
    {
        print_error(ERR_FILE_NOT_FOUND, "加载存档");
        return ERR_FILE_NOT_FOUND;
    }

    // 读取文件头
    struct header
    {
        char magic[4];
        time_t timestamp;
    } Header;
    if (fread(&Header, sizeof(Header), 1, fp) != 1)
    {
        print_error(ERR_READ_FAILURE, "读取文件头");
        fclose(fp);
        return ERR_READ_FAILURE;
    }

    // 魔数校验
    if (memcmp(Header.magic, "TICT", 4) != 0)
    {
        print_error(ERR_FILE_CORRUPTED, "魔数校验失败");
        fclose(fp);
        return ERR_FILE_CORRUPTED;
    }

    size_t read = fread(board, sizeof(char), BOARD_SIZE * BOARD_SIZE, fp);
    fclose(fp);

    if (read != BOARD_SIZE * BOARD_SIZE)
    {
        print_error(ERR_FILE_CORRUPTED, "读取棋盘数据\n");
        fclose(fp);
        return ERR_FILE_CORRUPTED;
    }

    return ERR_NONE;
}

// 命名存档
int named_save(char (*board)[BOARD_SIZE], int player)
{
    char filename[50];
    printf("输入存档名，不需要输入后缀名：>");
    scanf("%49s", filename);

    // 获取当前时间戳（从1970-1-1开始的秒数）
    // 转换为本地时间的结构体
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char fullname[100];
    snprintf(fullname, sizeof(fullname), "%s_%04d%02d%02d.bin", filename, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    FILE *fp = fopen(fullname, "wb");
    if (!fp)
        return ERR_FILE_NOT_FOUND;

    struct
    {
        time_t timestamp;
        int player;
    } meta = {now, player};

    fwrite(&meta, sizeof(meta), 1, fp);
    fwrite(board, sizeof(char), BOARD_SIZE * BOARD_SIZE, fp);
    fclose(fp);
    return ERR_NONE;
}

void push_history(GameHistory *hist, int *count)
{
    if (*count < MAX_HISTORY)
        (*count)++;
    memmove(hist + 1, hist, sizeof(GameHistory) * (*count - 1));
}
void show_history(const GameHistory *hist, int count)
{
}