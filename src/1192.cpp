#include<stdio.h>

int k(int p)
{
    int tmp=0;
    if(0==p) return 0;
    while(p!=1)
    {
        if(p%2==1) tmp++;
        p=p/2;
    }
    tmp++;
    if(tmp%2==1) return 1;
    else return 0;
}

int main()
{
    int N,a[40];
    while(scanf("%d",&N)!=EOF)
    {
        int i,p,j;
        for(j=0;j<N;j++)
        {
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<N;i++)
        {
            printf("%d",k(a[i]));
            if(i==N-1) printf("\n");
            else printf(" ");
        }
        }
    }
    return 0;
}