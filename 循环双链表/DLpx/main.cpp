#include <stdio.h>
#include <stdlib.h>
#define N 20
typedef struct DuLNode
{
    int data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode,*DuLinkList;
void CreatList(DuLinkList &L,int n)
{
    int i=0;
    DuLinkList p=NULL,q=NULL;
    L=(DuLinkList)malloc(sizeof(DuLNode));
    L->data=i;
    q=L;
    for(i=1; i<n; i++)
    {
        p=(DuLinkList)malloc(sizeof(DuLNode));
        p->data=i;
        q->next=p;
        p->prior=q;
        q=q->next;
    }
    q->next=L;
    L->prior=q;
}
void ChangeDuLNode(DuLinkList &L)
{
    DuLinkList q=NULL;
    q=L->next;
    L->prior->next=q;
    q->next->prior=L;
    q->prior=L->prior;
    L->next=q->next;
    q->next=L;
    L->prior=q;
}
void PrDi(DuLinkList &L)
{
    DuLinkList p=L;
    int i=0;
    while(p!=L||i<N)
    {
        printf("%d ",p->data);
        p=p->next;
        i++;
    }
    printf("\n");
}
int main()
{
    DuLinkList L=NULL,p=NULL;
    CreatList(L,N);
    PrDi(L);
    p=L;
    ChangeDuLNode(p->next);
    PrDi(L);
    system("pause");
    return 0;
}
