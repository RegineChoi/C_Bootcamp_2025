#include <stdio.h>

int main()
{
    int array[] = {15, 16, 17, 18, 19};
    int *p;
    p = array;
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        printf("array[%d]的值为%d\n", i, array[i]);
        printf("array[%d]的地址为%p\n", i, &array[i]);
    }
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        printf("*(p+%d)的值为%d\n", i, *(p + i));
        printf("*(p+%d)的地址为%p\n", i, p + i);
    }

    // printf("a的地址：%p\n", array);
    // printf("a[0]的地址：%p\n", &array[0]);
    // printf("p的地址：%p\n", p);
    // printf("++p的地址：%p\n", ++p);
    // printf("++p的值：%d\n", *p);

    return 0;
}