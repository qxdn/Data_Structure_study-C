#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCRMENT
#define N 20
typedef struct
{
    int *elem;
    int  length;
    int  listsize;
} SqList;
int InitList_Sq(SqList &L)
{
    //顺序表
    int i;
    L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!L.elem)
        return 0;
    for(i=0; i<N; i++)
        L.elem[i]=i;
    L.length=N;
    L.listsize=LIST_INIT_SIZE;
    return 1;
}
int DelList(SqList &L,int x,int y)
{
    if(x>y)    //判断x，y资格
        return 0;
    int *p=&L.elem[0];
    int k=0;
    for(int i=0; i<L.length; i++)
        if(L.elem[i]>y||L.elem[i]<x) //判断是否删除
            L.elem[k++]=L.elem[i];  //删除并移动顺序表
        else
            L.length--;   //长度减一
    return 1;
}
void pL(SqList &L)   //打印出顺序表
{
    for(int i=0; i<L.length; i++)
        printf("%d ",L.elem[i]);
    printf("\n");
}
int main()
{
    SqList L;
    if(InitList_Sq(L))
        pL(L);
    else
        printf("创建顺序表失败");
    if(DelList(L,5,10))
        pL(L);
    else
        printf("输入有误");
    system("pause");
    return 0;
}
