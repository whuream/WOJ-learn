#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n,cas=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1) break;
        cas++;
        int *a,i,raw=0,num=0;
        a=(int *)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
            if(a[i]==1)
                break;
        for(;i<n;i++)
        {
            if(a[i]==1) raw++;
            if(a[i]==-1) num+=raw;
        }
        printf("Case %d: %d\n",cas,num);
    }
    return 0;
}
