#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *link;
} Node;

// 链表初始化
Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->link = NULL;
    return head;
}

// 求链表尾指针
Node *getTail(Node *L)
{
    Node *p = L;
    while (p->link != NULL)
    {
        p = p->link;
    }
    return p;
}
// 尾插法
Node *insertTail(Node *tail, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->link = NULL;
    tail->link = p;
    return p;
}

// 遍历链表
void displayList(Node *L)
{
    Node *p = L->link;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");
}

// 增加指定位置的节点
void insertNode(Node *L, int pos, ElemType e)
{
    Node *p = L;
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = e;
    int i = 0;
    for (i = 0; i < pos - 1; i++)
    {
        p = p->link;
    }
    q->link = p->link;
    p->link = q;
}

// 删除指定位置的节点
void deleteNode(Node *L, int pos)
{
    Node *p = L;
    Node *q = L;
    int i = 0;
    for (i = 0; i < pos - 1; i++)
    {
        p = p->link;
    }
    q = p->link;
    p->link = q->link;
    free(q);
}

// 获取表链的长度
int getLength(Node *L)
{
    Node *p = L;
    int i = 0;
    while (p->link != NULL)
    {
        i++;
        p = p->link;
    }
    printf("表长度为%d\n", i);
}

// 释放链表
void freeList(Node *L)
{
    Node *p = L->link;
    Node *q = L->link;
    while (p != NULL)
    {
        p = p->link;
        free(q);
        q = p;
    }
    L->link = NULL;
}

void removeNode(Node *L, int n)
{
    Node *p = L;
    int index;
    int *q = (int *)malloc(sizeof(int) * (n + 1));

    // 遍历数组，初始化值为0
    for (int i = 0; i < n + 1; i++)
    {
        *(q + i) = 0;
    }
    while (p->link != NULL)
    {
        // abs获取绝对值
        index = abs(p->link->data);
        if (*(q + index) == 0)
        {
            *(q + index) = 1;
            p = p->link;
        }
        else
        {
            Node *temp = p->link;
            p->link = temp->link;
            free(temp);
        }
    }
    free(q);
}

int main()
{
    Node *list = initList();
    Node *tail = insertTail(getTail(list), 21);
    tail = insertTail(tail, -15);
    tail = insertTail(tail, -15);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, 15);
    displayList(list);
    removeNode(list, 21);
    displayList(list);

    return 0;
}