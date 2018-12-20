#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define overflow -2

typedef struct List
{
    int data;
    struct List* next;
} ListNode,*Linklist;

int List_Init(Linklist &L)
{
    int n;
    Linklist p=NULL,new_node=NULL;
    if(L==NULL)
    {
        L=(Linklist)malloc(sizeof(ListNode));
        L->next=NULL;
    }
    if(L==NULL)
    {
        return ERROR;
    }
    p=L;
    printf("输入数值以EOF结尾\n");
    while(scanf("%d",&n)!=EOF)
    {
        new_node=(Linklist)malloc(sizeof(ListNode));
        new_node->data=n;
        new_node->next=p->next;
        p->next=new_node;
        p=p->next;
    }
    return OK;
}
int print_list(Linklist &L)
{
    Linklist p=NULL;
    p=L->next;
    while(p&&p->next)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
    return OK;
}
Linklist find_front(Linklist &a,Linklist b)
{
    Linklist temp=a;
    if(temp->next==b)
        return NULL;
    while(!(temp->next==b))
        temp=temp->next;
    return temp;
}
int nx(Linklist &head)
{
    Linklist a=head,new_list=NULL,c=NULL,b=NULL;

    while(a->next)
    {
        a=a->next;
    }
    new_list=a;
    c=new_list;
    while(b=find_front(head,c))
    {
        b->next=c->next;
        c->next=b;
        c=c->next;
    }
    head->next=new_list;
}
int main()
{
    Linklist head=NULL;
    printf("初始化链表\n");
    List_Init(head);
    printf("逆序前的链表\n");
    print_list(head);
    nx(head);
    printf("逆序后的链表\n");
    print_list(head);
}
