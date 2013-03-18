#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N;
	while(scanf("%d",&N)==1)
	{
		fflush(stdin);
		int *x,*y,i,j,count;
		double *z;
		x=(int *)malloc(sizeof(int)*N);
		y=(int *)malloc(sizeof(int)*N);
		z=(double *)malloc(sizeof(double)*N);
		for(i=0;i<N;i++)
		{
			scanf("%d %d",&x[i],&y[i]);
			fflush(stdin);
			z[i]=0;
		}
		for(i=0;i<N;i++)
		{
			count=0;
			for(j=0;j<N;j++)
			{
				if(x[j]==x[i])
				{
					count++;
					z[i]+=y[j];
				}
			}
			z[i]/=double(count);
		}
		for(i=1;i<N;i++)
		{
			if(!(z[i]-z[0]<0.00001&&z[i]-z[0]>-0.00001))
			{
				printf("No\n");
				break;
			}
		}
		if(i==N) printf("Yes\n");
	}
	return 0;
}