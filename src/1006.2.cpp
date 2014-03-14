#include<iostream>
#include<vector>
#include<deque>

#include<stdio.h>

using namespace std;

int main()
{
	int n,m,i;
	//cin>>n>>m;
	scanf("%d%d",&n,&m);

	vector< vector <int> > biao(n);

	for(i=0;i<m;i++)
	{
		int ani_a,ani_b;
		//cin>>ani_a,ani_b;
		scanf("%d%d",&ani_a,&ani_b);
		biao[ani_a].push_back(ani_b);
		biao[ani_b].push_back(ani_a);
	}

	int num;
	cin>>num;

	for(i=0;i<num;i++)
	{
		int a,b;
		//cin>>a>>b;
		scanf("%d%d",&a,&b);

		deque<int> duilie;

		vector<int> visited(n,-2);

		visited[a]=-1;

		duilie.push_back(a);

		while(1!=duilie.empty())
		{
			int p=duilie.front();
			duilie.pop_front();

			if(p!=b)
			{
				int size=biao[p].size();
				int i;
				for(i=0;i<size;i++)
				{
					if(visited[biao[p][i]]==-2)
					{
						duilie.push_back(biao[p][i]);
						visited[biao[p][i]]=p;
					}
				}
			}
			else break;
		}

		int p=b,count=0;
		if(visited[p]==-2) printf("-1\n");
		else if(a==b) printf("0\n");
		else
		{
			while(1)
			{
				if(visited[p]==-1) break;
				else
				{
					p=visited[p];
					count++;
				}
			}
			printf("%d\n",count-1);
		}
		
	}

	return 0;
}