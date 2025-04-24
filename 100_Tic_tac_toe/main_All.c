#include <stdio.h>
#include <stdbool.h> //布尔函数
#include <ctype.h>   //判断字符类型
#include <stdlib.h>  //随机数需要
#include <time.h>    //随机数的种子需要（当前电脑时间的时间戳）
#include <Windows.h> // Windows下设置颜色

#define SIZE 3

#define HUMAN 'X'
#define COMPUTER 'O'

// 设置玩家下棋和电脑下棋的颜色
void set_color(int color)
{
    static HANDLE hConsole = NULL;
    if (!hConsole)
    {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }
    SetConsoleTextAttribute(hConsole, color);
}

// 棋盘初始化
void init_board(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

//    |   |
// ---|---|---
//    |   |
// ---|---|---
//    |   |
// // 棋盘显示
void print_board(char board[SIZE][SIZE])
{
    // 设置三种颜色：棋盘颜色、玩家的棋子颜色、电脑的棋子颜色
    const int DEFAULT_COLOR = 7;   // 灰白色
    const int HUMAN_COLOR = 12;    // 红色
    const int COMPUTER_COLOR = 10; // 绿色

    int i = 0;
    int j = 0;
    printf("   ");
    for (j = 0; j < SIZE; j++)
    {
        printf(" %d ", j + 1);
        if (j < SIZE - 1)
            printf(" ");
    }
    printf("\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d  ", i + 1);
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == HUMAN)
            {
                set_color(HUMAN_COLOR);
            }
            else if (board[i][j] == COMPUTER)
            {
                set_color(COMPUTER_COLOR);
            }
            else
                set_color(DEFAULT_COLOR);

            printf(" %c ", board[i][j]);
            set_color(DEFAULT_COLOR);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        printf("   ");
        if (i < SIZE - 1)
        {
            for (j = 0; j < SIZE; j++)
            {
                printf("---");
                if (j < SIZE - 1)
                    printf("|");
            }
        }
        printf("\n");
    }

    printf("\n");
}

void get_move(int *row, int *col)
{
    while (1)
    {
        printf("请输入要落子的位置：(格式：行 列，示例：1 2)> ");
        if (scanf("%d %d", row, col) == 2)
        {
            (*row)--;
            (*col)--;
            if (*row >= 0 && *row < SIZE && *col >= 0 && *col < SIZE)
                return;
        }
        printf("输入有误！请输入1 ~ %d的数字\n", SIZE);
        while (getchar() != '\n')
            ;
    }
}

// 电脑下棋
void ai_move(char board[SIZE][SIZE], int *row, int *col)
{
    do
    {
        if (SIZE % 2 == 1 && board[SIZE / 2][SIZE / 2] == ' ')
        {
            *row = SIZE / 2;
            *col = SIZE / 2;
            return;
        }
        *row = rand() % SIZE;
        *col = rand() % SIZE;
    } while (board[*row][*col] != ' ');
}

// 判断胜负
int check_win(char board[SIZE][SIZE])
{
    // 检查行
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == ' ')
            continue;
        bool win = true; // 假设这一行已经连成一行
        for (int j = 1; j < SIZE; j++)
        {
            if (board[i][j] != board[i][0])
            {
                win = false;
                break;
            }
        }
        if (win)
            return 1;
    }

    // 检查列
    for (int j = 0; j < SIZE; j++)
    {

        if (board[0][j] == ' ')
            continue;
        bool win = true;
        for (int i = 1; i < SIZE; i++)
        {
            if (board[i][j] != board[0][j])
            {
                win = false;
                break;
            }
        }
        if (win)
            return 1;
    }

    // 检查主对角线
    if (board[0][0] != ' ')
    {
        bool win = true;
        for (int i = 1; i < SIZE; i++)
        {
            if (board[i][i] != board[0][0])
            {
                win = false;
                break;
            }
        }
        if (win)
            return 1;
    }

    // 检查副对角线
    if (board[0][SIZE - 1] != ' ')
    {
        bool win = true;
        for (int i = 1; i < SIZE; i++)
        {
            if (board[i][SIZE - 1 - i] != board[0][SIZE - 1])
            {
                win = false;
                break;
            }
        }
        if (win)
            return 1;
    }

    // 检查平局
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
                return 0; // 有空位继续游戏
        }
    }

    return 2; // 平局
}

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