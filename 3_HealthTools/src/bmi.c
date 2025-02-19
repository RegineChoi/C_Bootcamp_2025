// #include "../include/bmi.h"
#include "bmi.h"
#include <stdio.h>

// 计算BMI
float calculateBMI(float height_m, float weight_kg)
{
    float BMI = 0.0;
    BMI = weight_kg / (height_m * height_m);
    return BMI;
}

// // 打印健康建议
// void printHealthAdvice(float BMI)
// {
//     printf("BMI %0.2f,", BMI);
//     if (BMI >= 18.5 || BMI <= 24)
//     {
//         printf("Normal, continue to maintain\n");
//     }
//     else if (BMI < 18.5)
//     {
//         printf("Thin, need to gain weight\n");
//     }
//     else
//         printf("Fat, need to lose weight\n");
// }
