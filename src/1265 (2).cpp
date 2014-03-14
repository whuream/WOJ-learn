#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	vector<int> all(500010);
	vector<int> data(5000010);
	all[0]=0;
	int i;
	for(i=1;i<500010;i++)
	{
		all[i]=all[i-1]-i;
		if(!(all[i]>0 && data[all[i]]==false)) all[i]=all[i-1]+i;
		data[all[i]]=true;
	}
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1) break;
		printf("%d\n",all[n]);
	}

	return 0;
}