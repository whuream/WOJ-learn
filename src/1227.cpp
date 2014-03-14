#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

int max(int a,int b){return a>b?a:b;}
int i,j,k;

void getans(mint &data,int &n,int x,int y,int sum,int &ans)
{
	if(x==0 && y==n-1)
	{
		ans=max(ans,sum+data[x][y]);
		return;
	}
	if(x-1>=0) getans(data,n,x-1,y,sum+data[x][y],ans);
	if(y+1<n) getans(data,n,x,y+1,sum+data[x][y],ans);
}

int main()
{
	vector<int> yin(300);
	yin['A']=1;	
	for(i=2;i<=9;i++) yin['0'+i]=i;
	yin['T']=10;
	yin['J']=11;
	yin['Q']=12;
	yin['K']=13;

	int N;

	while(scanf("%d",&N)==1){
	getchar();
	mint data(N,vector<int>(N));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			char ctmp;
			scanf("%c%*c%*c",&ctmp);
			data[i][j]=yin[ctmp];
		}
	}
	int ans=0;
	getans(data,N,N-1,0,0,ans);
	printf("%d\n",ans);

	}

	return 0;
}