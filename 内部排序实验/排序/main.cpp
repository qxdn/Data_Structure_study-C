#include <stdio.h>
#include <stdlib.h>
#define elem int
#define list_init_size 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2
elem data[8]= {49,38,65,97,76,13,27,49}; //待排序数据
typedef struct sqlist
{
    elem* Elem;
    int length;
    int list_size;
} SqList;
/********************
顺序表初始化
********************/
int SqList_init(SqList &L)
{
    L.Elem=(elem*)malloc(list_init_size*sizeof(elem));
    if(NULL==L.Elem)
        return OVERFLOW;
    L.list_size=list_init_size;
    L.length=0;
    return OK;
}
/********************
摧毁顺序表
********************/
void destory_SqList(SqList &L)
{
    free(L.Elem);
    L.length=0;
    L.list_size=0;
}
/*****************
装填初值
*****************/
int Reload_data(SqList &L)
{
    int data_i;
    for(data_i=0; data_i<(sizeof(data)/sizeof(elem)); data_i++)    //将数据填入顺序表
        L.Elem[data_i]=data[data_i];
    L.length=(sizeof(data)/sizeof(elem));
    return OK;
}
/*****************************
输出顺序表值
******************************/
void printf_Sqlist(SqList &L)
{
    int i;
    for(i=0; i<L.length; i++)
        printf("%d ",L.Elem[i]);
    printf("\b\n");
}
/***************************
简单插入排序  v1PASS
**************************/
void insertsort(SqList &L)
{
    int i;
    int j;
    int temp;
    for(i=1; i<L.length; i++)      //从第二项开始找
    {
        temp=L.Elem[i];                 //暂时保存最后一项即插入项
        for(j=i; j>0; j--)
        {
            if(temp<L.Elem[j-1])     //如果插入项大于当前项后移
            {
                L.Elem[j]=L.Elem[j-1];
            }
            else                     //找到插入点
                break;
        }
        L.Elem[j]=temp;      //插入
    }
}
/***********************
交换顺序表的两个元素
************************/
void swap_sqlist(elem *a,elem *b)
{
    elem temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
/************************
冒泡排序  v1PASS
************************/
void Bubble_sort(SqList &L)
{
    int i,j;
    for(i=0; i<L.length-1; i++)
        for(j=i+1; j<L.length; j++)
        {
            if(L.Elem[i]>L.Elem[j])
            {
                swap_sqlist(&L.Elem[i],&L.Elem[j]);
            }
        }
}
/**********************
排序找中轴位置
***********************/
int partiton(SqList &L,int low,int high)
{
    while(low<high)
    {
        while(low<high&&L.Elem[high]>=L.Elem[low])
            high--;
        swap_sqlist(&L.Elem[low],&L.Elem[high]);
        while(low<high&&L.Elem[high]>=L.Elem[low])
            low++;
        swap_sqlist(&L.Elem[low],&L.Elem[high]);
    }
    return low;
}
/**************************
递归进行快速排序
***************************/
void qsort(SqList &L,int low,int high)
{
    int pivotloc;     //中轴
    if(low<high)
    {
        pivotloc=partiton(L,low,high);
        qsort(L,low,pivotloc-1);
        qsort(L,pivotloc+1,high);
    }
}
/***************************
快速排序 v1pass
*****************************/
void quick_sort(SqList &L)
{
    qsort(L,0,L.length-1);
}
/*************************
归并排序 合并
**************************/
void Merge(SqList temp_L,SqList &L,int i,int m, int n)
{
    //将i~m和m+1~n合并
    int j,k;
    for(j=m+1,k=i; i<=m&&j<=n; k++)             //比较大小合并
        if(temp_L.Elem[i]<=temp_L.Elem[j])
            L.Elem[k]=temp_L.Elem[i++];
        else
            L.Elem[k]=temp_L.Elem[j++];
    while(i<=m)                               //合并剩下
        L.Elem[k++]=temp_L.Elem[i++];
    while(j<=n)                              //合并剩下
        L.Elem[k++]=temp_L.Elem[j++];
}
/***************************
归并排序 分开排序 递归法
****************************/
void Msort(SqList temp_L,SqList &L,int s,int t)
{
    SqList temp_L_1;
    int m;
    SqList_init(temp_L_1);
    if(s==t)
        L.Elem[s]=temp_L.Elem[s];
    else
    {
        m=(s+t)/2;    //temp_L平分两路s~m,m+1~t
        Msort(temp_L,temp_L_1,s,m);   //排序s~m
        Msort(temp_L,temp_L_1,m+1,t); //排序m+1~t
        Merge(temp_L_1,L,s,m,t);  //合并转移到L
    }
    destory_SqList(temp_L_1);
}
/***********************
归并排序 pass
***********************/
void Mergesort(SqList &L)
{
    Msort(L,L,0,L.length-1);
}
/******************
制作一个堆顶
********************/
void head_adjust(SqList &L,int s, int m)
{
    int i;
    elem temp;
    temp=L.Elem[s];
    for(i=2*s+1; i<m; i=i*2+1)//左子节点开始
    {
        if(i+1<m&&L.Elem[i]<L.Elem[i+1])   //如果左子节点大于右子节点，指向右子节点
            i++;
        if(temp<L.Elem[i]) //如果子节点大于父节点
        {
            L.Elem[s]=L.Elem[i];
            s=i;
        }
        else
            break;
    }
    L.Elem[s]=temp;
}
/**********************
堆排序 pass
************************/
void headsort(SqList &L)
{
    int i;
    for(i=L.length/2-1; i>=0; i--)      //从最后一个非终端节点开始
        head_adjust(L,i,L.length);
    for(i=L.length-1; i>0; i--)
    {
        swap_sqlist(&L.Elem[0],&L.Elem[i]);
        head_adjust(L,0,i);
    }
}
void print_menu(void)
{
    printf("1、输出原始序列\n");
    printf("2、输出简单插入排序结果\n");
    printf("3、输出冒泡排序结果\n");
    printf("4、输出快速排序结果\n");
    printf("5、输出归并排序结果\n");
    printf("6、输出堆排序结果\n");
    printf("7、重新装载初值\n");
    printf("8、退出\n");
}
int main()
{
    SqList L;   //排序用
    int choice;
    SqList_init(L);
    Reload_data(L);
    print_menu();
    while(scanf("%d",&choice)&&choice!=8)
    {
        switch(choice)
        {
        case 1:
            Reload_data(L);
            printf_Sqlist(L);
            break;
        case 2:
            insertsort(L);
            printf_Sqlist(L);
            break;
        case 3:
            Bubble_sort(L);
            printf_Sqlist(L);
            break;
        case 4:
            quick_sort(L);
            printf_Sqlist(L);
            break;
        case 5:
            Mergesort(L);
            printf_Sqlist(L);
            break;
        case 6:
            headsort(L);
            printf_Sqlist(L);
            break;
        case 7:
            Reload_data(L);
            printf_Sqlist(L);
            break;
        }
        print_menu();
    }
    destory_SqList(L);
    return 0;
}
