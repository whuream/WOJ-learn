#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

int mmax(int a,int b){return a>b?a:b;}
int mmin(int a,int b){return a<b?a:b;}
int mabs(int a){return a>0?a:-a;}

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=0;i<T;i++)
	{
		string a,b;
		int c;
		cin>>a>>b>>c;
		vector<int> data(a.length());
		int j;
		for(j=0;j<a.length();j++)
		{
			data[j]=mabs(a[j]-b[j]);
		}
		sort(data.begin(),data.end());
		for(j=0;j<c;j++)
		{
			if(data[data.size()-1-j]!=0) data[data.size()-1-j]=0;
			else data[data.size()-1-j]=1;
		}
		int ans=0;
		for(j=0;j<data.size();j++) ans+=data[j];

		printf("%d\n",ans);
	}
	return 0;
}