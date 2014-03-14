#include<iostream>
#include<string>
#include<vector>

using namespace std;

string count(int num);

vector<string> data(501);

string _add(string a,string b)
{
	//串_a长度大
	string *_a=&a,*_b=&b;
	if(a.length()<b.length())
	{
		_a=&b;
		_b=&a;
	}

	int pre=0,pointer_a=(*_a).length()-1,pointer_b=(*_b).length()-1,i,jk;
	string ans;
	
	for(;pointer_b>=0;pointer_b--,pointer_a--)
	{
		char tmp=a[pointer_a]+b[pointer_b]-'0'+pre;
		if(tmp>'9')
		{
			tmp-=10;
			pre=1;
		}
		else pre=0;
		ans.push_back(tmp);
	}
	for(;pointer_a>=0;pointer_a--)
	{
		char tmp=a[pointer_a]+pre;
		if(tmp>'9')
		{
			tmp-=10;
			pre=1;
		}
		else pre=0;
		ans.push_back(tmp);
	}
	if(pre==1) ans.push_back('1');
	string _ans;
	for(i=ans.length()-1;i>=0;i--) _ans.push_back(ans[i]);
	return _ans;
}

string add(int a,int b,int c)
{
	if(data[a].empty()) count(a);
	if(data[b].empty()) count(b);
	if(data[c].empty()) count(c);
	return _add(_add(data[a],data[b]),data[c]);
}

string count(int num)
{
	if(!data[num].empty()) return data[num];
	else return add(num-1,num-2,num-3);
}

int main()
{
	data[1]="1";
	data[2]="2";
	data[3]="4";
	for(int i=4;i<=500;i++) data[i]=count(i);
	while(1)
	{
		int num;
		cin>>num;
		if(num==0) break;
		if(data[num].empty())
			data[num]=count(num);
		cout<<data[num]<<endl;
	}
	return 0;
}