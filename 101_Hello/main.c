#include <stdio.h>

// 温度转换程序（教材P45案例）
int main()
{
    float fahr, celsius;
    printf("请输入华氏温度：");
    scanf("%f", &fahr);
    celsius = 5.0 / 9.0 * (fahr - 32);
    printf("%.2f华氏度 = %.1f摄氏度\n", fahr, celsius);
    printf("[DEBUG]输入：%.2f，计算结果：%.2f\n", fahr, celsius);

    return 0;
}