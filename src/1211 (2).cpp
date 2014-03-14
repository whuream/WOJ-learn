#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

template<class T> T mmax(T a,T b){return a>b?a:b;}
template<class T> T mmin(T a,T b){return a<b?a:b;}
template<class T> T mabs(T a){return a>0?a:-a;}

#define MIMAX 0x7fffffff
#define MIMIN 0xffffffff

bool isnumber(char c)
{
	if(c>='0' && c<='9') return true;
	return false;
}

bool isop(int c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/') return true;
	return false;
}

int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	int i;
	for(i=0;i<T;i++)
	{
		string data;
		getline(cin,data);

		map<char,int> mmap;
		mmap['+']=2;
		mmap['-']=2;
		mmap['*']=4;
		mmap['/']=4;
		mmap['(']=0;
		mmap[')']=1;

		stack<char> op;
		vector<int> num;
		vector<int> num_2;
		int j;
		int itmp=0;
		char cpre='#';
		for(j=0;j<data.length();j++)
		{
			if(data[j]==' ') continue;
			if(isnumber(data[j]))
			{
				itmp=itmp*10+data[j]-'0';
			}
			else
			{
				if(isnumber(cpre))
				{
					num.push_back(itmp);
					num_2.push_back(0);
					itmp=0;
				}

				if(data[j]=='(') op.push(data[j]);
				else if(data[j]==')')
				{
					while(op.top()!='(')
					{
						num.push_back(op.top());
						num_2.push_back(1);
						op.pop();
					}
					op.pop();
				}
				else
				{
					while(!op.empty() && mmap[op.top()]>=mmap[data[j]])
					{
						num.push_back(op.top());
						num_2.push_back(1);
						op.pop();
					}
					op.push(data[j]);
				}
			}
			cpre=data[j];
		}
		if(isnumber(cpre))
		{
			num.push_back(itmp);
			num_2.push_back(0);
		}
		while(!op.empty())
		{
			num.push_back(op.top());
			num_2.push_back(1);
			op.pop();
		}


		vector<int> tmp;
		
		for(j=0;j<num.size();j++)
		{
			if(num_2[j]==1)
			{
				if(num[j]=='+') tmp[tmp.size()-2]+=tmp[tmp.size()-1];
				if(num[j]=='-') tmp[tmp.size()-2]-=tmp[tmp.size()-1];
				if(num[j]=='*') tmp[tmp.size()-2]*=tmp[tmp.size()-1];
				if(num[j]=='/') tmp[tmp.size()-2]/=tmp[tmp.size()-1];
				tmp.pop_back();
			}
			else
			{
				tmp.push_back(num[j]);
			}
		}
		printf("%d\n",tmp[0]);

	}
	return 0;
}