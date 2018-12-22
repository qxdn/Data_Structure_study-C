#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define overflow (-2)
typedef struct List
{
    int data;
    struct List* next;
} ListNode,*Linklist;
/**************************
打印链表元素
******************************/
int print_list(Linklist &L)
{
    Linklist p=NULL;
    int i=1;
    if(L==NULL)
    {
        printf("还未初始化，请初始化链表\n");
        return ERROR;
    }
    printf("该链表的输出为:\n");
    p=L->next;
    while(p)
    {
        printf("%d     %d\n",i,p->data);
        p=p->next;
        i++;
    }
    return OK;
}
/**********************
链表初始化
***********************/
int List_Init(Linklist &L)
{
    if(L==NULL)
    {
        L=(Linklist)malloc(sizeof(ListNode));
        L->next=NULL;
    }
    else
    {
        printf("已经经过初始化\n");
        return OK;
    }
    if(L==NULL)
    {
        printf("链表初始化失败\n");
        return ERROR;
    }
    else
    {
        printf("链表初始化完成\n");
        return OK;
    }
}
/******************************
插入节点
******************************/
int insert_Node(Linklist &L)
{
    Linklist p=NULL,new_node=NULL;
    int data,place;
    int i=1;
    if(L==NULL)
    {
        printf("还未初始化，请初始化链表\n");
        return ERROR;
    }
    printf("请输入插入节点的位置（插入后成为第几个节点）\n");
    scanf("%d",&place);
    printf("请输入要插入的数据\n");
    scanf("%d",&data);
    p=L;
    while(p&&i<place)
    {
        p=p->next;
        i++;
    }
    if(!p||i>place)
        return  overflow;
    new_node=(Linklist)malloc(sizeof(ListNode));
    new_node->data=data;
    new_node->next=p->next;
    p->next=new_node;
    printf("插入完成\n");
    return OK;
}
/*******************
删除节点
******************/
int del_node(Linklist &L)
{
    Linklist p=NULL,temp=NULL;
    int i=1;
    int place;
    char check;
    if(L==NULL)
    {
        printf("还未初始化，请初始化链表\n");
        return ERROR;
    }
    printf("输入打算删除节点的位置\n");
    scanf("%d",&place);
    p=L;
    while(!p&&i<place)
    {
        p=p->next;
        i++;
    }
    if(!p||i>place)
        return overflow;
    temp=p->next;
    printf("要删除的数据是%d,Y确认删除(不区分大小写)\n",temp->data);
    getchar();
    scanf("%c",&check);
    if(check=='Y'||check=='y')
    {
        p->next=temp->next;
        free(temp);
        printf("删除完成\n");
        return OK;
    }
    else
        return OK;
}
int find_node(Linklist &L)
{
    Linklist p=NULL;
    int n;
    int i=1;
    if(L==NULL)
    {
        printf("还未初始化，请初始化链表\n");
        return ERROR;
    }
    printf("请输入想要查找的节点：\n");
    scanf("%d",&n);
    p=L->next;
    while(p)
    {
        if(p->data==n)
        {
            printf("节点的位置是%d\n",i);
            return OK;
        }
        p=p->next;
        i++;
    }
    printf("没有该节点\n");
}
void print_menu(void)
{
    printf("您好，请输入选项：\n");
    printf("1、初始化链表\n");
    printf("2、在初始化完成的链表里插入新的节点\n");
    printf("3、删除链表里的一个值\n");
    printf("4、查找节点位置\n");
    printf("5、打印链表中的所有元素\n");
    printf("6、退出\n");
}
int main()
{
    int n;
    Linklist L=NULL;
    print_menu();
    scanf("%d",&n);
    while(n!=6)
    {
        if(!(n>=1&&n<=5))
        {
            printf("无效输入，请重试\n");
            scanf("%d",&n);
            continue;
        }
        switch(n)
        {
        case 1:
            List_Init(L);
            break;
        case 2:
            insert_Node(L);
            break;
        case 3:
            del_node(L);
            break;
        case 4:
            find_node(L);
            break;
        case 5:
            print_list(L);
            break;
        }
        print_menu();
        scanf("%d",&n);
    }
}
