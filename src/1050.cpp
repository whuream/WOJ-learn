#include<iostream>
#include<vector>

#define INF 999999;

using namespace std;

int main()
{
	int t,i,j,k;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int N,allcost=0;
		cin>>N;
		vector< vector<int> > table(N,vector<int>(N));
		for(j=0;j<N;j++)
			for(k=0;k<N;k++)
			{
				int tmp;
				cin>>tmp;
				table[j][k]=tmp;
			}

		vector<int> lowcost(N),closest(N);
		int min,i1,v=0;
		for(i1=0;i1<N;i1++)
		{
			lowcost[i1]=table[v][i1];
			closest[i1]=v;
		}
		for(i1=1;i1<N;i1++)
		{
			min=INF;
			for(j=0;j<N;j++)
				if(lowcost[j]!=0&&lowcost[j]<min)
				{
					min = lowcost[j];
					k = j;
				}
			allcost+=min;
			lowcost[k]=0;
			for(j=0;j<N;j++)
				if(table[k][j]!=0&&table[k][j]<lowcost[j])
				{
					lowcost[j]=table[k][j];
					closest[j]=k;
				}
		}
		cout<<allcost<<endl;
	}
	return 0;
}