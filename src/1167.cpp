#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef vector<vector<char> > mchar;
typedef vector<vector<int> > mint;

void change(mint &table,int a,int tob,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(table[i][j]==a) table[i][j]=tob;
		}
	}
}

int main()
{
	int r,c;
	while(1)
	{
		scanf("%d %d",&r,&c);
		getchar();
		if(r==0 && c==0) break;

		mchar data(r,vector<char>(c));

		mint table(r,vector<int>(c));
		
		int ans=0;
		int id=0;
		int i,j;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%c",&data[i][j]);
				if(data[i][j]=='O' && j-1>=0 && data[i][j-1]=='O') table[i][j]=table[i][j-1];
				if(data[i][j]=='O' && i-1>=0 && data[i-1][j]=='O') table[i][j]=table[i-1][j];

				if(data[i][j]=='O' && i-1>=0 && j-1>=0 && data[i-1][j-1]=='O') table[i][j]=table[i-1][j-1];

				if(data[i][j]=='O' && i-1>=0 && j+1<c && data[i-1][j+1]=='O' && table[i-1][j+1]!=table[i][j])
				{
					if(table[i][j]!=0)
					{
						change(table,table[i-1][j+1],table[i][j],r,c);
						ans--;
					}
					else
					{
						table[i][j]=table[i-1][j+1];
					}
				}
				if(data[i][j]=='O' && !(j-1>=0 && data[i][j-1]=='O') && !(i-1>=0 && data[i-1][j]=='O')
					&& !(i-1>=0 && j-1>=0 && data[i-1][j-1]=='O') 
					&& !(i-1>=0 && j+1<c && data[i-1][j+1]=='O'))
				{
					id++;
					table[i][j]=id;
					ans++;
				}
			}
			getchar();
		}

		printf("%d\n",ans);
	}
	return 0;
}