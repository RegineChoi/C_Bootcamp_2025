#include "bmi.h"

float height_m = 0.0f;
float weight_kg = 0.0f;
float BMI = 0.0f;

// 计算BMI
void calculateBMI()
{
    printf("Intput height(m) and Input weight(kg): ");
    scanf("%f %f", &height_m, &weight_kg);
    BMI = weight_kg / (height_m * height_m);
    printf("BMI %0.2f,", BMI);
}

// 打印健康建议
void printHealthAdvice()
{
    if (BMI)
    {
        if (BMI >= 18.5 && BMI <= 24)
        {
            printf("Normal, continue to maintain\n");
        }
        else if (BMI < 18.5)
        {
            printf("Thin, need to gain weight\n");
        }
        else
            printf("Fat, need to lose weight\n");
    }
    else
        printf("Error, please check\n");
}
