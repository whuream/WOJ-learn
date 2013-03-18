#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int p(int a,int b,int m)
{
	if(a==0 && b==0) return 1;
	if(a==0) return 0;

	a%=m;
	int ans=1;
	int base=a;
	while(b!=0)
	{
		if(b%2==1)
		{
			ans*=base;
			ans%=m;
		}
		base*=base;
		base%=m;
		b/=2;
	}
	return ans;
}

int main()
{
	int i,j;
	int T;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		int M,H;
		scanf("%d %d",&M,&H);
		int ans=0;
		for(j=0;j<H;j++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			ans+=p(a,b,M);
			ans%=M;
		}
		ans=(ans+M)%M;
		printf("%d\n",ans);
	}
	return 0;
}