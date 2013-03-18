#include<stdio.h>


int max(int a,int b)
{
	return a>b?a:b;
}

int max(int a,int b,int c)
{
	return a>(b>c?b:c)?a:(b>c?b:c);
}



int main()
{
	
	int N,i;

	scanf("%d",&N);

	for(i=0;i<N;i++)
	{
		int F[1002]={0};
		int p[1002];
		int tmp[1002];
		int a,b,j,k,maxdollor=0;
		scanf("%d%d",&a,&b);
		for(j=0;j<a;j++)
		{

			for(k=0;k<b;k++) scanf("%d",&p[k]);

			for(k=0;k<b;k++) tmp[k]=F[k];

			for(k=0;k<b;k++)
			{
				if(k==0) F[k]=tmp[k]+p[k];
				else F[k]=p[k]+max(F[k-1],tmp[k-1],tmp[k]);
				maxdollor<F[k]?maxdollor=F[k]:1;
			}
		}
		printf("Case #%d: %d\n",i+1,maxdollor);
	}
}