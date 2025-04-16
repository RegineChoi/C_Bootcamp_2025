#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

// 重命名TreeNode指针为biTree
typedef TreeNode *biTree;

// 二叉树的前序遍历
void preOrder(biTree T)
{
    if (T == NULL)
        return;
    printf("%c", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

int main()
{
    return 0;
}