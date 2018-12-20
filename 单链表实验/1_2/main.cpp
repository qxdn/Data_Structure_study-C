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
int mix(Linklist &a,Linklist &b,Linklist &c)
{
    Linklist pa=a->next,pb=b->next,pc=c;
    Linklist new_node=NULL;
    while(pa&&pb)
    {
        if(pa->data>=pb->data)
        {
            new_node=(Linklist)malloc(sizeof(ListNode));
            if(!new_node)
                printf("内存不足\n");
            new_node->next=pc->next;
            new_node->data=pb->data;
            pc->next=new_node;
            pc=pc->next;
            pb=pb->next;
        }
        else
        {
            new_node=(Linklist)malloc(sizeof(ListNode));
            if(!new_node)
                printf("内存不足\n");
            new_node->next=pc->next;
            new_node->data=pa->data;
            pc->next=new_node;
            pc=pc->next;
            pa=pa->next;
        }
    }
    if(!pa)
    {
        pc->next=pb;
    }
    else if(!pb)
    {
        pc->next=pa;
    }
    return OK;
}
void px(Linklist &L)
{
    Linklist p=L->next,q=NULL;
    int temp;
    for(; p->next!=NULL; p=p->next)
        for(q=p->next; q!=NULL; q=q->next)
        {
            if(q->data<p->data)
            {
                temp=q->data;
                q->data=p->data;
                p->data=temp;
            }
        }
}

int main()
{
    Linklist La=NULL,Lb=NULL,Lc=NULL;
    Lc=(Linklist)malloc(sizeof(ListNode));
    Lc->next=NULL;
    printf("初始化La\n");
    if(List_Init(La))
    {
        printf("La初始化完成\n");
    }
    printf("初始化Lb\n");
    if(List_Init(Lb))
    {
        printf("Lb初始化完成\n");
    }
    px(La);
    px(Lb);
    printf("La:");
    print_list(La);
    printf("Lb:");
    print_list(Lb);
    mix(La,Lb,Lc);
    print_list(Lc);
}
