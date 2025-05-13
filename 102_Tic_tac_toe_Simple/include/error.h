#pragma once

#define ERR_FILE_NOT_FOUND -1
#define ERR_FILE_CORRUPTED -2
#define ERR_READ_FAILURE -3
#define ERR_INVALID_PLAYER -4

const char *get_error_msg(int code);