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

int c(int n,int &m)
{
	if(n==2) return 1;
	if((c(n-1,m)+m)%(n-1)!=0)
		return (c(n-1,m)+m)%(n-1);
	else return n-1;
}

int main()
{
	int n,m;
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) break;

		int ans=c(n+1,m);
		printf("%d\n",ans);
	}
	return 0;
}