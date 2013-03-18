#include<stdio.h>

int zuida(int a,int b)
{
	return b==0?a:zuida(b,a%b);
}

int main()
{
	int a,b,n;
	while(scanf("%d%d%d",&a,&b,&n)==3)
	{
		if(a==0&&b==0)
		{
			if(n==0) printf("Possible!\n");
			else printf("Impossible!\n");
		}
		else
		{
			if(n%zuida(a,b)==0) printf("Possible!\n");
			else printf("Impossible!\n");
		}
	}
	return 0;
}