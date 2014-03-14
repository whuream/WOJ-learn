#include<iostream>
#include<vector>

using namespace std;

vector<bool> data(1000001,-1);

void find(int num)
{
	if(data[num]!=-1) return;
	else
	{
		find(num-2);
		find(num-3);
		find(num-5);
		data[num]=!(data[num-2]&&data[num-3]&&data[num-5]);
	}
}

int main()
{
	int i;
	data[0]=0;
	data[1]=0;
	data[2]=1;
	data[3]=1;
	data[4]=1;
	for(i=5;i<1000001;i++)
	{
		data[i]=!(data[i-2]&&data[i-3]&&data[i-5]);
	}
	int N;
	cin>>N;
	for(i=0;i<N;i++)
	{
		int num;
		cin>>num;
		//if(data[num]==-1) find(num);
		cout<<data[num]<<endl;
	}
	return 0;
}