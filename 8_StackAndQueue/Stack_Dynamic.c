#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

// 栈的基本操作有进栈push和出栈pop
typedef struct
{
    ElemType *data;
    int top;
} Stack;

// 初始化栈
// 栈的顺序结构初始化 - 动态内存分配
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
        printf("该栈为空\n");
        return 1;
    }
    else
        return 0;
}

// 压栈操作
int push(Stack *s, ElemType e)
{
    if (s->top >= MAXSIZE - 1)
    {
        printf("该栈满了\n");
        return 0;
    }
    else
    {
        s->top++;
        s->data[s->top] = e;
        return 1;
    }
}

// 出栈操作
int pop(Stack *s, ElemType *e)
{
    if (s->top == -1)
    {
        printf("该栈为空\n");
        return 0;
    }

    *e = s->data[s->top];
    s->top--;
    return 1;
}

// 去栈顶元素
int getTop(Stack *s, ElemType *e)
{
    if (s->top == -1)
    {
        printf("该栈为空\n");
        return 0;
    }

    *e = s->data[s->top];
    return 1;
}

int main()
{
    Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    ElemType output = 0;
    pop(&s, &output);
    printf("取出的数为%d\n", output);
    pop(&s, &output);
    printf("取出的数为%d\n", output);
    getTop(&s, &output);
    printf("栈顶元素为%d\n", output);
    getTop(&s, &output);
    printf("栈顶元素为%d\n", output);
}