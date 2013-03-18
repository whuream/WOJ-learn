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

void s(vector<int> &data,int &ans,int i)
{
	if(data.size()==16)
	{
		return;
	}
	if(data[data.size()-1]==i)
	{
		if(data.size()<ans) ans=data.size();
		data.pop_back();
		return;
	}
	int j,jj;
	for(jj=-1;jj<2;jj+=2)
	{
		for(j=0;j<data.size();j++)
		{
			int tmp=data.back()+data[j]*jj;
			if(tmp>0)
			{
				int k;
				for(k=0;k<data.size();k++) if(data[k]==tmp) break;
				if(k==data.size())
				{
					data.push_back(tmp);
					s(data,ans,i);
					if(!data.empty())
					data.pop_back();
				}
			}
		}
	}
}

int main()
{
	vector<int> all(1001);
	all[1]=0;
	int i;
	for(i=2;i<1001;i++)
	{
		all[i]=MIMAX;
		vector<int> data;
		data.push_back(1);
		s(data,all[i],i);
	}
	for(i=2;i<1001;i++) if(all[i]==0) break;
	if(i!=1001) printf("XXXXXXXXXXX");
	else printf("OOOOOOOOOOO");
	return 0;
}