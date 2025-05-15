#include "../include/board.h"
#include "../include/error.h"
#include <ctype.h>
#include <stdio.h>

bool get_valid_input(int *row, int *col)
{
    char buffer[128];
    if (!fgets(buffer, sizeof(buffer), stdin))
        return false;

    for (char *p = buffer; *p; p++)
    {
        // 如果不是数字也不是空格，则返回false
        if (!isdigit(*p) && !isspace(*p))
            return false;
    }

    // int t = sscanf(butter, "%d %d", *row, *col);
    if (sscanf(buffer, "%d %d", row, col) != 2)
        return false;

    if ((*row < 1 || *row > BOARD_SIZE) ||
        (*col < 1 || *col > BOARD_SIZE))
    {
        print_error(ERR_INVALID_INPUT, "输入越界");
        return false;
    }

    return true;
}

bool get_menu_input(int *choice)
{
    char buffer[128];
    if (!fgets(buffer, sizeof(buffer), stdin))
    {
        return false;
    }

    for (char *p = buffer; *p; p++)
    {
        if (!isdigit(*p) || !isspace(*p))
            return false;
    }

    return (sscanf(buffer, "%d", choice) == 1);
}