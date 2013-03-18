#include<stdio.h>

long long int a(int N)
{
	if(N==1) return 1;
	else if(N==2) return 2;
	else if(N==3) return 4;
	else return a(N-1)+a(N-2)+a(N-3);
}

int main()
{
	int N;
	while(scanf("%d",&N)==1)
	{
		if(N==0) break;
		fflush(stdin);
		printf("%lld\n",a(N));
	}
	return 0;
}