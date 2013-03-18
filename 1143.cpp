#include<stdio.h>

int main()
{
	int p,n,m;
	while(1)
	{
		scanf("%d %d %d",&m,&p,&n);
		if(p==0)
		{
			break;
		}
		m>p*n?printf("%d\n",m):printf("%d\n",p*n);
	}
}