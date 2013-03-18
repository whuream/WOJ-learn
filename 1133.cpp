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
	int a,b,c;
	int id;
}node;

bool ca(node a,node b){return a.a<b.a;}
bool cb(node a,node b){return a.b<b.b;}
bool cc(node a,node b){return a.c<b.c;}

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		ull sum=0;
		vector<node> data(n);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&data[i].a,&data[i].b,&data[i].c);
			data[i].id=i;
			sum+=data[i].a+data[i].b+data[i].c;
		}
		vector<node> data2(n);
		data2=data;
		vector<int> p;

		sort(data2.begin(),data2.end(),ca);
		int mmm=data2.size()-3;
		for(i=data2.size()-1;i>=mmm;i--)
		{
			p.push_back(data2[i].id);
		}

		sort(data2.begin(),data2.end(),cb);
		for(i=data2.size()-1;i>=mmm;i--) p.push_back(data2[i].id);

		sort(data2.begin(),data2.end(),cc);
		for(i=data2.size()-1;i>=mmm;i--) p.push_back(data2[i].id);

		sort(p.begin(),p.end());
		vector<int>::iterator it=unique(p.begin(),p.end());
		p.erase(it,p.end());

		data2.clear();
		for(i=0;i<p.size();i++) data2.push_back(data[p[i]]);

		int ss=0;
		int j,k;
		for(i=0;i<data2.size();i++)
		{
			for(j=0;j<data2.size();j++)
			{
				if(j!=i)
				{
					for(k=0;k<data2.size();k++)
					{
						if(k!=j && k!=i)
						{
							int tmp=data[i].a+data[j].b+data[k].c;
							if(tmp>ss) ss=tmp;
						}
					}
				}
			}
		}
		sum-=ss;
		printf("%llu\n",sum);
	}
	return 0;
}