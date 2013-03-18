#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,m,i,j,k;
	while(1)
	{
		cin>>n>>m;
		if(0==n) break;
		vector<int> data(n);
		for(i=0;i<n;i++)
		{
			int a;
			cin>>a;
			data[i]=a;
		}
		sort(data.begin(),data.end());
		for(i=0;i<n;i+=m)
		{
			cout<<data[i];
			if(i<n-m) cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}