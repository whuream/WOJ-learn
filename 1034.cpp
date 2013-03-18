#include<stdio.h>

int main()
{
	long long int N;
	while(scanf("%lld",&N)==1)
	{
		fflush(stdin);
		//if(N==0) printf("0\n");
		 printf("%lld\n",(N*N*N+5*N+6)/6);
	}
	return 0;
}