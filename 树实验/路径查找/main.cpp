#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define elem char
#define List_init_size 100;
typedef struct BiTNode
{
    elem data;
    struct BiTNode *lchild,*rchild;
} BiTNode,* BiTree;
typedef struct
{
    elem *base;
    elem *top;
    int ListSize;
} SqStack;
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
/**********
函数名：初始化栈
参数：SqStack
返回：void
**********/
/**
 * ......................我佛慈悲......................
 *                       _oo0oo_
 *                      o8888888o
 *                      88" . "88
 *                      (| -_- |)
 *                      0\  =  /0
 *                    ___/`---'\___
 *                  .' \\|     |// '.
 *                 / \\|||  :  |||// \
 *                / _||||| -卍-|||||- \
 *               |   | \\\  -  /// |   |
 *               | \_|  ''\---/''  |_/ |
 *               \  .-\__  '-'  ___/-. /
 *             ___'. .'  /--.--\  `. .'___
 *          ."" '<  `.___\_<|>_/___.' >' "".
 *         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *         \  \ `_.   \_ __\ /__ _/   .-` /  /
 *     =====`-.____`.___ \_____/___.-`___.-'=====
 *                       `=---='
 *
 *..................佛祖开光 ,永无BUG...................
 *
 */

void Init_Stack(SqStack &S)
{
    S.base=(elem *)malloc(List_init_size*sizeof(elem));    //我也不知道为什么它错
    if(!S.base)
        printf("栈初始化失败\n");
    S.top=S.base;
    S.ListSize=List_init_size;
}

/**********
函数名：插入栈
参数：SqStack x
返回：OK
**********/
int push(SqStack &S,elem x)
{
    if(S.top-S.base>=S.ListSize)
    {
        printf("栈已经满了\n");
        return OVERFLOW;
    }
    *(S.top)=x;
    S.top++;
    return OK;
}
/**********
函数名：出栈
参数：SqStack x
返回：OK
**********/
int Pop(SqStack &S,elem &x)
{
    if(S.base==S.top)
    {
        printf("栈已经空了\n");
        return ERROR;
    }
    x=*(--S.top);
    return OK;
}
/********************
摧毁栈
*********************/
int destory_sqstack(SqStack &S)
{
    free(S.base);
    S.top=S.base;
    S.ListSize=0;
    return OK;
}
elem get_top(SqStack &S)
{
    if(S.base==S.top)
        return ERROR;
    return *(S.top-1);
}
/*********************
判断空
*********************/
int is_stack_empty(SqStack &S)
{
    if(S.base==S.top)
        return 1;
    else
        return 0;
}
/*************
路径查找
**************/
int find_way(BiTree T,elem p,SqStack &S)
{
    if(!T)
        return 0;
    if(find_way(T->lchild,p,S)||find_way(T->rchild,p,S))
    {
        push(S,T->data);
        return 1;
    }
    if(T->data==p)
    {
        push(S,p);
        return 1;
    }
    return 0;
}
int main()
{
    BiTree T;
    SqStack S;
    elem p;
    Init_Stack(S);
    printf("创建一个树：\n");
    printf("查找:\n");
    scanf("%c",&p);
    find_way(T,p,S);
    while(!is_stack_empty(S))
    {
        Pop(S,p);
        printf("%c->",p);
    }
    return 0;
}
