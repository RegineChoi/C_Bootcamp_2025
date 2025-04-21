#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ATTEMPT 15

// 猜数字游戏：随机生成一个1~100的数x
// 输入一个数字y，当x>y输出y太小；当x<y输出y太大了
// 当x=y时，输出猜对了，并输出你在第n次猜对了
// 扩展功能：使用scanf函数的返回值判断，防止输入非数字造成程序报错；
// 当输入非数字时清空输入缓冲区
// 猜三次都不中的情况下给出提示
// 可以输入0退出游戏

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // printf("【清除缓冲区】字符%c，ASCII码%d", c, c);
    }
    // 清空输入缓冲区
}
void save_record(int count)
{
    FILE *fp = fopen("record.txt", "w");
    if (fp != NULL)
    {
        fprintf(fp, "%s最佳纪录为%d次\n", __TIME__, count);
        fclose(fp);
    }
    else
        perror("保存记录失败！\n");
}

int main()
{
    srand(time(0));
    int magic_num = rand() % 100 + 1;
    printf("猜数字游戏启动,已生成神秘数字X\n");
    printf("你一共有%d次机会猜中数字\n", MAX_ATTEMPT);
    printf("%d\n", magic_num);
    int count = 0;
    int guess_num = 0;
    while (count < MAX_ATTEMPT)
    {
        printf("\n【第%d次尝试】请输入1~100的数字(输入0退出): ", count + 1);
        if (scanf("%d", &guess_num) != 1)
        {
            clear_input_buffer();
            printf("非法输入！请输入数字[范围：1~100]\n");
            continue;
        }
        if (guess_num == 0)
        {
            printf("提前退出游戏，正确答案是%d\n", magic_num);
            system("pause");
            return 0;
        }
        if (guess_num > 100 || guess_num < 1)
        {
            printf("输入数字的范围已超！请输入数字[范围：1~100]\n");
            continue;
        }
        count++;
        int prompt_lower = 0.6 * magic_num; // 提示的范围下限为 60% magic_num
        int prompt_upper = 1.4 * magic_num; // 提示的范围上限为140% magic_num
        prompt_lower = (prompt_lower < 1) ? 1 : prompt_lower;
        prompt_upper = (prompt_upper > 100) ? 100 : prompt_upper;
        if (guess_num > magic_num)
        {
            printf("提示：%d太大了\n", guess_num);
            if (count % 3 == 0)
                printf("建议尝试( %d~%d )\n", prompt_lower, prompt_upper);
        }
        else if (guess_num < magic_num)
        {
            printf("提示：%d太小了\n", guess_num);
            if (count % 3 == 0)
                printf("建议尝试( %d~%d )\n", prompt_lower, prompt_upper);
        }
        else
        {
            printf("你太棒了！你在第%d次尝试中猜中了\n", count);
            switch (count)
            {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                printf("⭐ 天才级表现！\n");
                break;
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                printf("✨ 优秀水平！\n");
            default:
                printf("💪 继续努力！\n");
                break;
            }
            save_record(count);
            system("pause");
            return 0;
        }
        printf("剩余%d次机会\n", MAX_ATTEMPT - count);
    }

    printf("很遗憾！这个神秘数字是%d，下次再接再厉\n", magic_num);
    system("pause");
    return 0;
}