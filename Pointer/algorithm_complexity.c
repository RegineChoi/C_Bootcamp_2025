#include <stdio.h>

int main()
{
    int i = 0;
    int x = 90;
    int y = 100;
    while (y > 0)
    {
        i++;
        if (x > 100)
        {
            x = x - 10;
            y--;
        }
        else
        {
            x++;
        }
    }
    printf("i=%d\n", i);
    return 0;
}