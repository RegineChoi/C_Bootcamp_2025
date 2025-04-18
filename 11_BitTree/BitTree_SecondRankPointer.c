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

// 传入一个biTree指针T，相当于TreeNode指针的指针
void createTree(biTree *T)
{
    ElemType ch;
    ch = str[index++];
    if (ch == '#')
    {
        *T = NULL; //*T相当于TreeNode指针
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

// 二叉树的中序遍历
void inOrder(biTree T)
{
    if (T == NULL)
        return;
    inOrder(T->lchild);
    printf("%c", T->data);
    inOrder(T->rchild);
}

// 二叉树的后序遍历
void postOrder(biTree T)
{
    if (T == NULL)
        return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c", T->data);
}

int main()
{
    biTree T;       // TreeNode指针
    createTree(&T); // 传入TreeNode指针的地址
    preOrder(T);
    printf("\n");

    inOrder(T);
    printf("\n");

    postOrder(T);
    printf("\n");

    return 0;
}