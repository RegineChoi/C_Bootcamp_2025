#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType *data;
    int top;
} Stack;

typedef enum
{
    LEFT_PARE,
    RIGHT_PARE,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    EOS,
    NUM
} contentType;

char expr[] = "82/2+56*-";

// Stack初始化
Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    s->top = -1;
    return s;
}

// 判断栈是否为空
int isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        printf("栈为空\n");
        return 1;
    }
    else
        return 0;
}

// 进栈/压栈
int push(Stack *s, ElemType e)
{
    if (s->top >= MAXSIZE - 1)
    {
        printf("栈已满，无法压栈\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

// 出栈
int pop(Stack *s, ElemType *e)
{
    if (s->top == -1)
    {
        printf("栈已空，无法出栈\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

// 获取栈顶元素
int getTop(Stack *s, ElemType *e)
{
    if (s->top == -1)
    {
        printf("栈已空，无法获取\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

int main()
{

    return 0;
}