#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next=NULL;
} LNode, *LinkList;
void CreateList_L(LinkList &L,int n)
{
    LinkList p=NULL;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    for(int i=0; i<n; i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next=L->next;
        L->next=p;
    }
}
void DelMaxL(LinkList &L)
{
    LinkList p=NULL,q=NULL;
    int max_data;
    p=L->next;    //待验证节点
    max_data=p->data;
    q=L;       //待验证节点的前一个节点
    while(p)   //判断是否到链表末尾
    {
        if(p->next&&(p->next)->data>max_data)  //判断是否为为最大
        {
            q=p;  //保存最大值节点的上一个节点
            max_data=(p->next)->data;//保存最大值
        }
        p=p->next;
    }
    p=q->next;//删除节点
    q->next=p->next;
    free(p);//释放空间
}
void prL(LinkList &L)
{
    LinkList p=L->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    LinkList L=NULL;
    int n;
    printf("请输入需要的元素数量：");
    scanf("%d",&n);
    CreateList_L(L,n);
    prL(L);
    DelMaxL(L);
    prL(L);
    system("pause");
    return 0;
}
