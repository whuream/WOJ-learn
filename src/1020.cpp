#include<stdio.h>
#include<stdlib.h>

void order(int seq[],int n)
{
    int i,j,tmp;
    for(i=1;i<n;i++)
    {
        tmp=seq[i];
        j=i-1;
        for(;j>=0&&tmp<seq[j];)
        {
            seq[j+1]=seq[j];
            j--;
        }
        seq[j+1]=tmp;
    }
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int N,flag=1,j;
        fflush(stdin);
        scanf("%d",&N);
        fflush(stdin);
        int *seq;
        seq=(int *)malloc(sizeof(int)*N);
        for(j=0;j<N;j++)
        {
            scanf("%d",&seq[j]);
        }
        fflush(stdin);
        for(j=N-1;j>0;j--)
        {
            seq[j]-=seq[j-1];
        }
        order(seq,N);
        printf("Case %d:\n",i+1);
        for(j=0;j<N;j++)
        {
            printf("%d",seq[j]);
            if(j!=N-1) printf(" ");
            else printf("\n");
        }
        if(i!=T-1) printf("\n");
    }
    return 0;
}
