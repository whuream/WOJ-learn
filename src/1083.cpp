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

void out(mint &data,vector<int> &dsta,vector<int> &ans,int &ians,int t)
{
	if(dsta[t]==1) return;
	if(dsta[t]==2)
	{
		ians=1;
		return;
	}

	dsta[t]=2;
	int i;
	for(i=0;i<data[t].size();i++)
		out(data,dsta,ans,ians,data[t][i]);
	dsta[t]=1;
	ans.push_back(t);
}

void getans(mint &data,vector<int> &dsta,vector<int> &ans,int &ians)
{
	int n=data.size();
	int i;
	for(i=1;i<n;i++)
	{
			out(data,dsta,ans,ians,i);
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

		mint data(N+1);
		vector<int> dsta(N+1);
		int j;
		for(j=0;j<M;j++)
		{
			int itmp1,itmp2;
			scanf("%d %d",&itmp1,&itmp2);

			data[itmp1].push_back(itmp2);
		}
		for(j=0;j<=N;j++) sort(data[j].begin(),data[j].end());
		vector<int> ans;

		int ians=0;
		getans(data,dsta,ans,ians);
		if(ians==1) printf("-1\n");
		else
		{
			for(j=0;j<ans.size()-1;j++) printf("%d ",ans[j]);
			printf("%d\n",ans[j]);
		}
	}
	return 0;
}