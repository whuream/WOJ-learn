#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

#define N 5000000

//素数打表
void c(mint &all)
{
	int m;
	int i;
	for(i=1;i<4;i++)
	{
		if(i==1) m=100;
		if(i==2) m=2250;
		if(i==3) m=N;
		
		int j;
		for(j=2;j<m;j++)
		{
			int k;
			for(k=0;k<all[i-1].size();k++)
			{
				if(j%all[i-1][k]==0 && j!=all[i-1][k])
					break;
			}
			if(k==all[i-1].size()) all[i].push_back(j);
		}
	}
}

//all[3]为小于N的素数
void getdata(mint &all,vector<bool> &data)
{
	int i;
	for(i=0;i<all[3].size();i++)
	{
		ull tmp;
		tmp=all[3][i];
		while(tmp<N)
		{
			data[tmp]=true;
			tmp*=all[3][i];
		}
	}
}

//data为小于N pure number分布情况
void  getans(vector<bool> &data,vector<int> &ans)
{
	int ret=0;
	int i;
	for(i=0;i<data.size();i++)
	{
		if(data[i]==true)
		{
			ret++;
			ans[ret]=i;
		}
	}
}

int main()
{
	mint all(4);
	vector<int> vtmp;
	vtmp.push_back(2);
	vtmp.push_back(3);
	vtmp.push_back(5);
	vtmp.push_back(7);
	all[0]=vtmp;

	vector<bool> data(N);
	vector<int> ans(N);

	c(all);
	getdata(all,data);

	getans(data,ans);

	int n;
	while(scanf("%d",&n)==1)
	{
		if(ans[n]==0) printf("-1\n");
		else printf("%d\n",ans[n]);
	}
	return 0;
}