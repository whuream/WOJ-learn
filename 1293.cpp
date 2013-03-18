#include<stdio.h>

int main()
{
	int M,N,F[10][10];
	while(scanf("%d%d",&M,&N)==2)
	{
		if(M==0&&N==0) break;
		int i,p=M,j;
		for(i=0;i<N;i++)
		{
			for(j=i;j>=0;j--)
			{
				F[N-1-j][i-j]=p;
				p++;
			}
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(F[i][j]<10) printf(" ");
				printf("%d ",F[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}