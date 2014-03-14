#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    int *winner;
    winner=(int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        fflush(stdin);
        int card,xay=0,amr=0,j,k,turn=0;
        scanf("%d",&card);
        int *row;
        row=(int *)malloc(sizeof(int)*card);
        fflush(stdin);
        for(j=0;j<card;j++)
        {
            turn++;
            scanf("%d",&row[j]);
            for(k=0;k<j;k++)
            {
                if(row[k]==row[j])
                {
                    if(turn%2==1) xay+=j-k+1;
                    else amr+=j-k+1;
                    card-=j-k+1;
                    j=k-1;
                }
            }
        }
        if(amr>=xay) winner[i]=0;
        else winner[i]=1;
    }
    for(i=0;i<n;i++)
    {
        if(winner[i]==1) printf("xay");
        else printf("amr");
        if(i!=n-1) printf("\n");
    }
    return 0;
}
