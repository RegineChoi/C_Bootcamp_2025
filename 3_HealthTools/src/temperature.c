#include "temperature.h"

void convertTemperature()
{
    float fahrenheit = 0.0f;
    float celsius = 0.0f;
    printf("Input ℉: ");
    while (scanf("%f", &fahrenheit) != 1)
    {
        printf("Invalid input!\n");
        printf("Please Input ℉: ");
        scanf("%f", &fahrenheit);
    }
    printf("celsius= %.2f℃\n", (fahrenheit - 32) * 5 / 9);
}