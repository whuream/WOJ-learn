#include<stdio.h>

int main()
{
	int N,i,tmp,in;
	scanf("%d",&N);
	scanf("%d",&tmp);
	for(i=2;i<=N*2+1;i++)
	{
		scanf("%d",&in);
		tmp^=in;
	}
	printf("%d\n",tmp);
	return 0;
}