#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define elem int
#define List_init_size 100
typedef struct
{
    int *base;
    int *top;
    int ListSize;
} SqStack;
typedef struct link_stack_node
{
    elem data;
    struct link_stack_node *next;
} link_stack_node,*link_stack;
/**********
函数名：初始化栈
参数：SqStack
返回：void
**********/
void Init_Stack(SqStack &S)
{
    S.base=(int *)malloc(List_init_size*sizeof(int));
    if(!S.base)
        printf("栈初始化失败\n");
    S.top=S.base;
    S.ListSize=List_init_size;
}
/*********************
初始化链栈
**********************/
int init_link_stack(link_stack &L)
{
    L=(link_stack)malloc(sizeof(link_stack_node));
    if(NULL==L)
        exit(ERROR);
    L->next=NULL;
    return OK;
}
/************************
链栈内插入元素
************************/
int push_link_stack(link_stack &L,elem e)
{
    link_stack temp;
    temp=(link_stack)malloc(sizeof(link_stack_node));
    if(!temp)
        exit(ERROR);
    temp->data=e;
    temp->next=L->next;
    L->next=temp;
    return OK;
}
/**************
获得链栈的栈顶元素
****************/
int get_link_stack_top(link_stack &L,elem &e)
{
    if(!L->next)
        return ERROR;
    e=L->next->data;
}
/*******************
链栈出栈
********************/
int pop_link_stack(link_stack &L,elem &e)
{
    link_stack temp;
    if(!L->next)
        return ERROR;
    temp=L->next;
    e=temp->data;
    L->next=temp->next;
    free(temp);
    return OK;
}
/***************
摧毁链栈
****************/
void destory_link_Stack(link_stack &L)
{
    elem n;
    while(pop_link_stack(L,n))
        ;
    free(L);
}
/*****************
判断链栈是否为空
******************/
int Is_link_stack_empty(link_stack &L)
{
    if(!L->next)
        return 1;
    else
        return 0;
}
/**********
函数名：清空栈
参数：SqStack
返回：OK
**********/
int clear_Stack(SqStack &S)
{
    while(S.top>S.base)
    {
        S.top--;
    }
    printf("栈已经清空\n");
    return OK;
}
/**********
函数名：摧毁栈
参数：SqStack
返回：OK
**********/
int destory_Stack(SqStack &S)
{
    free(S.base);
    S.base=NULL;
    S.top=NULL;
    S.ListSize=0;
    printf("栈已经摧毁\n");
    return OK;
}
/**********
函数名：插入栈
参数：SqStack x
返回：OK
**********/
int push(SqStack &S,int x)
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
int Pop(SqStack &S,int &x)
{
    if(S.base==S.top)
    {
        printf("栈已经空了\n");
        return ERROR;
    }
    x=*(--S.top);
    return OK;
}

int get_top(SqStack &S,int &x)
{
    if(S.base==S.top)
        return ERROR;
    x=*(S.top-1);
    return OK;
}
int cal_t(int n)
{
    int sum=0;
    link_stack S;
    init_link_stack(S);
    push_link_stack(S,n);
    while(1)
    {
        get_link_stack_top(S,n);
        if(n==0)
        {
            break;
        }
        else
        {
            push_link_stack(S,n/2);
        }
    }
    while(!Is_link_stack_empty(S))
    {
        pop_link_stack(S,n);
        sum=2*sum+n;
    }
    destory_link_Stack(S);
    return sum;
}
int t_n(int n)
{
    if(n==0)
        return 0;
    return 2*t_n(n/2)+n;
}
int main()
{
    int n;
    printf("请输入要计算的值\n");
    scanf("%d",&n);
    printf("递归的结果：%d\n",t_n(n));
    printf("栈的结果：%d\n",cal_t(n));
}
