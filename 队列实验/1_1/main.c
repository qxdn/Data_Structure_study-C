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
    Q->base=(elem *)malloc((n+1)*sizeof(elem));
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
void print_mune()
{
    printf("请输入需要的功能\n");
    printf("1、初始化队列\n");
    printf("2、清空队列\n");
    printf("3、插入新元素\n");
    printf("4、获得队头元素\n");
    printf("5、删除队头\n");
    printf("6、输出队列\n");
    printf("7、退出\n");
}
int main()
{
    queue Q;
    int n=queue_init_size;
    int i;
    int flag=1;
    elem data;
    while(flag)
    {
        print_mune();
        scanf("%d",&i);
        switch (i)
        {
        case 1:
            printf("请输入队列长\n");
            scanf("%d",&n);
            queue_init(&Q,n);
            break;
        case 2:
            clear_queue(&Q);
            break;
        case 3:
            printf("请输入要插入的元素\n");
            scanf("%d",&data);
            Enqueue(&Q,data);
            break;
        case 4:
            get_head(&Q,&data);
            printf("队头是%d\n",data);
            break;
        case 5:
            Dequeue(&Q,&data);
            printf("被删除的是%d\n",data);
            break;
        case 6:
            printf_queue(&Q);
            break;
        case 7:
            flag=0;
            break;
        }
    }
    return 0;
}
