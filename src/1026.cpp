#include<stdio.h>


int max(int a, int b)
{
	return a>b?a:b;
}

int max(int a, int b, int c)
{
	return a>(b>c?b:c)?a:(b>c?b:c);
}

int main()
{
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		int a[1000]={0},pre=0,now;
		int b;
		int N,j,k,maxnum=0;
		scanf("%d",&N);
		for(j=0;j<N;j++)
		{
			for(k=0;k<N;k++)
			{
				now=a[k];
				scanf("%d",&b);
				if(k==0) a[k]=b+max(a[k],a[k+1]);
				else if(k==N-1) a[k]=b+max(a[k],pre);
				else a[k]=b+max(pre,a[k],a[k+1]);
				maxnum=max(maxnum,a[k]);
				pre=now;
			}
		}
		printf("Case %d:\n%d\n\n",i+1,maxnum);
	}
	return 0;
}