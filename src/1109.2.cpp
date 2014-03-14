#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool replace(const string it,const string tmp)
{
	int len=tmp.length();
	bool dif=false;

	for(int _i=0;_i!=len;++_i)
	{
		if((it[_i]!=tmp[_i])&&(false==dif)) dif=true;
		else if((it[_i]!=tmp[_i])&&(true==dif)) return false;
	}
	return true;
}

bool tmpless(const string it,const string tmp)
{
	int len=it.length();
	bool dif=false;

	for(int _i=0,_j=0;_i!=len;++_i,++_j)
	{
		if((it[_i]!=tmp[_j])&&(false==dif))
		{
			dif=true;
			--_j;
		}
		else if((it[_i]!=tmp[_j])&&(true==dif)) return false;
	}
	return true;
}

int main()
{
	while(1)
	{
		vector<string> dic;
		string tmp;
		while(cin>>tmp)
		{
			if("#"==tmp) break;
			dic.push_back(tmp);
		}

		if(dic.empty()) break;

		while(cin>>tmp)
		{
			if("#"==tmp) break;

			vector<string>::iterator it=dic.begin();
			for(;it!=dic.end();++it)
			{
				if(*it==tmp)
				{
					cout<<tmp<<" is correct"<<endl;
					break;
				}
			}

			if(it==dic.end())
			{
				cout<<tmp<<":";
				for(it=dic.begin();it!=dic.end();++it)
				{
					if(it->length()==tmp.length() && replace(*it,tmp) )
					{
						cout<<" "<<*it;
					}

					if(it->length()==tmp.length()+1 && tmpless(*it,tmp) )
					{
						cout<<" "<<*it;
					}
					if(it->length()==tmp.length()-1 && tmpless(tmp,*it) )
					{
						cout<<" "<<*it;
					}
				}
				cout<<endl;
			}
		}
	}
	return 0;
}