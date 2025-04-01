#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int main()
{

    return 0;
}