#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef vector< vector<int>> mint;

int count(mint &data,int &m,int &n)
{
	int ans=0;
	int i,j;
	for(i=0;i<n;i++)
	{
		int mc=0;
		for(j=0;j<m;j++) if(data[j][i]==1) mc++;
		
		if(mc<=m/2) ans+=m-mc;
		else ans+=mc;
	}
	return ans;
}

void getans(mint &data,int &m,int &n,int t,int &ans)
{
	if(t==m) return;
	else
	{
		int c;
		c=count(data,m,n);
		if(ans<c) ans=c;

		getans(data,m,n,t+1,ans);

		int i;
		for(i=0;i<n;i++) data[t][i]=!data[t][i];

		c=count(data,m,n);
		if(ans<c) ans=c;

		getans(data,m,n,t+1,ans);

		for(i=0;i<n;i++) data[t][i]=!data[t][i];
	}
}


int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)==2)
	{
		 mint data(m,vector<int>(n));

		int i,j;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++) scanf("%d",&data[i][j]);
		}
		int ans=0;
		getans(data,m,n,0,ans);
		printf("%d\n",ans);
	}
	return 0;
}