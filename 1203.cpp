#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N;
	while(scanf("%d",&N)==1)
	{
		int i,*a,num=0,loop=0,tmp;
		for(i=0;i<N;i++)
		{
			scanf("%d",&tmp);
			if(loop==0)
			{
				loop++;
				num=tmp;
			}
			else
			{
				if(tmp==num) loop++;
				else loop--;
			}
		}
		printf("%d\n",num);
	}
	return 0;
}