#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int M;
	cin>>M;
	for(int j=0;j<M;j++)
	{
		int N;
		cin>>N;
		string ans;
		if(N==0) cout<<"0\n";
		else{
		while(N!=0)
		{
			if(N%3==2)
			{
				N=N/3+1;
				ans.push_back('-');
			}
			else if(N%3==-2)
			{
				N=N/3-1;
				ans.push_back('1');
			}
			else if(N%3==-1)
			{
				N=N/3;
				ans.push_back('-');
			}
			else
			{
				ans.push_back(N%3+'0');
				N=N/3;
			}
		}
		int flag=0;
		for(int i=ans.length()-1;i>=0;i--)
		{
			if(flag==0&&ans[i]=='0');
			else 
			{
				cout<<ans[i];
				flag=1;
			}
		}
		cout<<endl;
		}
	}
	return 0;
}