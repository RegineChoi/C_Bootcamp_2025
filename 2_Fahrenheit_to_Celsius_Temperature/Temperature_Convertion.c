#include <stdio.h>
// 精简版华氏转摄氏（15行内完成）

int main()
{
    float f;
    printf("Input ℉: ");
    if (scanf("%f", &f) != 1)
    {
        printf("Invalid input!");
        return 1;
    }
    printf("= %.2f℃\n", (f - 32) * 5 / 9);
    return 0;
}