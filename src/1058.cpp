#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<cstring>

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
	int c;
	while(1)
	{
		scanf("%d",&c);
		if(c==0) break;
		ull end=c/2;
		ull m=c/3;
		ull ans=(m+1)+(m+1)*m/2+(end-m)*(c+1)-(end+m+1)*(end-m);
		printf("%llu\n",ans);
	}
	return 0;
}