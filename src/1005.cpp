#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N,SIZE;
    while(scanf("%d",&N)==1)
    {
        fflush(stdin);
        int *s,*p,*v,i,j,tmp;
        s=(int *)malloc(sizeof(int)*(N+1));
        p=(int *)malloc(sizeof(int)*(N+1));
        //printf("%d %d %d",s[0],s[1],s[2]);
        for(i=1;i<=N;i++)
        {
            scanf("%d %d",&s[i],&p[i]);
            fflush(stdin);
        }
        scanf("%d",&SIZE);
        fflush(stdin);
        v=(int *)malloc(sizeof(int)*(SIZE+1));
        for(i=0;i<=SIZE;i++) v[i]=0;
        for(i=1;i<=N;i++)
        {
            for(j=SIZE;j>0;j--)
            {
                if(j>=s[i])
                {
                    tmp=v[j-s[i]]+p[i];
                    v[j]>tmp?1:v[j]=tmp;
                }
            }
        }
        printf("%d\n",v[SIZE]);
    }
    return 0;
}