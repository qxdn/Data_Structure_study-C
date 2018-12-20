#include <stdio.h>
#include <stdlib.h>

int g_m_n(int m,int n)
{
    if(m==0)
        return 0;
    return (g_m_n(m-1,2*n)+n);
}

int main()
{
    int m,n;
    printf("请输入m和n\n");
    scanf("%d %d",&m,&n);
    printf("值是：%d\n",g_m_n(m,n));
}
