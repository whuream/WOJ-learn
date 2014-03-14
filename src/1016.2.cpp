#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int N;
	while(scanf("%d",&N)==1)
	{
		int *a,i;
		long int up=0;
		double line=0;
		a=(int *)malloc(sizeof(int)*2*N);
		for(i=0;i<N;i++)
		{
			fflush(stdin);
			scanf("%d %d",&a[2*i],&a[2*i+1]);
		}
		for(i=0;i<N;i++)
		{
			line+=(double)a[i*2+1];
		}

		line/=N;
		for(i=0;i<N;i++)
		{
			if(double(a[2*i+1])-line>0.00001)
				up+=a[2*i];
			else if(double(a[2*i+1])-line<-0.00001) up-=a[2*i];
		}
		if(up==0) printf("YES\n");
		else printf("NO\n");
		free(a);
		fflush(stdin);
	}
	return 0;
}