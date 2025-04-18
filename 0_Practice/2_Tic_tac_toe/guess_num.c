#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 猜数字游戏，生成一个0~100的随机数x
// 猜测这个数字为y，猜中回复猜中了，并打印经过n次猜中。
// 如果没猜中，输出x>y或者x<y提示。继续猜直至猜中。

int main()
{
    // 种子决定序列：相同的种子产生相同的随机数序列
    // time(0)的作用：获取从1970年1月1日至今的秒数（每秒变化）
    srand(time(0));
    int magic_num = rand() % 100 + 1; // rand（生成的随机数）至少为32767，所以%100，让生成的值为0~99，再加上1变成1~100。
    int guess_num = 0;
    int count = 0;
    printf("=========  猜数字游戏启动  =========\n");
    // printf("%d\n", magic_num);

    while (1)
    {
        printf("请输入一个1~100的数字\n");
        scanf("%d", &guess_num);
        count++;
        if (guess_num >= 1 && guess_num <= 100)
        {
            if (guess_num > magic_num)
            {
                printf("你输入的数字比随机数大，继续猜喔\n");
            }
            else if (guess_num < magic_num)
            {
                printf("你输入的数字比随机数小，继续猜喔\n");
            }
            else
            {
                printf("猜对了！你真棒！！！\n");
                printf("你经过了%d次猜中数字\n", count);
                break;
            }
        }
    }
    return 0;
}