#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -1
#define elem int
#define queue_init_size 100
typedef struct queue
{
    elem *base;
    int front;
    int rear;
    int len;
} queue;
/*********
初始化队列
***********/
int queue_init(queue *Q,int n)
{
    Q->base=(elem *)malloc(n+1*sizeof(elem));
    if(!Q)
        return ERROR;
    Q->len=n+1;
    Q->front=Q->rear=0;
    return OK;
}
/************
清空队列
*************/
int clear_queue(queue *Q)
{
    Q->rear=Q->front;
    return OK;
}
/************
插入元素
**************/
int Enqueue(queue *Q,elem data)
{
    if((Q->rear+1)%Q->len==Q->front)
    {
        printf("队列已满\n");
        return OVERFLOW;
    }
    Q->base[Q->rear]=data;
    Q->rear=(Q->rear+1)%Q->len;
    return OK;
}
/*****************
得到队头
********************/
int get_head(queue *Q,elem * data)
{
    if(Q->front==Q->rear)
    {
        printf("队列为空\n");
        return ERROR;
    }
    *data=Q->base[Q->front];
    return OK;
}
/*******************
出队列
***********************/
int Dequeue(queue *Q,elem *data)
{
    if(Q->front==Q->rear)
    {
        printf("队列为空\n");
        return ERROR;
    }
    *data=Q->base[Q->front];
    Q->front=(Q->front+1)%Q->len;
    return OK;
}
/********************
输出队列
**********************/
int printf_queue(queue *Q)
{
    int i;
    if(Q->front==Q->rear)
        printf("空\n");
    else if(Q->front<Q->rear)
    {
        for(i=Q->front; i<Q->rear; i++)
            printf("%d ",Q->base[i]);
    }
    else if(Q->front>Q->rear)
    {
        for(i=Q->front; i<Q->len; i++)
            printf("%d ",Q->base[i]);
        for(i=0; i<Q->rear; i++)
            printf("%d ",Q->base[i]);
    }
    printf("\b\n");
    return OK;
}
/*********
队列长
**********/
int queue_length(queue *Q)
{
    if(Q->rear>=Q->front)
        return (Q->rear)-(Q->front);
    else
        return ((Q->len)-(Q->front))+(Q->rear);
}
int main()
{
    int n;   //n个人
    int m;   //数到m出列
    queue Q;
    int temp;
    int i;
    elem data;
    printf("请输入n个人，数到m出列,从i开始\n");
    scanf("%d %d %d",&n,&m,&i);
    queue_init(&Q,n);
    for(temp=0; temp<n; temp++)
    {
        Enqueue(&Q,temp+1);
    }
    for(temp=1; temp<i; temp++)
    {
        Dequeue(&Q,&data);
        Enqueue(&Q,data);
    }
    while(queue_length(&Q)-1)
    {
        for(temp=1; temp<m; temp++)
        {
            Dequeue(&Q,&data);
            Enqueue(&Q,data);
        }
        Dequeue(&Q,&data);
        printf("%d ",data);
    }
    get_head(&Q,&data);
    printf("%d\n",data);
    return 0;
}
