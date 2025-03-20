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

// // 顺序表插入元素
// int insertElem(SeqLink *L, int num, ElemType e)
// {
//     if (num < 0 || num > 100 || (num > L->length))
//     {
//         printf("插入的位置错误，无法操作\n");
//         return 0;
//     }

//     if (L->length >= MAXSIZE)
//     {
//         printf("顺序表已满无法插入\n");
//         return 0;
//     }
//     else
//     {
//         for (int i = L->length; i > num; i--)
//         {
//             if (num == i)
//             {
//                 L->data[i] = e;
//                 L->length++;
//                 return 1;
//             }
//             L->data[i] = L->data[i - 1];
//         }
//     }
// }

// 顺序表插入元素,pos位置为 1 ~ length(此处没有队尾插入的情况)
int insertElem(SeqLink *L, int pos, ElemType e)
{
    if (L->length >= MAXSIZE)
    {
        printf("顺序表已满，无法插入\n");
        return 0;
    }
    if (pos < 1 || pos > L->length)
    {
        printf("插入位置错误\n");
        return 0;
    }
    if (pos <= L->length)
    {
        for (int i = L->length - 1; i >= pos - 1; i--)
        {
            L->data[i + 1] = L->data[i];
        }
        L->data[pos - 1] = e;
        L->length++;
        return 1;
    }
}

int main()
{
    // 声明一个顺序表并初始化
    SeqLink list;
    initList(&list);
    printf("初始化成功，目前长度为%d字节\n", list.length);
    printf("目前占用内存的大小为%zu字节\n", sizeof(list.data));
    int flag = appendElem(&list, 100);
    if (flag)
        printf("尾部添加元素成功\n");
    else
        printf("尾部添加元素失败\n");
    appendElem(&list, 101);
    if (flag)
        printf("尾部添加元素成功\n");
    else
        printf("尾部添加元素失败\n");
    appendElem(&list, 102);
    appendElem(&list, 103);
    appendElem(&list, 104);
    listElem(&list);
    insertElem(&list, 1, 80);
    listElem(&list);
    return 0;
}