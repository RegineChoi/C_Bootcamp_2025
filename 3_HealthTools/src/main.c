// #include "../include/bmi.h"
// #include "include/calculator.h"
// #include "include/temperature.h"
#include "bmi.h"
#include <stdio.h>

int main()
{
    float height_m = 0.0f;
    float weight_kg = 0.0f;
    printf("Intput height(m) and Input weight(kg): ");
    scanf("%f %f", &height_m, &weight_kg);
    float BMI = 0.0f;
    BMI = calculateBMI(height_m, weight_kg);
    // // printHealthAdvice(BMI);
    printf("%.2f\n", BMI);
    getchar();

    return 0;
}