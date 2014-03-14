#include<iostream>
#include<cstdio>

using namespace std;

#define N 1000010

int all[N][4];

int main()
{
	
	int i=0;
	all[2][0]=1;
	all[2][1]=1;
	all[2][2]=1;
	all[2][3]=2;
	all[1][3]=1;

	for(i=3;i<N;i++)
	{
		all[i][0]=all[i-1][3];
		all[i][1]=(all[i-1][0]+all[i-1][2])%10000;
		all[i][2]=(all[i-1][0]+all[i-1][1])%10000;
		all[i][3]=(all[i-1][0]+all[i-1][1]+all[i-1][2]+all[i-1][3])%10000;
	}
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("%d\n",all[n][3]);
	}
	return 0;
}