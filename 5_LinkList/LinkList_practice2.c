#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
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

// 初始化节点（带节点数据域参数）
Node *initListWithElem(ElemType e)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    return node;
}

// 头插法
int insertHead(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}

// 遍历
void displayList(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 尾插法
Node *insertTail(Node *tail, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}
// 获取尾部节点
Node *getTail(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        p = p->next;
    }
    return p;
}

// 指定位置插入
int inserNode(Node *L, int pos, ElemType e)
{
    Node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
            return 0;
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
}

// 删除节点
int deleteNode(Node *L, int pos)
{
    Node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

// 尾插法（节点）
Node *insertTailWithNode(Node *tail, Node *node)
{
    tail->next = node;
    node->next = NULL;
    return node;
}

int main()
{

    return 0;
}