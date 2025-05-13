#pragma once

typedef enum
{
    ERR_NONE = 0,
    ERR_FILE_NOT_FOUND = -1,
    ERR_FILE_CORRUPTED = -2,
    ERR_READ_FAILURE = -3,
    ERR_WRITE_FAILURE = -4,
    ERR_INVALID_PLAYER = -5,
    ERR_INVALID_INPUT = -6,

} ErrorCode;

const char *get_error_msg(int code);
void print_error(int code, const char *context);