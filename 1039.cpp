#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int N;
	while(1)
	{
		vector<int> ans(100010);
		vector<int> table(100010);
		scanf("%d",&N);
		if(N==0) break;

		int count=-1;
		int i;
		for(i=0;i<table.size();i++) table[i]=i;

		for(i=0;i<N;i++)
		{
			int key;
			scanf("%d",&key);
			key--;

			while(ans[key]!=0) key++;
			if(count<key) count=key;
			ans[key]=i+1;


		}
		printf("%d\n",count+1);

		for(i=0;i<count+1;i++)
		{
			printf("%d",ans[i]);
			if(i!=count) printf(" ");
			else printf("\n");
		}

	}
	return 0;
}