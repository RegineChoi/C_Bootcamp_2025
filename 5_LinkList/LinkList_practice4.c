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
// 头插法
Node *insertHead(Node *head, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->link = head->link;
    head->link = p;
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
// 反转链表，等于遍历链表+头插法
//  Node *reversalList(Node *input)
//  {
//      Node *output = (Node *)malloc(sizeof(Node));
//      Node *p = input->link;
//      while (p != NULL)
//      {
//          insertHead(output, p->data);
//          p = p->link;
//      }
//      return output;
//  }

// // 老师教的反转链表
// Node *reverseList(Node *head)
// {
//     Node *first = NULL;
//     Node *second = head->link;
//     Node *third;
//     while (second != NULL)
//     {
//         third = second->link;
//         second->link = first;
//         first = second;
//         second = third;
//     }
//     Node *hd = initList();
//     hd->link = first;
//     return hd;
// }

// // 删除链表中间节点
// int delMiddleNode(Node *L)
// {
//     Node *fast = L->link;
//     Node *slow = L;
// }

// 反转链表
Node *reverseList(Node *head)
{
    Node *first = NULL;
    Node *second = head->link;
    Node *third;
    while (second != NULL)
    {
        third = second->link;
        second->link = first;
        first = second;
        second = third;
    }
    head->link = first;
    free(second);
    return head;
}

// 删除中间节点
int delMiddleNode(Node *head)
{
    Node *fast = head->link;
    Node *slow = head;

    while (fast != NULL && fast->link != NULL)
    {
        fast = fast->link->link;
        slow = slow->link;
    }
    Node *q = slow->link;
    slow->link = q->link;
    free(q);
    return 1;
}

// 链表重新排序
void reOrderList(Node *head)
{
    Node *fast = head->link;
    Node *slow = head;
    while (fast != NULL && fast->link != NULL)
    {
        fast = fast->link->link;
        slow = slow->link;
    }

    Node *first = NULL;
    Node *second = slow->link;
    slow->link = NULL;
    Node *third = NULL;

    while (second != NULL)
    {
        third = second->link;
        second->link = first;
        first = second;
        second = third;
    }

    Node *p1 = head->link;
    Node *q1 = first;
    Node *p2, *q2;
    while (p1 != NULL && q1 != NULL)
    {
        p2 = p1->link;
        q2 = q1->link;

        p1->link = q1;
        q1->link = p2;

        p1 = p2;
        q1 = q2;
    }
}

// // 反转链表 使用头插法进行倒序
// Node *reverseList(Node *head)
// {
//     Node *reverse_head = initList();
//     Node *p = head->link;
//     Node *q = NULL;
//     while (p != NULL)
//     {
//         insertHead(reverse_head, p->data); // 向reverseList头插法插入数据
//         q = p;
//         p = p->link;
//         free(q);
//     }
//     free(head);
//     return reverse_head;
// }

int main()
{
    Node *list = initList();
    Node *tail = getTail(list);
    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);
    displayList(list);
    // reverseList(list);
    // displayList(list);
    reOrderList(list);
    displayList(list);
    return 0;
}