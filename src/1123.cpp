#include<iostream>
#include<cstdio>

using namespace std;

typedef unsigned long long ull;

int main()
{
	ull a;
	while(scanf("%llu",&a)==1)
	{
		if(a==1) printf("1\n");
		else printf("%llu\n",a*2-2);
	}
	return 0;
}