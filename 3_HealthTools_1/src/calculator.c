#include <stdio.h>
#include "calculator.h"

void scientific_calculator(float *a, float *b, char *op, float *result)
{
    switch (*op)
    {
    case '+':
        *result = *a + *b;
        break;
    case '-':
        *result = *a - *b;
        break;
    case '*':
        *result = *a * *b;
        break;
    case '/':
        if (*b == 0)
        {
            printf("错误！除数不能为零！\n");
            *result = -1;
            return;
        }
        else
            *result = *a / *b;
        break;

    default:
        printf("错误：无效运算符！\n");
        *result = -1;
        break;
    }
}