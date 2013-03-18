#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

template<class T> T mmax(T a,T b){return a>b?a:b;}
template<class T> T mmin(T a,T b){return a<b?a:b;}
template<class T> T mabs(T a){return a>0?a:-a;}

#define MIMAX 0x7fffffff
#define MIMIN 0xffffffff
#define ZERO 1e-7

int main()
{
	vector<ull> all(101);
	all[0]=1;
	all[1]=1;
	int i;
	for(i=2;i<=100;i++)
	{
		int j;
		for(j=0;j<=i-1;j++)
		{
			all[i]+=all[j]*all[i-1-j];
		}
	}
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1) break;
		printf("%llu\n",all[n]);
	}
	return 0;
}