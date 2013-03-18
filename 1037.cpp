#include<iostream>
#include<vector>

#include<stdio.h>

using namespace std;

int main()
{
	int N,i;
	while(1)
	{
		int call=0,dall=0;
		cin>>N;
		if(N==0) break;
		vector<int> c(N);
		vector<int> d(N);
		vector<int> e;
		for(i=0;i<N;i++)
		{
			int a;
			scanf("%d",&a);
			c[i]=a;
			call+=a;
		}
		for(i=0;i<N;i++)
		{
			int a;
			scanf("%d",&a);
			d[i]=a;
			dall+=a;
			if(e.empty()&&c[i]-d[i]!=0) e.push_back(c[i]-d[i]);
			else if(c[i-1]-d[i-1]>0&&e[e.size()-1]>0) e.back()+=c[i]-d[i];
			else if(c[i-1]-d[i-1]<0&&e[e.size()-1]<0) e.back()+=c[i]-d[i];
			else e.push_back(c[i]-d[i]);
		}

		if(call<dall) printf("NO\n");
		else{
		int starter;
		int len=e.size();
		for(starter=0;starter<len;starter++)
		{
			if(e[starter]<0) continue;
			int gas=0;
			for(i=0;i<len;i++)
			{
				gas+=e[(starter+i)%len];
				if(gas<0) break;
			}
			if(i==len) break;
		}
		if(starter==len) 
		{
		loop:		cout<<"NO\n";
		}
		else cout<<"YES\n";
		}
	}
	return 0;
}