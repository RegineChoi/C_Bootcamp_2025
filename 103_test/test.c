#include <stdio.h>
#include <ctype.h>

#define BOARD_SIZE 3

int get_valid_input(int *row, int *col)
{
    char buffer[128];
    printf("请输入行列（示例：1 2）：");

    // 模拟实际输入流程
    fgets(buffer, sizeof(buffer), stdin);
    printf("原始输入内容：[%s]\n", buffer); // 显示实际内容

    // 清理非法字符（您的原始逻辑）
    for (char *p = buffer; *p; ++p)
    {
        if (!isdigit(*p) && !isspace(*p))
        {
            printf("检测到非法字符：ASCII %d\n", *p);
            return 0;
        }
    }

    // 解析输入
    int ret = sscanf(buffer, "%d %d", row, col);
    printf("sscanf返回值：%d\n", ret); // 关键输出

    return (ret == 2) && (*row >= 1 && *row <= BOARD_SIZE) && (*col >= 1 && *col <= BOARD_SIZE);
}

int main()
{
    int row, col;
    while (1)
    {
        if (get_valid_input(&row, &col))
        {
            printf("有效输入：row=%d, col=%d\n", row, col);
        }
        else
        {
            printf("输入无效！\n");
        }
    }
    return 0;
}
