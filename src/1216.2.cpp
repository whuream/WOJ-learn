#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int yingshe[8]={0,0,1,1,2,2,2,2};

int m_pow(int a,int b)
{
	int i;
	int ans=1;
	for(i=0;i<b;i++) ans*=a;
	return ans;
}


void c(vector<vector<int> > &all,int t)
{
	int m;
	if(t==1) m=100;
	if(t==2) m=10000;
	
	int i;
	for(i=2;i<m;i++)
	{
		int j;
		for(j=0;j<all[t-1].size();j++)
		{
			if(i%all[t-1][j]==0 && i!=all[t-1][j]) break;
		}
		if(j==all[t-1].size()) all[t].push_back(i);
	}
}

void cou(vector<vector<int> > &all,vector<vector<int> > &ans)
{
	int i;
	for(i=1;i<8;i++)
	{
		int key=yingshe[i];

		int j;
		for(j=0;j<ans[i-1].size();j++)
		{
			int itmp=ans[i-1][j]*10;

			int k;
			for(k=1;k<=9;k++)
			{
				int itmp2=itmp+k;
				int l;
				for(l=0;l<all[key].size();l++)
				{
					if(itmp2%all[key][l]==0 && itmp2!=all[key][l]) break;
				}
				if(l==all[key].size()) ans[i].push_back(itmp2);
			}
		}
	}
}

int main()
{
	vector<vector<int> > ans(8);

	vector<vector<int> > all(3);

	vector<int> vitmp;
	vitmp.push_back(2);
	vitmp.push_back(3);
	vitmp.push_back(5);
	vitmp.push_back(7);
	all[0]=vitmp;
	
	ans[0]=vitmp;

	c(all,1);
	c(all,2);

	cou(all,ans);

	int n;
	while(scanf("%d",&n)==1)
	{
		int i;
		for(i=0;i<ans[n-1].size();i++) printf("%d\n",ans[n-1][i]);
	}
	return 0;
}