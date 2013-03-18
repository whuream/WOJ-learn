#include<stdio.h>
#include<math.h>

int main()
{
	int N;
	while(scanf("%d",&N)==1)
	{
		printf("%d\n",(int)sqrt(double(N)));
	}
	return 0;
}