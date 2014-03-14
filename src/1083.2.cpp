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
	int T;
	scanf("%d",&T);

	int i;
	for(i=0;i<T;i++)
	{
		int N,M;
		scanf("%d %d",&N,&M);
		
		mint data(N+1);
		vector<int> sta(N+1);
		vector<int> ans;

		int j;
		for(j=0;j<M;j++)
		{
			int itmp1,itmp2;
			scanf("%d %d",&itmp1,&itmp2);
			data[itmp1].push_back(itmp2);
		}
		while(1)
		{
			vector<int> vitmp;
			for(j=1;j<=N;j++)
			{
				if(sta[j]==0)
				{
					int k;
					for(k=0;k<data[j].size();k++)
					{
						int key=data[j][k];
						if(sta[key]==0) break;
					}
					if(k==data[j].size())
					{
						vitmp.push_back(j);
						sta[j]=1;
					}
				}
			}
			if(vitmp.empty()) break;
			sort(vitmp.begin(),vitmp.end());
			for(j=0;j<vitmp.size();j++) ans.push_back(vitmp[j]);
		}
		for(j=1;j<=N;j++)
		{
			if(sta[j]==0) break;
		}
		if(j!=N+1) printf("-1\n");
		else
		{
			for(j=0;j<ans.size()-1;j++) printf("%d ",ans[j]);
			printf("%d\n",ans[j]);
		}

	}
	return 0;
}