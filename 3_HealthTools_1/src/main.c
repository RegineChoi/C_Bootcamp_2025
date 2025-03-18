#include <stdio.h>
#include "bmi.h"
#include "temperature.h"
#include "calculator.h"

int main()
{
    int choice;
    float result;
    while (1)
    {
        printf("\n===== 健康工具 ====\n");
        printf("1. BMI计算器\n");
        printf("2. 温度转换器\n");
        printf("3. 科学计算器\n");
        printf("4. 退出\n");
        printf("请选择：");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            float height;
            float weight;
            printf("请输入身高(m): ");
            scanf("%f", &height);
            printf("请输入体重(kg): ");
            scanf("%f", &weight);
            calculator_bmi(&height, &weight, &result);
            if (result > 0)
                print_bmi_advice(result);
            break;
        case 2:
            float f;
            printf("输入华氏度：");
            scanf("%f", &f);
            float c;
            fahrenhet_to_celsius(&f, &c);
            break;
        case 3:
            float a;
            float b;
            char op;
            printf("请输入算式(如 3 + 5): ");
            scanf("%f %c %f", &a, &op, &b);
            scientific_calculator(&a, &b, &op, &result);
            if (result != -1)
                printf("结果: %.2f\n", result);
            break;
        case 4:
            printf("退出游戏\n");
            return 0;
            break;
        default:
            printf("无效选项！请重新输入！\n");
            break;
        }
    }
    return 0;
}