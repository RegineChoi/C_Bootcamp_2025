#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct stack
{
    ElemType data;
    struct stack *next;
} Stack;

// 初始化
Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

// 判断栈是否为空
int isEmpty(Stack *s)
{
    if (s->next == NULL)
    {
        printf("该栈为空\n");
        return 1;
    }
    else
        return 0;
}

// 压栈
int push(Stack *s, ElemType e)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}
int pop(Stack *s, ElemType *del_num)
{
    if (s->next == NULL)
    {
        printf("该栈已空，无法删除\n");
        return 0;
    }
    else
    {
        *del_num = s->next->data;
        Stack *p = s->next;
        s->next = p->next;
        free(p);
        return 1;
    }
}

int getTop(Stack *s, ElemType *num)
{
    if (s->next == NULL)
    {
        printf("该栈已空，无法获取栈顶元素\n");
        return 0;
    }
    else
    {
        *num = s->next->data;
        return 1;
    }
}

// 出栈

int main()
{
    return 0;
}