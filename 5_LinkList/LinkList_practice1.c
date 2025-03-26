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

// // 链表插入数据-在尾部插入数据
// int insertList(Node *L, ElemType e)
// {
//     Node *p = L->next;
//     // 续
//     while (p != NULL)
//     {
//         p = p->next;
//     }
//     Node *temp = (Node *)malloc(sizeof(Node));
//     temp->data = e;
//     p->next = temp;
//     temp->next = NULL;
//     return 1;
// }

// 尾插法
Node *insertTail(Node *tail, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

// 获取尾节点
Node *getTail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
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

// 在指定位置插入数据
int insertElem(Node *L, int pos, ElemType e)
{
    Node *p = L;
    int i = 0;
    // 遍历链表找到插入位置的前驱节点。
    while (i < pos - 1)
    {
        p = p->next;
        i++;
    }
    // 要插入的新节点设置为q
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

// 删除节点
int deleteElem(Node *L, int pos)
{

    Node *p = L->next;
    int i = 1;
    // 遍历链表，找到要删除节点的前驱。
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
            return 0;
    }
    // q指向删除节点
    Node *q = p->next;
    p->next = q->next;
    // 释放要删除节点的内存空间
    free(q);
    return 1;
}

// 获取链表长度
int listLength(Node *L)
{
    int length = 0;
    Node *p = L->next;
    while (p != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}

// 释放链表
void freeList(Node *L)
{
    Node *p = L->next;
    Node *q;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

// 使用双指针查找倒数第k个节点
int findNodeFS(Node *L, int k)
{
    Node *fast = L->next;
    Node *slow = L->next;
    for (int i = 0; i < k; i++)
    {
        if (fast == NULL)
            return 0;
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("倒数第%d个节点的数据为%d\n", k, slow->data);
    return 1;
}

int main()
{
    Node *list = initList();
    Node *tail = getTail(list);
    tail = insertTail(tail, 199);
    tail = insertTail(tail, 200);
    tail = insertTail(tail, 201);
    tail = insertTail(tail, 202);
    tail = insertTail(tail, 203);
    displayList(list);
    insertElem(list, 3, 111);
    displayList(list);
    deleteElem(list, 3);
    displayList(list);
    printf("%d\n", listLength(list));
    findNodeFS(list, 4);
    // freeList(list);
    // printf("%d", listLength(list));
    return 0;
}