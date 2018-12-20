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
int div_list(Linklist &La,Linklist &Lb,Linklist &Lc)
{
    Linklist pa=La->next,pb=Lb,pc=Lc,new_node=NULL;
    while(pa)
    {
        new_node=(Linklist)malloc(sizeof(ListNode));
        if(!new_node)
            return ERROR;
        new_node->data=pa->data;
        if(pa->data%2==0)
        {
            new_node->next=pc->next;
            pc->next=new_node;
            pc=pc->next;
        }
        else
        {
            new_node->next=pb->next;
            pb->next=new_node;
            pb=pb->next;
        }
        pa=pa->next;
    }
    return OK;
}
int main()
{
    Linklist La=NULL,Lb=NULL,Lc=NULL;
    Lc=(Linklist)malloc(sizeof(ListNode));
    Lc->next=NULL;
    Lb=(Linklist)malloc(sizeof(ListNode));
    Lb->next=NULL;
    List_Init(La);
    printf("链表初始化完成\n");
    printf("链表初始化完成\n");
    print_list(La);
    div_list(La,Lb,Lc);
    printf("拆分后的La和Lb为：\n");
    print_list(Lb);
    print_list(Lc);
}
