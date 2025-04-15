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

// 表达式为中缀表达式
char expr[] = "x/(i-j)*y";

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

// 获取字符的类型
contentType getToken(char *symbol, int *index)
{
    *symbol = expr[*index];
    *index = *index + 1;
    switch (*symbol)
    {
    case '(':
        return LEFT_PARE;
    case ')':
        return RIGHT_PARE;
    case '+':
        return ADD;
    case '-':
        return SUB;
    case '*':
        return MUL;
    case '/':
        return DIV;
    case '%':
        return MOD;
    case '\0':
        return EOS;
    default:
        return NUM;
    }
}

// 打印字符类型
int print_token(contentType token)
{
    switch (token)
    {
    case ADD:
        printf("+");
        break;
    case SUB:
        printf("-");
        break;
    case MUL:
        printf("*");
        break;
    case DIV:
        printf("/");
        break;
    case MOD:
        printf("%%");
        break;
    default:
        return 0;
    }
    return 1;
}

void postfix(Stack *s)
{
    // 对应枚举中的 0 LEFT_PARE;1 RIGHT_PARE;2 ADD;3 SUB;4 MUL;5 DIV;6 EOS;7 NUM; 的优先级
    int in_stack[] = {0, 19, 12, 12, 13, 13, 13, 0};
    int out_stack[] = {20, 19, 12, 12, 13, 13, 13, 0};
    contentType token;
    int index = 0;
    s->top = 0;
    s->data[0] = EOS;
    char symbol;
    ElemType e;

    token = getToken(&symbol, &index);

    while (token != EOS)
    {
        if (token == NUM)
            printf("%c", symbol);
        else if (token == RIGHT_PARE)
        {
            while (s->data[s->top] != LEFT_PARE)
            {
                pop(s, &e);
                print_token(e);
            }
            pop(s, &e);
        }
        else
        {
            while (in_stack[s->data[s->top]] >= out_stack[token])
            {
                pop(s, &e);
                print_token(e);
            }
            push(s, token);
        }
        token = getToken(&symbol, &index);
    }

    pop(s, &e);
    token = e;
    while (token != EOS)
    {
        print_token(token);
        pop(s, &e);
        token = e;
    }
    printf("\n");
}

int main()
{
    Stack *s = initStack();
    printf("%s\n", expr);
    postfix(s);
    return 0;
}