#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

int max(int a,int b){return a>b?a:b;}
int i,j,k;

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) return 0;
		if(n%2==0) printf("No Solution!\n");
		else printf("%d\n",n-1);
	}
	return 0;
}