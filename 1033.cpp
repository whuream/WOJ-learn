#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<cstring>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

int mmax(int a,int b){return a>b?a:b;}
int mmin(int a,int b){return a<b?a:b;}
int mabs(int a){return a>0?a:-a;}

int main()
{
	int a,b,m,n;
	while(scanf("%d %d %d %d",&a,&b,&m,&n)==4)
	{
		vector<int> all(a*b);
		int i,j;
		for(i=0;i<b;i++)
		{
			for(j=0;j<a;j++)
			{
				int tmp=a*i+b*j;
				if(tmp<a*b) all[tmp]=1;
			}
		}
		int ans=0;
		if(n>=a*b) n=a*b-1;
		for(i=m;i<=n;i++) if(all[i]==0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}