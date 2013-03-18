#include<iostream>
#include<vector>

using namespace std;

vector<long long int> data(26,0);


int main()
{
	data[0]=1;
	data[1]=1;
	int i,j;
	for(i=2;i<=25;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			data[i]+=data[j]*data[i-1-j];
		}
	}
	int num;
	while(cin>>num)
	{
		if(num!=0)
			cout<<data[num/2]<<endl;
		else cout<<"0\n";
	}
	return 0;
}