#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	string data;
	while(cin>>data)
	{
		int count=0,i,j,k;
		vector<char> ans;
		int end=data.length();
		for(i=0;i<end;i++)
		{
			char pei=' ';
			switch(data[i])
			{
			case ')': pei='(';break;
			case '}': pei='{';break;
			case '>': pei='<';break;
			case ']': pei='[';break;
			}
			if(!ans.empty()&&ans.back()==pei)
				ans.pop_back();
			else
				ans.push_back(data[i]);
		}
			int len=ans.size();
			/*
			for(j=0;j<len&&ans.size()>=2;j++)
			{
				char c;
				switch(ans[j])
				{
				case ')': c='(';break;
				case '}': c='{';break;
				case '>': c='<';break;
				case ']': c='[';break;
				}
				for(k=j+1;k<ans.size();k++)
				{
					if(ans[k]==c)
					{
						vector<char>::iterator it=ans.begin()+k;
						ans.erase(it);
						count++;
						break;
					}
				}
				if(k<ans.capacity())
				{
					vector<char>::iterator it=ans.begin()+j;
					ans.erase(it);
					j--;
				}
			}
			*/
			count+=ans.size();	
		
		cout<<count<<endl;
	}
	return 0;
}