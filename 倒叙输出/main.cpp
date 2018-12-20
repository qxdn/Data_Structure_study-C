#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define List_init_size 100
typedef struct
{
    int *base;
    int *top;
    int ListSize;
} SqStack;
/**********
函数名：初始化栈
参数：SqStack
返回：OK OVERFLOW
**********/
int Init_Stack(SqStack &S)
{
    S.base=(int *)malloc(List_init_size*sizeof(int));
    if(!S.base)
    {
        printf("栈初始化失败\n");
        return OVERFLOW;
    }
    S.top=S.base;
    S.ListSize=List_init_size;
    return OK;
}
/**********
函数名：输入
参数：SqStack
返回：OK OVERFLOW
**********/
int Inputs_SqStack(SqStack &S)
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        *(S.top)=n;
        S.top++;
        if((S.top-S.base)>=S.ListSize)
        {
            printf("满栈\n");
            return OVERFLOW;
        }
    }
    return OK;
}
/**********
函数名：倒叙输出
参数：SqStack
返回：OK OVERFLOW
**********/
int print_SqStack(SqStack &S)
{
    int *p;
    for(p=S.top-1 ; p>=S.base+1; p--)
    {
        printf("%d ",*p);
    }
    printf("%d\n",*(p));
    return OK;
}
int main()
{
    SqStack S;
    Init_Stack(S);
    Inputs_SqStack(S);
    print_SqStack(S);
}
