#define _CRT_SECURE_NO_WARNINGS
#include "../include/menu.h"
#include "../include/bmi.h"
#include "../include/temperature.h"
#include "../include/calculator.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input = 0;
    do
    {
        printMenu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            // 计算BMI值，并打印健康建议
            calculateBMI();
            printHealthAdvice();
            break;
        case 2:
            // 华氏温度转换成摄氏温度
            convertTemperature();
            break;
        case 3:
            // 科学计算器
            scientific_calculator();
            break;
        case 0:
            printf("quit\n");
            break;
        default:
            printf("Input error\n");
        }
    } while (input != 0);

    system("pause"); // 等待用户按下任意键
    return 0;
}