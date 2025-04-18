#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <ctype.h> // 新增isdigit校验

#define MAX_ATTEMPTS 15 // 增加尝试限制

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // printf("[DEBUG] 清除字符：%c (ASCII %d)\n", c, c); // 调试语句
    }
    // 清空输入缓冲区
}

int main()
{
    srand(time(0));
    int magic_num = rand() % 100 + 1;
    int guess_num = 0;
    int count = 0;
    int prompt_lower = magic_num * 0.6; // 下界调整为60%
    int prompt_upper = magic_num * 1.4; // 上届调整为140%
    prompt_lower = (prompt_lower < 1) ? 1 : prompt_lower;
    prompt_upper = (prompt_upper > 100) ? 100 : prompt_upper;

    printf("========= 猜数字游戏v2.0 =========\n");
    printf("神秘数字已生成，你有%d次机会！\n", MAX_ATTEMPTS);

    while (count < MAX_ATTEMPTS)
    {
        printf("\n【第%d次尝试】请输入1-100的数字（输入0退出）: ", count + 1);
        // 通过scanf返回值判断输入的是数字
        if (scanf("%d", &guess_num) != 1)
        { // 检测输入有效性
            clear_input_buffer();
            printf("⚠️ 非法输入！请输入数字！\n");
            continue;
        }

        if (guess_num == 0)
        {
            printf("提前退出游戏，正确答案是%d\n", magic_num);
            return 0;
        }

        if (guess_num < 1 || guess_num > 100)
        {
            printf("⚠️ 输入超出范围！请确认1-100之间\n");
            continue;
        }

        count++;

        if (guess_num > magic_num)
        {
            printf("↘️ 提示：%d 太大了！", guess_num);
            if (count % 3 == 0)
                printf("（建议尝试 %d~%d）", prompt_lower, prompt_upper);
        }
        else if (guess_num < magic_num)
        {
            printf("↗️ 提示：%d 太小了！", guess_num);
            if (count % 3 == 0)
                printf("（建议尝试 %d~%d）", prompt_lower, prompt_upper);
        }
        else
        {
            printf("\n🎉 太棒了！你在第%d次猜中！\n", count);
            switch (count)
            {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                printf("⭐ 天才级表现！");
                break;
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                printf("✨ 优秀水平！");
                break;
            default:
                printf("💪 继续努力！");
            }
            system("pause");
            return 0;
        }

        printf("\n剩余机会：%d\n", MAX_ATTEMPTS - count);
    }

    printf("\n❌ 很遗憾，正确答案是%d。再接再厉！\n", magic_num);
    return 0;
}
