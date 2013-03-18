#include<iostream>

using namespace std;

int main()
{
	int N,i;
	cin>>N;
	for(i=0;i<N;i++)
	{
		long long int a,b;
		cin>>a>>b;
		cout<<"Case #"<<i+1<<": "<<(a+b)*(b-a+1)/2<<endl;
	}
	return 0;
}