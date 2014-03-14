#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int N;
	while(scanf("%d",&N),N!=EOF)
	{
		fflush(stdin);
		long int *a;
		int i,j,*b;
		double line=0;
		a=(long int *)malloc(sizeof(long int)*2*N);
		b=(int *)malloc(sizeof(int)*N);
		for(i=0;i<N;i++) b[i]=0;
		for(i=0;i<N;i++)
		{
			scanf("%ld %ld",&a[2*i],&a[2*i+1]);
			fflush(stdin);
		}
		for(i=0;i<N;i++)
		{
			line+=(double)a[i*2+1];
		}
		line/=N;
		/*for(i=0;i<N;i++)
		{
			for(j=i;j<N;j++)
			{
				if(b[i]==0&&b[j]==0&&a[2*i]==a[2*j]&&abs(double(a[2*i+1]+a[2*j+1])/2-line)<0.00001) b[i]=b[j]=1;
			}
		}*/
		for(i=0;i<N;i++)
		{
			if(b[i]==0)
			{
				printf("NO\n");
				break;
			}
		}
		if(i==N) printf("YES\n");
		free(a);
		free(b);
	}
	return 0;
}