#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N;
	while(scanf("%d",&N)==1)
	{
		int a[500000],num;
		
		int i,loop=0,na=0,nb=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
			if(loop==0)
			{
				loop++;
				num=a[i];
			}
			else
			{

				if(num==a[i]) loop++;
				else loop--;
			}
		}
		if(loop!=0) printf("%d\n",num);
		else
		{
			for(i=0;i<N;i++)
			{
				if(a[i]==num) na++;
				if(a[i]==a[N-1]) nb++;
			}
		}
		na>nb?printf("%d\n",num):printf("%d\n",a[N-1]);
	}
	return 0;
}