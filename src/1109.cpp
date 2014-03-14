#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	
	while(1)
{
	int i,j,k,l;
	vector<string> dictionary;
	string tmp;

	while(1)
	{
		cin>>tmp;
		if(tmp=="#") break;
		else dictionary.push_back(tmp);
	}
	int len=dictionary.size();
	if(0==len) break;

	while(1)
	{
		cin>>tmp;
		if(tmp=="#") break;
		else
		{
			cout<<tmp;
			for(i=0;i<len;i++)
			{
				if(tmp==dictionary[i])
				{
					cout<<" is correct ";
					break;
				}
			}
			if(i==len)
			{
				cout<<": ";
			for(i=0;i<len;i++)
			{
				if(tmp.length()==dictionary[i].length())
				{
					int dif=-1,tmp_len=tmp.length();
					for(j=0;j<tmp_len;j++)
					{
						if(tmp[j]!=dictionary[i][j])
						{
							if(dif!=-1) break;
							else dif=j;
						}
					}
					if(j==tmp_len) cout<<dictionary[i]<<" ";
				}

				else if(tmp.length()==dictionary[i].length()-1)
				{
					int dif=-1,tmp_len=tmp.length();
					for(j=0,k=0;j<tmp_len;j++,k++)
					{
						if(tmp[j]!=dictionary[i][k])
						{
							if(dif!=-1) break;
							else
							{
								dif=j;
								j--;
							}
						}
					}
					if(j==tmp_len) cout<<dictionary[i]<<" ";
				}

				else if(tmp.length()-1==dictionary[i].length())
				{
					int dif=-1,tmp_len=dictionary[i].length();
					for(j=0,k=0;k<tmp_len;j++,k++)
					{
						if(tmp[j]!=dictionary[i][k])
						{
							if(dif!=-1) break;
							else
							{
								dif=j;
								k--;
							}
						}
					}
					if(k==tmp_len) cout<<dictionary[i]<<" ";
				}
			}
			}
		}
		cout<<'\b'<<endl;
	}
}
	return 0;
}