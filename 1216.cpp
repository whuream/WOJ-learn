#include<stdio.h>

int main()
{
	int N,i,j,k,l,m;
	long int tmp;
	int a[4]={2,3,5,7};
	while(scanf("%d",&N)==1)
	{
		tmp=0;
		for(i=0;i<4;i++)
		{
			tmp=a[i];
			for(j=1;j<=9;i++)
			{
				tmp=tmp*10+j;
				for(k=2;k<tmp/2)
				{
					if(tmp%k==0) break;
				}
				if(k==tmp/2+1) 
			}
		}
	}
}