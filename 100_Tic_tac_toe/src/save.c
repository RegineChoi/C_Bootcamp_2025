#include "../include/save.h"
#include <stdio.h>

// 保存游戏
int save_game(const GameSave *save)
{
    FILE *fp = fopen(SAVE_FILE, "wb");
    if (!fp)
    {
        printf("错误：无法创建存档文件\n");
        return 0;
    }

    int write_ok = 1;
    // 版本号
    if (fwrite(&save->version, sizeof(int), 1, fp) != 1)
    {
        printf("错误：版本号写入失败\n");
        write_ok = 0;
    }

    // 棋盘尺寸
    if (fwrite(&save->board_size, sizeof(int), 1, fp) != 1)
    {
        printf("错误：棋盘尺寸写入失败\n");
        write_ok = 0;
    }

    // 棋盘数据
    const size_t board_data_size = save->board_size * save->board_size;
    if (write_ok && fwrite(save->board, sizeof(char), board_data_size, fp) != board_data_size)
    {
        printf("错误：棋盘数据写入不完整\n");
        write_ok = 0;
    }

    // 当前玩家

    if (write_ok && fwrite(&save->current_player, sizeof(char), 1, fp) != 1)
    {
        printf("错误：玩家状态写入失败\n");
        write_ok = 0;
    }

    fclose(fp);
    return write_ok;
}

// 加载游戏
int load_game(GameSave *load)
{
    FILE *fp = fopen(SAVE_FILE, "rb");
    if (!fp)
    {
        printf("错误：存档文件不存在\n");
        return 0;
    }

    int read_ok = 1;

    // 读取版本号
    if (fread(&load->version, sizeof(int), 1, fp) != 1)
    {
        printf("错误：版本号读取失败\n");
        read_ok = 0;
    }

    // 读取棋盘尺寸
    if (read_ok && fread(&load->board_size, sizeof(int), 1, fp) != 1)
    {
        printf("错误：棋盘尺寸读取失败\n");
        read_ok = 0;
    }

    // 尺寸校验
    if (read_ok && load->board_size != BOARD_SIZE)
    {
        printf("错误：棋盘尺寸不匹配（存档：%d 当前：%d）\n", load->board_size, BOARD_SIZE);
        read_ok = 0;
    }

    // 读取棋盘数据
    const size_t expect_data = BOARD_SIZE * BOARD_SIZE;
    if (read_ok && fread(load->board, sizeof(char), expect_data, fp) != expect_data)
    {
        printf("错误：棋盘数据不完整\n");
        read_ok = 0;
    }

    if (read_ok && fread(&load->current_player, sizeof(char), 1, fp) != 1)
    {
        printf("错误：玩家状态读取失败\n");
        read_ok = 0;
    }
    fclose(fp);
    return read_ok;
}
