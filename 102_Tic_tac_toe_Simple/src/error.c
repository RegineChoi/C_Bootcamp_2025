#include "../include/error.h"

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
    case ERR_INVALID_PLAYER:
        return "非法玩家标识";
    default:
        return "未知错误";
    }
}
