#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

template<class T> T mmax(T a,T b){return a>b?a:b;}
template<class T> T mmin(T a,T b){return a<b?a:b;}
template<class T> T mabs(T a){return a>0?a:-a;}

#define MIMAX 0x7fffffff
#define MIMIN 0xffffffff

int main()
{
	
	while(1)
	{
		string data;
		char c;
		c=getchar();
		bool fi=false;
		while(c!='\n')
		{
			if(c=='0')
			{
				if(fi==true)
					data.push_back(c);
			}
			else
			{
				fi=true;
				data.push_back(c);
			}
			c=getchar();
		}
		if(data=="") break;
		if(data.length()>10) printf("NO\n");
		else
		{
			bool ans=false;
			sort(data.begin(),data.end());
			string::iterator it=unique(data.begin(),data.end());
			if(it==data.end())
			{
				int b=data[0];
				int i;
				for(i=1;i<data.length();i++)
				{
					if(b=='9') b='0';
					else b++;
					if(data[i]!=b) break;
				}
				if(i==data.length()) ans=true;
				
				int j;
				b=data[0];
				for(j=data.length()-1;j>=i;j--)
				{
					if(b=='0') b='9';
					else b--;
					if(data[j]!=b) break;
				}
				if(j==i-1) ans=true;
			}
			if(ans) printf("YES\n");
			else printf("NO\n");
		}
		
	}
	return 0;
}