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

// 顺序表删除，删除的位置 1 ~ L->length
int deleteElem(SeqLink *L, int pos, ElemType *e)
{
    if (L->length == 0)
    {
        printf("队列长度为空，无法删除\n");
        return 0;
    }
    if (pos < 1 || pos > L->length)
    {
        printf("删除的位置错误\n");
        return 0;
    }
    *e = L->data[pos - 1];
    for (int i = pos; i < L->length; i++)
    {
        L->data[i - 1] = L->data[i];
    }
    L->length--;
    return 1;
}
int main()
{
    // 声明一个顺序表并初始化
    SeqLink list;
    initList(&list);
    printf("初始化成功，目前长度为%d字节\n", list.length);
    printf("目前占用内存的大小为%zu字节\n", sizeof(list.data));
    int addflag = appendElem(&list, 100);
    if (addflag)
        printf("尾部添加元素成功\n");
    else
        printf("尾部添加元素失败\n");
    appendElem(&list, 101);
    appendElem(&list, 102);
    appendElem(&list, 103);
    appendElem(&list, 104);
    listElem(&list);
    insertElem(&list, 1, 80);
    listElem(&list);
    int delete_flag = 0;
    ElemType delete_num;
    delete_flag = deleteElem(&list, 6, &delete_num);
    if (delete_flag)
        printf("删除元素成功，删除的元素为%d\n", delete_num);
    else
        printf("删除元素失败\n");
    listElem(&list);
    return 0;
}