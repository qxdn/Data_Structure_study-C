#include <stdio.h>
#include <stdlib.h>

typedef struct dxs_NODE
{
    int xishu;
    int mici;
    dxs_NODE* next;
} dxs_node,*dxs_linklist;
void creat_list(dxs_linklist &L)
{
    int n,i;
    dxs_linklist temp=NULL,q=NULL;
    L=(dxs_linklist)malloc(sizeof(dxs_node));
    L->next=NULL;
    q=L;
    printf("请输入要输入的个数：");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        temp=(dxs_linklist)malloc(sizeof(dxs_node));
        q->next=temp;
        printf("请输入系数：");
        scanf("%d",&temp->xishu);
        printf("请输入幂:");
        scanf("%d",&temp->mici);
        temp->next=NULL;
        q=q->next;
    }
}
void pri_list(dxs_linklist &L)
{
    dxs_linklist q=L->next;
    while(q->next)
    {
        if(q->mici!=0)
            printf("%dX^%d+",q->xishu,q->mici);
        else
            printf("%d+",q->xishu);
        q=q->next;
    }
    if(q->mici!=0)
        printf("%dX^%d",q->xishu,q->mici);
    else
        printf("%d",q->xishu);
    printf("\n");
}
void add_list(dxs_linklist &qa,dxs_linklist &qb)
{
    dxs_linklist temp_a=qa->next,temp_b=qb->next,temp=qa;
    while(temp_a&&temp_b)
    {
        if(temp_a->mici>temp_b->mici)
        {
            temp->next=temp_b;
            temp_b=temp_b->next;
            (temp->next)->next=temp_a;
        }
        else if(temp_a->mici<temp_b->mici)
        {
            temp=temp_a;
            temp_a=temp_a->next;
        }
        else if(temp_a->mici=temp_b->mici)
        {
            if((temp_a->xishu+temp_b->xishu)==0)
            {
                temp->next=temp_a->next;
                free(temp_a);
                temp_a=temp->next;
                temp_b=temp_b->next;
            }
            else
            {
                temp_a->xishu=temp_a->xishu+temp_b->xishu;
                temp=temp_a;
                temp_a=temp_a->next;
                temp_b=temp_b->next;
            }
        }
    }
    if(temp_b)
    {
        temp=qa;
        while(temp->next)
            temp=temp->next;
        temp->next=temp_b;
    }
}
int main()
{
    dxs_linklist qa=NULL,qb=NULL;
    creat_list(qa);
    pri_list(qa);
    creat_list(qb);
    pri_list(qb);
    add_list(qa,qb);
    pri_list(qa);
    system("pause");
    return 0;
}
