#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int *a;
    a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        int m,n,num=0;
        scanf("%d%d",&m,&n);
        for(j=m;j<8;j++)
        {
        switch(j)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            {
                num+=31;
                break;
            }
            case 2:
            {
                num+=29;
                break;
            }
            case 4: case 6: num+=30;
        }
     //   printf("%d\n",num);
        }
        a[i]=num-n+8;
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(i!=n-1) printf("\n");
    }
}
