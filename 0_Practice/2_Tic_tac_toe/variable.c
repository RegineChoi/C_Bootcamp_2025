#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    printf("%d\n", 5 / 2);     // → 2（整数除法）
    printf("%.2f\n", 5.0 / 2); // → 2.50
    // Sleep(1000);
    int x = 5;
    int y = 3;
    printf("%d %d\n", x, y);
    x ^= y;
    y ^= x;
    x ^= y;
    printf("%d %d\n", x, y);
    y = x ^ y;
    x = x ^ y;
    y = x ^ y;
    printf("%d %d\n", x, y);

    return 0;
}