#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct
{
    Elemtype *data;
    int front;
    int rear;
} Queue;

// 初始化队列
Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (Elemtype *)malloc(sizeof(Elemtype) * MAXSIZE);
    q->front = 0;
    q->rear = 0;
    return q;
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

// 判断队列是否满
int isQueueFull(Queue *q)
{
    if (q->front > 0)
    {
        int diff = q->front;
        for (int i = q->front; i <= q->rear; i++)
        {
            q->data[i - diff] = q->data[i];
        }
        q->rear = q->rear - diff;
        q->front = 0;
        return 0;
    }
    else
    {
        printf("队列真的满了\n");
        return 1;
    }
}

// 队列入队
int inQueue(Queue *q, Elemtype e)
{
    if (q->rear >= MAXSIZE)
    {
        if (isQueueFull(q))
        {
            return 0;
        }
    }
    q->data[q->rear] = e;
    q->rear++;
    return 1;
}

// 获取队头元素
int getHead(Queue *q, Elemtype *e)
{
    if (q->front == q->rear)
    {
        printf("队列为空，无法获取队头元素\n");
        return 0;
    }
    *e = q->data[q->front];
    return 1;
}

int main()
{
    Queue *q = initQueue();
    inQueue(q, 10);
    inQueue(q, 20);
    inQueue(q, 30);
    Elemtype output = 0;
    getHead(q, &output);
    printf("\n%d\n", output);
    outQueue(q);
    outQueue(q);
    getHead(q, &output);
    printf("\n%d\n", output);
    return 0;
}