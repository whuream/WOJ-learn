#include<stdio.h>

int f(int m,int n)
{
    if(n==1) return 1;
    if(m<n) return f(m,n-1);
    return f(m,n-1)+f(m-n,n);
}

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)==2)
    {
        printf("%d\n",f(m,n));
    }
    return 0;
}
