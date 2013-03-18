#include<stdio.h>

int main()
{
    int n,i,j,num,tem;
    while(scanf("%d",&n)==1)
    {
        num=0;
        for(i=1;i<n+1;i++)
        {
            tem=0;
            for(j=1;j<=i/2;j++)
            {
                if(i%j==0) tem++;
            }
            if(tem%2==0) num++;
        }
        printf("%d\n",num);
    }
    return 0;
}
