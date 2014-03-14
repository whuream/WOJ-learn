#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

template<class T> T mmax(T a,T b){return a>b?a:b;}
template<class T> T mmin(T a,T b){return a<b?a:b;}
template<class T> T mabs(T a){return a>0?a:-a;}

#define MIMAX 0x7fffffff
#define MIMIN 0xffffffff
#define ZERO 1e-7

int main()
{
	int T;
	scanf("%d",&T);

	int i;
	for(i=0;i<T;i++)
	{
		int N,K;
		scanf("%d %d",&N,&K);
		
		vector<int> value(N+1);
		vector<int> wei(N+1);

		int j;
		for(j=1;j<=N;j++)
		{
			scanf("%d %d",&value[j],&wei[j]);
		}
		int W;
		scanf("%d",&W);
		mint data(K+1,vector<int>(W+1));

		int k;
		for(j=1;j<=K;j++)
		{
			for(k=0;k<=W;k++)
			{
				data[j][k]=MIMIN;
			}
		}

		int l;
		for(j=0;j<=N;j++)
		{
			for(k=K;k>=1;k--)
			{
				for(l=W;l>=wei[j];l--)
				{
					data[k][l]=mmax(data[k][l],data[k-1][l-wei[j]]+value[j]);
				}
			}
		}
		printf("%d\n",data[K][W]);
	}
	return 0;
}