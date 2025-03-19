#include <stdio.h>

struct point
{
    int x;
    int y;
};

struct point creatPoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int main()
{
    int a = 10;
    int b = 20;
    struct point pp;
    pp = creatPoint(a, b);
    printf("pp->x的值为：%d\n", pp.x);
    printf("pp->y的值为：%d\n", pp.y);
    return 0;
}