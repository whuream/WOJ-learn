#include<stdio.h>

int main()
{
	int N,i,j;
	scanf("%d",&N);
	fflush(stdin);
	for(i=0;i<N;i++)
	{
		int year;
		scanf("%d",&year);
		fflush(stdin);
		int pre_y=1,pre_m=0,pre_o=0,y=0,m=0,o=0;
		long count=0;
		for(j=0;j<year*2;j++)
		{
			y=pre_o*2+pre_m*2;
			m=pre_y;
			o=pre_o+pre_m;
			pre_y=y;
			pre_o=o;
			pre_m=m;
		}
		count=y+m+o;
		printf("%ld\n",count);
	}
	return 0;
}