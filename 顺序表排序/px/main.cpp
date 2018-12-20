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
    int i,k=1;
    L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!L.elem)
        return 0;
    for(i=0; i<N; i++)
    {
        L.elem[i]=i*k;
        k=-k;
    }
    L.length=N;
    L.listsize=LIST_INIT_SIZE;
    return 1;
}
void px(SqList &L)
{
    int k=0,*p=&L.elem[0],temp;
    for(int i=0; i<L.length; i++)
        if(p[i]<0)   //判断是否小于0
        {
            temp=p[i];    //元素交换
            p[i]=p[k];
            p[k]=temp;
            k++;          //交换位置右移
        }
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
    px(L);
    pL(L);
    system("pause");
    return 0;
}
