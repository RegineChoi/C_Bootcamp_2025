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

char str[] = "ABDH#K###E##CFI###G#J##";
int index = 0;

void createTree(biTree *T)
{
    ElemType ch;
    ch = str[index++];
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (biTree)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&(*T)->lchild);
        createTree(&(*T)->rchild);
    }
}

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
    biTree T;
    createTree(&T);
    preOrder(T);

    return 0;
}