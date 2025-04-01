#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *prev;
    struct node *next;
} Node;

// 链表初始化
Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;
    return head;
}

// 求链表尾指针
Node *getTail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
// 尾插法
Node *insertTail(Node *tail, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->prev = tail;
    p->next = NULL;

    tail->next = p;
    return p;
}

// 头插法 作业DoubleLinkList1
int insertHead(Node *head, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->prev = head;
    p->next = head->next;

    if (head->next != NULL)
    {
        // 判断队列是否有节点，如果有节点，第一个节点的prev设置为p
        head->next->prev = p;
    }
    head->next = p;
    return 1;
}

// 从头开始遍历链表
void displayHeadList(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 从尾开始遍历链表
void displayTailList(Node *L)
{
    Node *p = getTail(L);
    while (p->prev != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

// 在指定位置插入节点
int insertNode(Node *head, int pos, ElemType e)
{
    Node *p = head;
    for (int i = 0; i < pos - 1; i++)
    {
        if (p != NULL)
            p = p->next;
        else
            return 0;
    }
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = e;
    temp->prev = p;
    temp->next = p->next;

    if (p->next != NULL)
    {
        p->next->prev = temp;
    }
    p->next = temp;
    return 1;
}

// 在指定位置删除节点
int deleteNode(Node *head, int pos)
{
    Node *p = head;
    Node *q = NULL;
    for (int i = 0; i < pos - 1; i++)
    {
        if (p != NULL)
            p = p->next;
        else
            return 0;
    }
    if (p->next != NULL)
    {
        q = p->next;
    }
    else
    {
        return 0;
    }
    p->next = q->next;
    if (q->next != NULL)
        q->next->prev = p;
    free(q);
    return 1;
}

// // 删除指定位置的节点
// void deleteNode(Node *L, int pos)
// {
//     Node *p = L;
//     Node *q = L;
//     int i = 0;
//     for (i = 0; i < pos - 1; i++)
//     {
//         p = p->next;
//     }
//     q = p->next;
//     p->next = q->next;
//     free(q);
// }

// // 获取表链的长度
// int getLength(Node *L)
// {
//     Node *p = L;
//     int i = 0;
//     while (p->next != NULL)
//     {
//         i++;
//         p = p->next;
//     }
//     printf("表长度为%d\n", i);
// }

// // 释放链表
// void freeList(Node *L)
// {
//     Node *p = L->next;
//     Node *q = L->next;
//     while (p != NULL)
//     {
//         p = p->next;
//         free(q);
//         q = p;
//     }
//     L->next = NULL;
// }
int main()
{
    Node *list = initList();
    // displayHeadList(list);
    Node *tail = getTail(list);
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail, 30);

    // insertHead(list, 10);
    // insertHead(list, 20);
    // insertHead(list, 30);
    insertNode(list, 2, 40);
    displayHeadList(list);
    deleteNode(list, 5);

    displayHeadList(list);
    // displayTailList(list);

    return 0;
}