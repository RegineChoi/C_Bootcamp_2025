#include <stdio.h>

int main()
{
    int a = 100;
    int b = 200;
    int *pa;
    int *pb;
    pa = &a;
    pb = &b;
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", pa);
    printf("%p\n", pb);
    printf("%d\n", *pa);
    printf("%d\n", *pb);
    return 0;
}