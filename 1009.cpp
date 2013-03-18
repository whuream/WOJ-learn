#include<iostream>
#include<vector>
#include<list>

#include<stdio.h>

#define INF 9999999

using namespace std;

typedef struct tag
{
	int cost;
	int pguard;
	int sguard;
	char letter;
}rode;

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		vector< vector<rode> > data(n,vector<rode>(n));

		int i,j,min,u;

		//初始化
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(j!=i) data[i][j].cost=-1;
				else data[i][j].cost=0;
			}

		//数据输入
		for(i=0;i<m;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			scanf("%d %d %d %c",&data[a][b].pguard, &data[a][b].sguard, &data[a][b].cost,
				&data[a][b].letter);
			data[b][a].pguard=data[a][b].pguard;
			data[b][a].sguard=data[a][b].sguard;
			data[b][a].cost=data[a][b].cost;
			data[b][a].letter=data[a][b].letter;
		}
		int plovers,slovers;
		scanf("%d %d",&plovers,&slovers);
		 
		//数据处理
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if((data[i][j].pguard >= plovers)||(data[i][j].sguard >=slovers))
					data[i][j].cost=-1;

		vector<int> s(n,0);

		vector<int> path(n);

		vector<int> dist(n);

		int mindis,v=0;

		for(i=0;i<n;i++)
		{
			dist[i]=data[v][i].cost;
			if(data[v][i].cost!=-1)
				path[i]=v;
			else
				path[i]=-1;
		}

		s[v]=1;path[v]=0;

		for(i=0;i<n;i++)
		{
			mindis=INF;
			for(j=0;j<n;j++)
				if(s[j]==0&&dist[j]!=-1&&dist[j]<mindis)
				{
					u=j;
					mindis=dist[j];
				}
			s[u]=1;
			for(j=0;j<n;j++)
				if(s[j]==0)
					if(data[u][j].cost!=-1&&(dist[u]+data[u][j].cost<dist[j]||dist[j]==-1))
					{
						dist[j]=dist[u]+data[u][j].cost;
						path[j]=u;
					}
		}

		int point=n-1;

		vector<char> str;
		while(1)
		{
			str.push_back(data[path[point]][point].letter);
			//printf("%c",data[path[point]][point].letter);

			point=path[point];

			if(path[point]==v)
			{
				printf("%c",data[path[point]][point].letter);
				break;
			}
		}
		for(i=str.size()-1;i>=0;i--) printf("%c",str[i]);
		printf("\n");
	}
	return 0;
}