#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int max(int a,int b){return a>b?a:b;}

int mpow(int a,int b)
{
	int ans=1;
	int i;
	for(i=0;i<b;i++) ans*=a;
	return ans;
}

void c(vector<int> &data,int n)
{
	int all=0;
	int tmp=n;

	while(tmp!=0)
	{
		int weishu=log10(max(1,tmp));
		int mod=mpow(10,weishu);
		int head=tmp/mod;
		int tail=tmp%mod;

		int i;
		data[head]+=tail+1;
		for(i=head-1;i>=0;i--) data[i]+=mod;

		all+=head*weishu*mpow(10,weishu-1);

		int weishutail=log10(max(1,tail));
		data[0]+=max(0,weishu-weishutail-1)*(tail+1);

		tmp=tail;
	}

	int i;
	for(i=0;i<10;i++) data[i]+=all;

	for(i=1;i<=log10(max(1,n));i++) data[0]-=mpow(10,i);

	if(n%10==0) data[0]++;

}

int main()
{
	int a,b;
	while(1)
	{
		scanf("%d %d",&a,&b);
		if(a==0 && b==0) break;
		
		vector<int> da(10);
		vector<int> db(10);
		int mi;
		if(a>b)
		{
			c(da,a);
			c(db,b);
			mi=b;
		}
		else
		{
			c(da,b);
			c(db,a);
			mi=a;
		}

		int i;
		for(i=0;i<10;i++) da[i]-=db[i];

		while(mi!=0)
		{
			da[mi%10]++;
			mi/=10;
		}
		
		for(i=0;i<9;i++)
		{
			printf("%d ",da[i]);
		}
		printf("%d\n",da[i]);
	}
	return 0;
}