#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

// 链表初始化
Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

// // 链表插入数据-在头部插入数据
// int insertList(Node *L, ElemType e)
// {
//     Node *p = (Node *)malloc(sizeof(Node));
//     p->data = e;
//     p->next = L->next;
//     L->next = p;
//     return 1;
// }
// 链表插入数据-在尾部插入数据
int insertList(Node *L, ElemType e)
{
    Node *p = L->next;
    // 续
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->data = e;
    return 1;
}

// 链表的遍历
void displayList(Node *L)
{
    // 这个链表有头节点，头节点数据为0，不读取头节点的数据，只读取头节点的地址。
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *list = initList();
    insertList(list, 199);
    insertList(list, 200);
    insertList(list, 201);
    displayList(list);
    return 0;
}