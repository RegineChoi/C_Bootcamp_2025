#include "../include/error.h"
#include <stdio.h>

const char *get_error_msg(int code)
{
    switch (code)
    {
    case ERR_FILE_NOT_FOUND:
        return "文件不存在";
    case ERR_FILE_CORRUPTED:
        return "文件已损坏";
    case ERR_READ_FAILURE:
        return "文件读取错误";
    case ERR_WRITE_FAILURE:
        return "文件写入错误";
    case ERR_INVALID_PLAYER:
        return "非法玩家标识";
    case ERR_INVALID_INPUT:
        return "输入格式错误";
    default:
        return "未知错误";
    }
}

void print_error(int code, const char *context)
{
    fprintf(stderr, "[ERR] %s → 错误码：%d (%s)\n",
            context, code, get_error_msg(code));
}
