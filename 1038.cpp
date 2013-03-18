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

template<class T> T mmax(T a,T b){return a>b?a:b;}
template<class T> T mmin(T a,T b){return a<b?a:b;}
template<class T> T mabs(T a){return a>0?a:-a;}

#define MIMAX 0x7fffffff
#define MIMIN 0xffffffff

typedef struct _point
{
	int x,y,id,is;
	double dis;
}point;

double getdis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		int L;
		scanf("%d",&L);

		vector<point> data(n);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&data[i].x,&data[i].y);
		}

		data[0].is=1;
		int pre=0;
		for(i=1;i<n;i++)
		{
			data[i].dis=getdis(data[i],data[0]);
		}
		double ans=0;
		for(i=1;i<n;i++)
		{
			double tmpmin=MIMAX;
			int itmp;
			int j;
			for(j=1;j<n;j++)
			{
				if(data[j].is==0)
				{
					double dtmp;
					dtmp=getdis(data[j],data[pre]);
					if(dtmp<data[j].dis)
					{
						data[j].id=pre;
						data[j].dis=dtmp;
					}
					//tmpmin=mmin(tmpmin,data[j].dis);
					if(data[j].dis<tmpmin)
					{
						itmp=j;
						tmpmin=data[j].dis;
					}
				}
			}
			ans+=tmpmin;
			data[itmp].is=1;
			pre=itmp;
		}
		if(ans<=L) printf("Success!\n");
		else printf("Poor magicpig!\n");
	}
	return 0;
}