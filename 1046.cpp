#include<stdio.h>

int main()
{
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		int N,a[3000],j,k,tmp,sum=0;
		scanf("%d",&N);

		for(j=0;j<N;j++)
		{
			scanf("%d",&a[j]);
		}

		for(j=0;j<N-1;j++)
			for(k=N-1;k>j;k--)
			{
				if(a[k]<a[k-1])
				{
					tmp=a[k-1];
					a[k-1]=a[k];
					a[k]=tmp;
					sum++;
				}
			}
		printf("%d\n",sum);
	}
	return 0;
}