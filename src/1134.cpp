#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
	int N,i,j,k,l;
	cin>>N;
	getchar();
	for(i=0;i<N;i++)
	{
		int M;
		cin>>M;
		getchar();
		vector<int> d1(M);
		vector<int> d2(M);
		for(j=0;j<M;j++)
		{
			char a,b,c;
			cin>>a>>b;
			int front,back;
			if('2'<=a&&a<='9') front=a-'0'-2;
			else if(a=='T') front=8;
			else if(a=='J') front=9;
			else if(a=='Q') front=10;
			else if(a=='K') front=11;
			else if(a=='A') front=12;
			if(b=='C') back=0;
			if(b=='D') back=1;
			if(b=='S') back=2;
			if(b=='H') back=3;
			d1[j]=front*4+back;
			getchar();
		}

		for(j=0;j<M;j++)
		{
			char a,b,c;
			cin>>a>>b;
			int front,back;
			if('2'<=a&&a<='9') front=a-'0'-2;
			else if(a=='T') front=8;
			else if(a=='J') front=9;
			else if(a=='Q') front=10;
			else if(a=='K') front=11;
			else if(a=='A') front=12;
			if(b=='C') back=0;
			if(b=='D') back=1;
			if(b=='S') back=2;
			if(b=='H') back=3;
			d2[j]=front*4+back;
			getchar();
		}
		sort(d1.begin(),d1.end());
		sort(d2.begin(),d2.end());
		int count=0;
		int pointer;
		int d1_len=d1.size(),d2_len=d2.size();
		for(j=0;j<d1_len;j++)
		{
			for(k=0;k<d2_len;k++)
			{
				if(d2[k]!=-1)
				{
					if(d2[k]>d1[j])
					{
						d2[k]=-1;
						count++;
						break;
					}
				}
			}
			if(k==d2_len)
			{
				for(l=0;l<d2_len;l++)
				{
					if(d2[l]!=-1)
					{
						d2[l]=-1;
						break;
					}
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}