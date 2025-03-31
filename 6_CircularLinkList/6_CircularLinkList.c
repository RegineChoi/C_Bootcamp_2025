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
    int i = 0;
    while (p != NULL)
    {
        i++;
        printf("%d ", p->data);
        p = p->link;
        if (i > 1000)
        {
            printf("疑似循环\n");
            break;
        }
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

// 判断链表是否有环
int isCircle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->link != NULL)
    {
        fast = fast->link->link;
        slow = slow->link;
        if (slow = fast)
        {
            return 1;
        }
    }
    return 0;
}

// 找到循环链表的入口
Node *findTheInput(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->link != NULL)
    {
        fast = fast->link->link;
        slow = slow->link;
        if (slow == fast)
        {
            Node *p = fast;
            p = p->link;
            int count = 1;
            while (p != slow)
            {
                count++;
                p = p->link;
            }
            fast = head;
            slow = head;
            for (int i = 0; i < count; i++)
            {
                fast = fast->link;
            }
            while (slow != fast)
            {
                fast = fast->link;
                slow = slow->link;
            }
            return slow;
        }
    }
}

int main()
{
    Node *list = initList();
    Node *tail = getTail(list);
    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    displayList(list);
    Node *three = tail;
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, 8);
    tail->link = three;
    if (isCircle(list))
    {
        printf("有环\n");
    }
    else
    {
        printf("无环\n");
    }
    Node *input = findTheInput(list);
    printf("入口处的值为：%d\n", input->data);

    return 0;
}