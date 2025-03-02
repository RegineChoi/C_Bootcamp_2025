#include "../include/calculator.h"

void scientific_calculator()
{
    float a = 0.0f;
    float b = 0.0f;
    float result = 0.0f;
    char operator= ' ';
    printf("Enter a formula, for example：3 + 5: ");
    scanf("%f %c %f", &a, &operator, & b);
    switch (operator)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (b != 0)
        {
            result = a / b;
        }
        else
        {
            printf("The divisor cannot be 0!\n");
            result = -1;
        }
        break;
    default:
        printf("Input error!");
        result = -1;
    }
    if (result != -1)
    {
        printf("%0.2f %c %0.2f = %0.2f\n", a, operator, b, result);
    }
}