#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct
{
    Elemtype data[MAXSIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

// 判断队列是否为空
int isEmpty(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("队列为空\n");
        return 1;
    }
    return 0;
}

// 队列出队
Elemtype outQueue(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("队列为空,无法出队\n");
        return 0;
    }
    Elemtype e = q->data[q->front];
    q->front++;
    return e;
}

// 队列入队
int inQueue(Queue *q, Elemtype e)
{
    if (q->rear >= MAXSIZE)
    {
        printf("队列已满，无法入队\n");
        return 0;
    }
    q->data[q->rear] = e;
    q->rear++;
    return 1;
}

int main()
{

    return 0;
}