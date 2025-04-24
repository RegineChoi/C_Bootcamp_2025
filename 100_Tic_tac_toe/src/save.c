#include "../include/save.h"
#include <stdio.h>

// 保存游戏
int save_game(const GameSave *save)
{
    FILE *fp = fopen(SAVE_FILE, "w");
    if (!fp)
    {
        return 0;
    }

    size_t written = fwrite(save, sizeof(GameSave), 1, fp);
    fclose(fp);

    return written == 1;
}

// 加载游戏
int load_game(GameSave *save)
{
    FILE *fp = fopen(SAVE_FILE, "r");
    if (!fp)
    {
        printf("错误：存档文件不存在\n");
        return 0;
    }
    size_t read = fread(save, sizeof(GameSave), 1, fp);
    fclose(fp);

    return read == 1;
}
