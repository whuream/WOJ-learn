#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

int max(int a,int b){return a>b?a:b;}
int mabs(int a){return a>=0?a:-a;}
int i,j,k;

void gui2(vector<int> &data,vector<int> &tmp,int a,int mid,int b,int &ans)
{
	i=a;
	j=mid+1;
	k=a;
	while(i<=mid && j<=b)
	{
		if(data[i]<=data[j])
		{
			tmp[k++]=data[i++];
			//ans+=mabs(i-k);
		}
		else
		{
			tmp[k++]=data[j++];
			ans+=mabs(j-k);
		}
	}
	
	while(i<=mid) tmp[k++]=data[i++];
	while(j<=b) tmp[k++]=data[j++];//这一行需要？
	for(i=a;i<=b;i++) data[i]=tmp[i];
}

void guibing(vector<int> &data,vector<int> &tmp,int a,int b,int &ans)
{
	if(a>=b) return ;
	int mid=(a+b)/2;
	guibing(data,tmp,a,mid,ans);
	guibing(data,tmp,mid+1,b,ans);
	gui2(data,tmp,a,mid,b,ans);
}


int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		vector<int> data(n);
		vector<int> tmp(n);
		for(i=0;i<n;i++) scanf("%d",&data[i]);
		int ans=0;
		guibing(data,tmp,0,n-1,ans);
		printf("%d\n",ans);
	}
	return 0;
}