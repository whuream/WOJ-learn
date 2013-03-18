#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef vector<vector<int> > mint;

int max(int a,int b){return a>b?a:b;}

int main()
{
	int K;
	while(scanf("%d",&K)==1)
	{
		vector<int> data(K+1);
		int sum=0;
		int i;
		for(i=1;i<=K;i++)
		{
			scanf("%d",&data[i]);
			sum+=data[i];
		}
		int m=sum/2;
		mint all(K+1,vector<int>(m+1));
		for(i=1;i<=K;i++)
		{
			int j;
			for(j=1;j<=m;j++)
			{
				if(j-data[i]>=0)
					all[i][j]=max(all[i-1][j],all[i-1][j-data[i]]+data[i]);
				else
					all[i][j]=all[i-1][j];
			}
		}
		int ans=sum-2*all[K][m];
		printf("%d\n",ans);
	}
	return 0;
}