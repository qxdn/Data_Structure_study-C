#include <stdio.h>
#include <stdlib.h>
int a[]={11,16,8,5,14,10,38,23};
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
        p->data=a[i];
        p->next=L->next;
        L->next=p;
    }
}
void px(LinkList &L)
{
    LinkList p=L->next,q=NULL;
    int temp;
    for(;p->next!=NULL;p=p->next)
      for(q=p->next;q!=NULL;q=q->next)
      {
          if(q->data>p->data)
          {
              temp=q->data;
              q->data=p->data;
              p->data=temp;
          }
      }
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
    int n=8;
    CreateList_L(L,n);
    prL(L);
    px(L);
    prL(L);
    system("pause");
    return 0;
}
