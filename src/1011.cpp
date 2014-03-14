#include<stdio.h>

long long int cxx(int a,int b)
{
	long long int sum=1;
	int i;
	for(i=0;i<b;i++)
		sum=sum*(a-i);
	for(i=b;i>0;i--)
		sum=sum/i;
	return sum;
}

int main()
{
	int N;
	while(scanf("%d",&N)==1)
	{
		printf("%lld\n",cxx(N,3));
	}
	return 0;
}