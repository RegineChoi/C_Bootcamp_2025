#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 3; i > 0; i--)
    {
        printf("%d\n", i);
    }
    printf("go!\n");

    printf(__TIME__);
    printf("\n");

    return 0;
}