#include<stdio.h>
#include<stdlib.h>


/*
			你妹的，YES，NO要小写！！！！！！！！！！！F@CK！！！！！！！！
*/

int check(int *x,int *y,int *z,int N,int sum)
{
	int i,j;
	sum*=2;
	if(sum%N!=0) return 0;
	else
	{
		sum/=N;
		for(i=0;i<N;i++)
		{
			if(z[i]==0&&y[i]*2!=sum)
			{
				for(j=i+1;j<N;j++)
				{
					if(x[j]==x[i]&&y[i]+y[j]==sum)
					{
						z[i]=z[j]=1;
						break;
					}
				}
				if(j==N) return 0;
			}
		}
		return 1;
	}
}

int main()
{
	int N;
	while(scanf("%d",&N)==1)
	{
		int *x,*y,*z,i;
		int sum=0;
		x=(int *)malloc(sizeof(int)*N);
		y=(int *)malloc(sizeof(int)*N);
		z=(int *)malloc(sizeof(int)*N);
		for(i=0;i<N;i++)
		{
			scanf("%d %d",&x[i],&y[i]);
			sum+=y[i];
			z[i]=0;
		}
		if(check(x,y,z,N,sum)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}