#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define elem char
typedef struct BiTNode
{
    elem data;
    struct BiTNode *lchild,*rchild;
} BiTNode,* BiTree;
/*****************
创建二叉树
*****************/
int CreatBiTree(BiTree &T)
{
    elem ch;
    scanf("%c",&ch);
    getchar();
    if(' '==ch)
        T=NULL;
    else
    {
        if(!(T=(BiTree)malloc(sizeof(BiTNode))))
            return OVERFLOW;
        T->data=ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
    return OK;
}
/*********************
寻找度为1的节点个数
***********************/
int count_one(BiTree &T)
{
    int count_d=0;
    if(T->lchild&&!T->rchild)
    {
        count_d++;
        count_d+=count_one(T->lchild);
    }
    else if(!T->lchild&&T->rchild)
    {
        count_d++;
        count_d+=count_one(T->rchild);
    }
    return count_d;
}

int main()
{
    BiTree T;
    printf("创建一个树：\n");
    CreatBiTree(T);
    printf("度为一的节点数为%d",count_one(T));
    return 0;
}
