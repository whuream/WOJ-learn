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

typedef struct _node
{
	int a,b;
}node;

bool c(node a,node b)
{
	return a.a<b.a;
}

int main()
{
	int N;
	while(1)
	{
		scanf("%d",&N);
		if(N==0) break;

		vector<node> data(N);
		int i;
		for(i=0;i<N;i++) scanf("%d",&data[i].a);
		for(i=0;i<N;i++) scanf("%d",&data[i].b);
		sort(data.begin(),data.end(),c);
		int sum=0;
		int tmp=MIMAX;
		for(i=0;i<N;i++)
		{
			if(data[i].b<tmp)
			{
				sum++;
				tmp=data[i].b;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}