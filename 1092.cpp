#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

#define N 5000000

void c(mint &all)
{
	int m;
	int i;
	for(i=1;i<4;i++)
	{
		if(i==1) m=100;
		if(i==2) m=1000;
		if(i==3) m=5000000;
		
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

void getdata(mint &all,vector<bool> &data)
{
	int i;
	for(i=0;i<all[3].size();i++)
	{
		ull tmp;
		tmp=all[3][i];
		while(tmp<data.size())
		{
			data[tmp]=true;
			tmp*=all[3][i];
		}
	}
}

int  getans(vector<bool> &data,vector<int> &ans)
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
	return ret;
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

	vector<bool> data(N+1000);
	vector<int> ans(N+1000);

	c(all);
	getdata(all,data);

	int len=getans(data,ans);

	int n;
	while(scanf("%d",&n)==1)
	{
		if(n>len) printf("-1\n");
		else if(ans[n]>5000000) printf("-1\n");
		else printf("%d\n",ans[n]);
	}
	return 0;
}