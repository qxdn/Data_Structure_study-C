#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define elem char
#define stack_init_size 100
typedef struct BiTNode
{
    elem data;
    struct BiTNode *lchild,*rchild;
} BiTNode,* BiTree;
typedef struct Stack
{
    BiTree *base;
    BiTree* top;
    int len;
} SqStack;

char a[]= {'1','2',' ',' ','3','4','6',' ',' ',' ','5',' ',' '};
int temp=0;
int Init_Stack(SqStack &S)
{
    S.base=(BiTree *)malloc(stack_init_size*sizeof(BiTree));
    if(!S.base)
        return ERROR;
    S.top=S.base;
    S.len=stack_init_size;
    return OK;
}
int StackEmpty(SqStack &S)
{
    if(S.base==S.top)
        return 1;
    else
        return 0;
}
/*************
压入栈
*************/
int push(SqStack &S,BiTree x)
{
    if(S.top-S.base>=S.len)
    {
        printf("栈已经满了\n");
        return OVERFLOW;
    }
    *(S.top)=x;
    S.top++;
    return OK;
}
/********************
出栈
********************/
int Pop(SqStack &S,BiTree &x)
{
    if(S.base==S.top)
    {
        return ERROR;
    }
    x=*(--S.top);
    return OK;
}

/****************
创建二叉树
*****************/
int CreatBiTree(BiTree &T)
{
    elem ch;
    ch=a[temp++];
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
/*************
非递归遍历
**************/
int inordertraverse(BiTree T)
{
    SqStack S;
    BiTree p;
    Init_Stack(S);
    p=T;
    while(p||!StackEmpty(S))
    {
        if(p)
        {
            push(S,p);
            p=p->lchild;
        }
        else
        {
            Pop(S,p);
            printf("%c ",p->data);
            p=p->rchild;
        }
    }
    return OK;
}
int main()
{
    BiTree T;
    CreatBiTree(T);
    inordertraverse(T);
    return 0;
}
