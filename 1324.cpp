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

typedef struct _point
{
	double x,y;
}point;

typedef struct _rec
{
	point ld,ru;
	double rad;
}rec;

int main()
{
	vector<rec> data;
	char op;
	while(1)
	{
		scanf("%c",&op);
		if(op=='*') break;
		if(op=='r')
		{
			rec tmp;
			scanf("%lf %lf %lf %lf",&tmp.ld.x,&tmp.ld.y,&tmp.ru.x,&tmp.ru.y);
			tmp.rad=-1;
			data.push_back(tmp);
			getchar();
		}
		else
		{
			rec tmp;
			scanf("%lf %lf %lf",&tmp.ld.x,&tmp.ld.y,&tmp.rad);
			data.push_back(tmp);
			getchar();
		}
	}

	point ptmp;
	int t=0;
	while(scanf("%lf %lf",&ptmp.x,&ptmp.y)==2)
	{
		if(abs(ptmp.x-9999.9)<=ZERO && abs(ptmp.y-9999.9)<=ZERO) break;
		t++;
		int i;
		bool is=false;
		for(i=0;i<data.size();i++)
		{
			if(data[i].rad<0)
			{
				if(ptmp.x<=data[i].ru.x && ptmp.x>=data[i].ld.x && ptmp.y<=data[i].ru.y && ptmp.y>=data[i].ld.y)
				{
					printf("Point %d is contained in figure %d\n",t,i+1);
					is=true;
				}
			}
			else
			{
				if(sqrt((ptmp.x-data[i].ld.x)*(ptmp.x-data[i].ld.x)+(ptmp.y-data[i].ld.y)*(ptmp.y-data[i].ld.y))<=data[i].rad)
				{
					printf("Point %d is contained in figure %d\n",t,i+1);
					is=true;
				}
			}
		}
		if(!is) printf("Point %d is not contained in any figure\n",t);
	}

	return 0;
}