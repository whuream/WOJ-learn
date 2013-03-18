#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

int max(int a,int b){return a>b?a:b;}
int i,j,k;

#define MMAX 1000000000

int main()
{
	int T;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		int N,S;
		scanf("%d %d",&N,&S);
		vector<int> data(N);
		for(j=0;j<N;j++) scanf("%d",&data[j]);

		int sum=0;
		int tmplen=0;
		int minlen=MMAX;
		for(j=0;j<N;j++)
		{
			tmplen++;
			sum+=data[j];
			while(sum>=S)
			{
				if(tmplen<minlen) minlen=tmplen;
				sum-=data[j-tmplen+1];
				tmplen--;
			}
		}
		if(minlen==MMAX) minlen=0;
		printf("%d\n",minlen);
	}
	return 0;
}