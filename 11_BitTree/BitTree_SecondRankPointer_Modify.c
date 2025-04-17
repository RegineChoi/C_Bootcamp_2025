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

// TreeNode指针的指针
void createTree(TreeNode **T)
{
    ElemType ch;
    ch = str[index++];
    if (ch == '#')
    {
        *T = NULL; //*T相当于TreeNode指针
    }
    else
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&(*T)->lchild);
        createTree(&(*T)->rchild);
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
    TreeNode *T;    // TreeNode指针
    createTree(&T); // 传入TreeNode指针的地址
    preOrder(T);
    printf("\n");

    inOrder(T);
    printf("\n");

    postOrder(T);
    printf("\n");

    return 0;
}