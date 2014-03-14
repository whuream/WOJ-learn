#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,min=10000,sum=0;
    while(scanf("%d",&n)==1)
    {
        int *p[8];
        for(i=0;i<8;i++)
        {
            p[i]=(int *)malloc(sizeof(int)*n);
        }
        for(i=0;i<8;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&p[i][j]);
            }
            //printf("this is i:%d\n",i);
        }
       // printf("***");
        for(j=0;j<n;j++)
        {
            for(i=0;i<8;i++)
            {
                if(p[i][j]<min)
                min=p[i][j];
            }
            sum+=min;
            min=10000;
        }
        printf("%d\n",sum);
        sum=0;
    }
    return 0;
}
