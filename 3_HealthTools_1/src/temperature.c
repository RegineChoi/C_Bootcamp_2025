#include <stdio.h>
#include "temperature.h"

void fahrenhet_to_celsius(float *f, float *c)
{
    *c = (*f - 32) * 5 / 9;
    printf("%.2f℉ = %.2f℃\n", *f, *c);
}