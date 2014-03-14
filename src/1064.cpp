#include<stdio.h>

int main()
{
    int N,i,j,tmp;
    int a[1005];
    while(scanf("%d",&N)==1)
    {
        int len=0,flag=0,k;
        for(i=0;i<N;i++)
        {
            flag=0;
            scanf("%d",&tmp);
            for(j=len-1;j>=0&&a[j]>=tmp;j--)
            {
                if(a[j]==tmp)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(k=len-1;k>=j+1;k--)
                {
                    a[k+1]=a[k];
                }
                a[j+1]=tmp;
                len++;
            }
          //  for(k=0;k<len;k++) printf("%d ",a[k]);
          //  printf("\n");
        }
        //printf("============= %d\n",len);
        for(j=0;j<len;j++)
        {
            printf("%d",a[j]);
            if(j!=len-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
