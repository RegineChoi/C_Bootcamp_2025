#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SeqLink;

// 顺序表初始化
void initList(SeqLink *L)
{
    L->length = 0;
}

// 顺序表-在尾部添加元素
int appendElem(SeqLink *L, ElemType e)
{
    if (L->length >= MAXSIZE)
    {
        printf("顺序表已满，无法添加\n");
        return 0;
    }
    else
    {
        L->data[L->length] = e;
        L->length++;
        return 1;
    }
}

// 顺序表遍历
void listElem(SeqLink *L)
{
    if (L->length > 0)
    {
        for (int i = 0; i < L->length; i++)
        {
            printf("%d ", L->data[i]);
        }
        printf("\nL->length长度为%d\n", L->length);
    }
    else
        printf("L->length长度为0\n");
}

int main()
{
    // 声明一个顺序表并初始化
    SeqLink list;
    initList(&list);
    printf("初始化成功，目前长度为%d字节\n", list.length);
    printf("目前占用内存的大小为%zu字节\n", sizeof(list.data));
    appendElem(&list, 100);
    printf("添加成功，目前长度为%d字节\n", list.length);
    appendElem(&list, 101);
    appendElem(&list, 102);
    listElem(&list);
    return 0;
}