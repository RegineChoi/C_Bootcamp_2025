#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct QueueNode
{
    ElemType data;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

// 队列初始化
Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->data = 0;
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

// 队列判断是否为空
int isEmpty(Queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
        return 0;
}

// 尾插法
int insertTail(Queue *q, ElemType e)
{
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
    return 1;
}

// 队列出队
int outQueue(Queue *q, ElemType *e)
{
    QueueNode *node = q->front->next;
    *e = node->data;
    q->front->next = node->next;
    if (q->rear == node)
    {
        q->rear = q->front;
    }
    free(node);
    return 1;
}

// 获取队头元素
ElemType getTop(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空，无法获取队头元素\n");
        return 0;
    }

    return q->front->next->data;
}

int main()
{
    Queue *q = initQueue();
    insertTail(q, 10);
    insertTail(q, 20);
    insertTail(q, 30);
    ElemType e = 0;
    outQueue(q, &e);
    printf("e=%d\n", e);
    outQueue(q, &e);
    printf("e=%d\n", e);
    printf("q=%d\n", getTop(q));

    return 0;
}