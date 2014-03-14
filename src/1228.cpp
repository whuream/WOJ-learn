#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int F,K;
	while(scanf("%d %d",&F,&K)==2)
	{
		vector<int> data(F);
		int i;
		int ans=0;
		for(i=0;i<K;i++)
		{
			int L,I;
			scanf("%d %d",&L,&I);
			L--;
			while(L<F)
			{
				if(data[L]==0)
				{
					data[L]=1;
					ans++;
				}
				L+=I;
			}
		}
		ans=F-ans;
		printf("%d\n",ans);
	}
	return 0;
}