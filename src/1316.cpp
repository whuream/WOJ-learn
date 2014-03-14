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

int mmax(int a,int b){return a>b?a:b;}
int mmin(int a,int b){return a<b?a:b;}
int mabs(int a){return a>0?a:-a;}

int main()
{
	int i;
	int a,b;
	while(1)
	{
		scanf("%d %d",&a,&b);
		if(a==0 && b==0) break;
		
		if(a==0) printf("0");
		string ans;
		while(a!=0)
		{
			
			if(a%b==0)
			{
				ans.push_back('0');
				a/=b;
			}
			else
			{
				int tmp;
				if(a<0)
				{
					tmp=a%b-b;
					a=a/b+1;
				}
				else
				{
					tmp=a%b;
					a=a/b;
				}
				if(tmp>=10) tmp=tmp-10+'A';
				else tmp=tmp+'0';
				ans.push_back(tmp);
				
			}
		}
		for(i=ans.length()-1;i>=0;i--) printf("%c",ans[i]);
			printf("\n");
	}
	return 0;
}