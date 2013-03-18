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

mint data(100001);

void g(mint &data,vector<int> &dsta,int t,int x,int &ians)
{
	if(x==t)
	{
		ians=true;
		return;
	}
	if(dsta[x]==1) return;

	dsta[x]=1;
	data[t].push_back(x);
	int i;
	for(i=0;i<data[x].size();i++)
		g(data,dsta,t,data[x][i],ians);
}

bool f(int a,int b)
{
	int i;
	for(i=0;i<data[a].size();i++)
	{
		if(data[a][i]==b) break;
	}
	if(i==data[a].size()) return false;
	return true;
}

bool c(int a,int b)
{
	if(a<b)
	{
		if(f(a,b)) return false;
		return true;
	}
	else
	{
		if(f(b,a)) return true;
		return false;
	}
}

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=0;i<T;i++)
	{
		int N,M;
		scanf("%d %d",&N,&M);

		
		int j;
		for(j=1;j<=N;j++) data[j].clear();
		for(j=0;j<M;j++)
		{
			int itmp1,itmp2;
			scanf("%d %d",&itmp1,&itmp2);
			data[itmp1].push_back(itmp2);
		}

		int ians=false;
		for(j=1;j<=N;j++)
		{
			vector<int> dsta(N+1);
			int k;
			for(k=0;k<data[j].size();k++)
			{
				//dsta[data[j][k]]=1;
				g(data,dsta,j,data[j][k],ians);
			}
		}
		if(ians) printf("-1\n");
		else
		{
			vector<int> ans(N+1);
			for(j=1;j<=N;j++) ans[j]=j;
			sort(ans.begin()+1,ans.end(),c);
			for(j=1;j<N;j++) printf("%d ",ans[j]);
			printf("%d\n",ans[j]);
		}
	}
	return 0;
}