#include<vector>
#include<cstdio>

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		vector<int> ans(1,2);
		int _n;
		for(_n=0;_n!=n;++_n)
		{
			vector<int>::iterator it=ans.begin();
			int pre=0;
			for(;it!=ans.end();++it)
			{
				*it=(*it)*2+pre;
				if(*it>=10)
				{
					*it-=10;
					pre=1;
				}
				else
				{
					pre=0;
				}
			}
			if(1==pre)
			{
				pre=0;
				ans.push_back(1);
			}
		}
		ans.at(0)-=1;
		vector<int>::reverse_iterator it=ans.rbegin();
		for(;it!=ans.rend();++it)
		{
			printf("%d",*it);
		}
		printf("\n");
	}
	return 0;
}