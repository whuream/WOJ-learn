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
	int n;
	int m;
	int max=0;
	for(m=1;m<=1000;m++)
	{
		n=m;
		//scanf("%d",&n);
		string data;
		while(n)
		{
			data.push_back(n%2);
			n/=2;
		}
		int add=0;
		add+=data.length()-1;
		int i;
		int tmp=0;
		for(i=0;i<data.length();i++)
		{
			if(data[i]==1) tmp++;
			else
			{
				if(tmp>=2)
				{
					data[i]=1;
					add++;
					i--;
				}
				else add+=tmp;
				tmp=0;
			}
		}
		if(tmp>=3)
		{
			add+=3;
		}
		else add+=tmp;
		add--;
		if(add>max) max=add;
	}
	printf("%d\n",max);
	return 0;
}