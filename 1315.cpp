#include<stdio.h>

long long int mol(int a,int b,int c)
{
	long long int t;
	if(b==1) return a%c;
	t=mol(a,b/2,c);
	t=t*t%c;
	if(b%2==1) t=t*a%c;
	return t;
}

int main()
{
	int a,b,c;
	while(1)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==0&&b==0&&c==0) break;
		printf("%lld\n",mol(a,b,c));
	}
	return 0;
}