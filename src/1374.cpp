#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<string> > mstring;

string add_2(string &a,string &b)
{
	string ans;
	int i;
	for(i=0;i<b.length();i++)
	{
		ans.push_back(a[a.length()-1-i]+b[b.length()-1-i]-'0');
	}
	for(i=a.length()-b.length()-1;i>=0;i--) ans.push_back(a[i]);

	int pre=0;
	for(i=0;i<ans.length();i++)
	{
		ans[i]+=pre;
		if(ans[i]>'9')
		{
			pre=1;
			ans[i]-=10;
		}
		else pre=0;
	}
	if(pre==1) ans.push_back('1');
	string ans2;
	for(i=ans.length()-1;i>=0;i--) ans2.push_back(ans[i]);
	return ans2;
}

string add(string &a,string &b)
{
	if(a.length()>b.length()) return add_2(a,b);
	else return add_2(b,a);
}

int main()
{
	int m,d;
	while(scanf("%d %d",&m,&d)==2)
	{
		mstring all(d+1,vector<string>(m+1));
		
		if(m==0 && d==0) break;
		int i,j;
		for(i=0;i<=m;i++) all[1][i]="0";
		all[1][m]="1";
		all[1][0]="1";
		for(i=2;i<=d;i++)
		{
			for(j=1;j<=m-1;j++)
			{
				all[i][j]=all[i-1][j-1];
			}
			all[i][m]=add(all[i-1][m],all[i-1][m-1]);
			all[i][0]=all[i][m];
		}
		string ans="0";
		for(i=0;i<=m;i++) ans=add(ans,all[d][i]);
		cout<<ans<<endl;
	}
	return 0;
}