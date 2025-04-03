#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 4
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

// 队列入队
int inQueue(Queue *q, Elemtype e)
{
    if ((q->rear + 1) % MAXSIZE == q->front)
    {
        printf("队列已满，无法入队\n");
        return 0;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}
// 队列出队
int outQueue(Queue *q, Elemtype *e)
{
    if (q->front == q->rear)
    {
        printf("队列为空,无法出队\n");
        return 0;
    }
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
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
    inQueue(q, 40);
    Elemtype e;
    outQueue(q, &e);
    printf("%d\n", e);
    outQueue(q, &e);
    printf("%d\n", e);
    getHead(q, &e);
    printf("%d\n", e);

    return 0;
}