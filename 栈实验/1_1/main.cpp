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
参数：SqStack 长度n
返回：void
**********/
void Init_Stack(SqStack &S,int n)
{
    S.base=(int *)malloc(n*sizeof(int));
    if(!S.base)
        printf("栈初始化失败\n");
    S.top=S.base;
    S.ListSize=n;
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
/******************
函数名：取栈顶元素
参数：SqStack x int elem
返回：OK
*******************/
int get_top(SqStack &S,int &elem)
{
    if(S.base==S.top)
        return 0;
    elem=*(S.top-1);
    return OK;
}
int printf_Stack(SqStack &S)
{
    int * i=S.base;
    if(S.base==S.top)
    {
        printf("空\n");
        return OK;
    }
    while(i<S.top-1)
    {
        printf("%d ",*i);
        i++;
    }
    printf("%d\n",*i);
    return 0;
}
void printf_menu(void)
{
    printf("1、初始化栈\n");
    printf("2、插入栈\n");
    printf("3、出栈\n");
    printf("4、清空栈\n");
    printf("5、取栈顶元素\n");
    printf("6、打印栈的元素\n");
    printf("7、销毁栈\n");
    printf("8、退出\n");
}
int main()
{
    SqStack S;
    int n,i;
    printf_menu();
    scanf("%d",&i);
    while(i!=8)
    {
        switch (i)
        {
        case 1:
        {
            printf("请输入栈的长度\n");
            scanf("%d",&n);
            Init_Stack(S,n);
            break;
        }
        case 2:
        {
            printf("请输入要入栈的数:\n");
            scanf("%d",&n);
            push(S,n);
            break;
        }
        case 3:
        {
            Pop(S,n);
            printf("出栈元素是%d\n",n);
            break;
        }
        case 4:
        {
            clear_Stack(S);
            break;
        }
        case 5:
        {
            get_top(S,n);
            printf("栈顶元素是：%d\n",n);
            break;
        }
        case 6:
        {
            printf_Stack(S);
            break;
        }
        case 7:
            destory_Stack(S);
            break;
        }
        printf_menu();
        scanf("%d",&i);
    }
}
