#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

char str[] = "ABDH#K###E##CFI###G#J##";
int index = 0;

TreeNode *createTree()
{
    ElemType ch;
    ch = str[index++];
    if (ch == '#')
    {
        return NULL;
    }
    else
    {
        TreeNode *T = (TreeNode *)malloc(sizeof(TreeNode));
        T->data = ch;
        T->lchild = createTree();
        T->rchild = createTree();
        return T;
    }
}

// 二叉树的前序遍历
void preOrder(TreeNode *T)
{
    if (T == NULL)
        return;
    printf("%c", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

// 二叉树的中序遍历
void inOrder(TreeNode *T)
{
    if (T == NULL)
        return;
    inOrder(T->lchild);
    printf("%c", T->data);
    inOrder(T->rchild);
}

// 二叉树的后序遍历
void postOrder(TreeNode *T)
{
    if (T == NULL)
        return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c", T->data);
}

int main()
{
    TreeNode *T = createTree();
    preOrder(T);
    printf("\n");

    inOrder(T);
    printf("\n");

    postOrder(T);
    printf("\n");

    return 0;
}