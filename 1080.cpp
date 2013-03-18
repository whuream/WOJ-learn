#include<stdio.h>

int main()
{
	int T,i;
	long int N;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%ld",&N);
		if((N+14)%14==0) printf("snoopy wins the game!\n");
		else printf("flymouse wins the game!\n");
	}
	return 0;
}