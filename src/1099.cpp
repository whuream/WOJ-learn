#include<iostream>

using namespace std;

long long int N,M;

long long int get(long long int n)
{

	long long int tmp=2,ans;
	if(n%2==0) ans=1;
	else ans=2;
	n/=2;
	while(n!=0)
	{
		tmp=tmp*tmp%M;
		if(n%2==1) ans=ans*tmp%M;
		n/=2;
	}
	return ans;
}

int main()
{
	while(cin>>N>>M)
	{
		cout<<get(N)-1<<endl;
	}
	return 0;
}