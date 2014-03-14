#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef vector<vector<int> > mint;

#define MMIN -1000000000;
#define MMAX 1000000000;

int cou(mint &data,int &n)
{
	int max=MMIN;
	int i;
	for(i=0;i<n;i++)
	{
		int maxtmp=0;
		int j;
		for(j=0;j<n;j++)
			maxtmp+=data[j][i];
		if(maxtmp>max) max=maxtmp; 
	}
	return max;
}

void c(mint &data,int &n,int t,int &ans)
{
	if(t==n) return;
	int i;
	for(i=0;i<n;i++)
	{
		int j;
		int tmp=data[t][n-1];
		for(j=n-2;j>=0;j--) data[t][j+1]=data[t][j];
		data[t][0]=tmp;
		int tmpmax=cou(data,n);
		if(tmpmax<ans) ans=tmpmax;
		c(data,n,t+1,ans);
	}
}

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1) break;

		mint data(n,vector<int>(n));
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&data[i][j]);
		int ans=MMAX;
		c(data,n,0,ans);
		printf("%d\n",ans);
	}
	return 0;
}