#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        int i,max,tem,sum=1;
        scanf("%d",&max);
        for(i=0;i<n-1;i++)
        {
            sum*=2;
            scanf("%d",&tem);
            if(tem>max)
            {
                max=tem;
            }
            sum%=2006;
        }
        max%=2006;
        sum*=max;
        sum%=2006;
        if(sum<0) sum+=2006;
        printf("%d\n",sum);
    }
    return 0;
}
