#include <stdio.h>

struct point
{
    int x;
    int y;
};

int main()
{
    struct point p;
    p.x = 5;
    p.y = 10;
    struct point *pp;
    pp = &p;
    pp->x = 10;
    pp->y = 5;
    printf("p.x的值为：%d\n", p.x);
    printf("p.y的值为：%d\n", p.y);
    printf("p.x的地址为：%p\n", &(p.x));
    printf("p.y的地址为：%p\n", &(p.y));

    printf("(*pp).x的值为：%d\n", (*pp).x);
    printf("(*pp).y的值为：%d\n", (*pp).y);
    printf("(*pp).x的地址为：%p\n", &((*pp).x));
    printf("(*pp).y的地址为：%p\n", &((*pp).y));
    printf("pp->x的值为：%d\n", pp->x);
    printf("pp->y的值为：%d\n", pp->y);
    return 0;
}