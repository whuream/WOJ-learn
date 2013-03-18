#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n,i,j;
    //while(scanf("%d",&n)==1)
    {
        n=10;
        int num=(n+1)/2;
        int *a,*b;
        a=(int *)malloc(sizeof(int)*(n+1));
        b=(int *)malloc(sizeof(int)*(n+1));
        for(i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                a[i]=0;
                b[i]=1;
            }
            else
            {
                a[i]=1;
                b[i]=0;
            }
        }
        for(i=3;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if((j>=i)&&(j%i==0))
                {
                    if(a[j]==1)
                    {
                        a[j]=0;
                        b[j]=1;
                        num--;
                        break;
                    }
                    if(b[j]==1)
                    {
                        b[j]=0;
                        a[j]=1;
                        num++;
                    }
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
