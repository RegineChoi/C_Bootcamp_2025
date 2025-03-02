#include <stdio.h>
#include "bmi.h"

void calculator_bmi(float *height, float *weight, float *result)
{
    if (*height <= 0 || *weight <= 0)
    {
        printf("错误！身高和体重必须为正数！\n");
        *result = -1;
        return;
    }

    *result = *weight / (*height * *height);
}

void print_bmi_advice(float bmi)
{
    printf("您的BMI值为%.1f\n", bmi);
    if (bmi < 18.5)
        printf("建议：增重\n");
    else if (bmi < 24)
        printf("建议：继续保持\n");
    else
        printf("建议：减重\n");
}