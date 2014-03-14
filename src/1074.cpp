#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;

int main()
{
	int N,i,j,k,s,t;
	cin>>N;
	for(i=0;i<N;i++)
	{
		int ans=-1;
		int M;
		cin>>M;
		vector<int> data;
		for(j=0;j<M;j++)
		{
			int num;
			scanf("%d",&num);
			data.push_back(num);
		}
		sort(data.begin(),data.end());
		int point=M-1;
 		for(;point>=0&&ans==-1;point--)
		{
			s=0;
			t=point-1;
			while(s<t&&ans==-1)
			{
				if(data[s]+data[t]==data[point])
					ans=data[point];
				else if(data[s]+data[t]<data[point])
					s++;
				else
				{
					s=0;t--;
				}
			}
		}
		cout<<ans<<endl;
	}
}