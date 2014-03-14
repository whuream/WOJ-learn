#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N,M;
	while(scanf("%d%d",&N,&M)==2)
	{
		fflush(stdin);
		int *a;
		a=(int *)malloc(sizeof(int)*N);
		for(int i=0;i<N;i++) a[i]=1;
		int b=-1,r=N;
		while(r!=0)
		{
			b=(b+M)%N;
			while(a[b]==0) b=(b+1+N)%N;
			printf("%d ",b+1);
			r--;
			a[b]=0;
		}
	}
	return 0;
}