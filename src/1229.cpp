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
	int N,L;
	while(scanf("%d %d",&N,&L)==2)
	{
		string ans;
		if(L!=0)
		{
			while(N)
			{
				ans.push_back(N%9);
				N/=9;
			}
			int i;
			for(i=ans.length()-1;i>=0;i--)
			{
				if(ans[i]>=L && ans[i]!=0) printf("%d",ans[i]+1);
				else printf("%d",ans[i]);
			}
			printf("\n");
		}
		else
		{
			if(N==1) printf("1\n");
			else
			{
				N--;
				while(N)
				{
					ans.push_back(N%9+1);
					N/=9;
				}
				if(ans.length()!=1)
				ans[ans.length()-1]--;
				int i;
				for(i=ans.length()-1;i>=0;i--)
				{
					printf("%d",ans[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}