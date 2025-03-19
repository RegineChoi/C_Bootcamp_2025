#include <stdio.h>

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        printf("array[%d]的值为：%d\n", i, array[i]);
    }
    printf("修改array[]的值\n");
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        array[i] = 10 + i;
    }
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        printf("新array[%d]的值为：%d\n", i, array[i]);
    }

    return 0;
}