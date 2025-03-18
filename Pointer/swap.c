#include <stdio.h>

void swapp_point(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int m = 5;
    int n = 10;
    printf("m=%d;n=%d\n", m, n);
    swap(m, n);
    printf("swap:m=%d;n=%d\n", m, n);
    swapp_point(&m, &n);
    printf("swap_point:m=%d;n=%d\n", m, n);
    return 0;
}