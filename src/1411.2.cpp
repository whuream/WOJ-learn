#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

bool check(const vector<string> &table,const int &a,const int &b)
{
	int i;
	char key=table[a][b];

	if(b+4<15)
	{
		for(i=1;i<5;i++)
		{
			if(table[a][b+i]!=key) break;
		}
		if(i==5) return true;
	}

	if(a+4<15)
	{
		for(i=1;i<5;i++)
		{
			if(table[a+i][b]!=key) break;
		}
		if(i==5) return true;
	}

	if(a+4<15 && b+4<15)
	{
		for(i=1;i<5;i++)
		{
			if(table[a+i][b+i]!=key) break;
		}
		if(i==5) return true;
	}

	if(a-4>=0 && b+4<15)
	{
		for(i=1;i<5;i++)
		{
			if(table[a-i][b+i]!=key) break;
		}
		if(i==5) return true;
	}

	return false;
}


char who_next(const vector<string> &table)
{
	int i,j;
	int b=0,w=0;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
		{
			if(table[i][j]=='W') w++;
			else if(table[i][j]=='B') b++;
		}
	return w<b?'W':'B';
}

bool checkall(const vector<string> &table,const char &key)
{
	int i,j;
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			if(table[i][j]!=key) continue;
			if(check(table,i,j)) return true;
		}
	}
	return false;
}


bool forall(vector<string> &table,const char &key)
{
	int i,j;
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			if(table[i][j]=='.')
			{
				table[i][j]=key;
				if(checkall(table,key)) return true;
				table[i][j]='.';
			}
		}
	}
	return false;
}

int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		int j;
		vector<string> table(15);
		bool isfind=false;
		for(j=0;j<15;j++)
		{
			cin>>table[j];
		}

		char key=who_next(table);

		if(forall(table,key)) cout<<"YES"<<endl;

		else cout<<"NO"<<endl;
	}
	return 0;
}