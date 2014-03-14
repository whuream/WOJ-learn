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
	double x1,y1,z1,x2,y2,z2,x3,y3,z3;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3)==9)
	{
		double a,b,c;
		a=sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
		b=sqrt(pow(x1-x3,2)+pow(y1-y3,2)+pow(z1-z3,2));
		c=sqrt(pow(x2-x3,2)+pow(y2-y3,2)+pow(z2-z3,2));

		double in;
		double x=(a+b-c)/2;
		double C=(a*a+b*b-c*c)/(2*a*b);
		C=acos(C);
		C/=2;
		in=tan(C)*x;

		double out;
		if(c<a)
		{
			double dt=c;
			c=a;
			a=dt;
		}
		if(c<b)
		{
			double dt=c;
			c=b;
			b=dt;
		}
		C=(a*a+b*b-c*c)/(2*a*b);

		out=c/2/sqrt(1-C*C);
		double ans=in*in/out/out;
		printf("%.3lf\n",ans);
	}
	return 0;
}