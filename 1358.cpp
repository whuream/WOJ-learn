#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=0;i<T;i++)
	{
		unsigned long long a,b;
		scanf("%llu %llu",&a,&b);
		printf("%llu\n",(a-1)*(b-1)-1);
	}
	return 0;
}