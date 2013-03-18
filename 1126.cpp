#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

template<class T> T mmax(T a,T b){return a>b?a:b;}
template<class T> T mmin(T a,T b){return a<b?a:b;}
template<class T> T mabs(T a){return a>0?a:-a;}

#define MIMAX 0x7fffffff
#define MIMIN 0xffffffff

int main()
{
	vector<int> data(1000005);
	int i;
	for(i=2;i<=1000000;i++)
	{
		if(data[i]==0)
		{
			int j;
			for(j=i;j<=1000000;j+=i)
			{
				if(data[j]==0) data[j]=j;
				data[j]=data[j]/i*(i-1);
			}
		}
	}
	vector<ull> ans(1000005);
	for(i=2;i<=1000000;i++) ans[i]=ans[i-1]+data[i];
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("%llu\n",ans[n]);
	}
	return 0;
}