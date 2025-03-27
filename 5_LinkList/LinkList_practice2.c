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
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

// 尾插法（节点）
Node *insertTailWithNode(Node *tail, Node *node)
{
    tail->next = node;
    node->next = NULL;
    return node;
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
    return 1;
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
        if (p == NULL)
        {
            return 0;
        }
    }

    if (p->next == NULL)
    {
        printf("要删除的位置错误\n");
        return 0;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

// 获取链表长度
int listLength(Node *L)
{
    int len = 0;
    Node *p = L;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
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
// 查找倒数第k个节点
int findNodeFS(Node *L, int k)
{
    Node *fast = L->next;
    Node *slow = L->next;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
        if (fast == NULL)
        {
            return 0;
        }
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("倒数第%d个节点的值为：%d\n", k, slow->data);
    return 1;
}

// 查找两个节点共同后缀的起始位置
Node *findeIntersectionNode(Node *headA, Node *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    Node *p = headA;
    int lenA = 0;
    int lenB = 0;
    // 遍历链表A，获取链表A的长度
    while (p != NULL)
    {
        p = p->next;
        lenA++;
    }
    p = headB;
    // 遍历链表B，获取链表A的长度
    while (p != NULL)
    {
        p = p->next;
        lenB++;
    }

    Node *f;  // 快指针
    Node *s;  // 慢指针
    int step; // 两个单词之间差值，可以用于快指针先走的步数
    if (lenA > lenB)
    {
        step = lenA - lenB;
        f = headA;
        s = headB;
    }
    else
    {
        step = lenB - lenA;
        f = headB;
        s = headA;
    }
    for (int i = 0; i < step; i++)
    {
        f = f->next;
    }

    // 快慢指针同步走，直到指向同一个节点推出循环
    while (f != s)
    {
        f = f->next;
        s = s->next;
    }
    return f;
}

int main()
{
    Node *listA = initList();
    Node *listB = initList();
    Node *tailA = getTail(listA);
    Node *tailB = getTail(listB);
    tailA = insertTail(tailA, 'l');
    tailA = insertTail(tailA, 'o');
    tailA = insertTail(tailA, 'a');
    tailA = insertTail(tailA, 'd');
    tailB = insertTail(tailB, 'b');
    tailB = insertTail(tailB, 'e');
    Node *nodeI = initListWithElem('i');
    tailA = insertTailWithNode(tailA, nodeI);
    tailB = insertTailWithNode(tailB, nodeI);
    Node *nodeN = initListWithElem('n');
    tailA = insertTailWithNode(tailA, nodeN);
    tailB = insertTailWithNode(tailB, nodeN);
    Node *nodeG = initListWithElem('g');
    tailA = insertTailWithNode(tailA, nodeG);
    tailB = insertTailWithNode(tailB, nodeG);

    displayList(listA);
    displayList(listB);
    printf("%c\n", findeIntersectionNode(listA, listB)->data);
    return 0;
}