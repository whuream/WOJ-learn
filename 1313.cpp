#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> Nmin(1000,0);

	while(1)
	{
		long long int num,i;

		cin>>num;
		if(num==0) break;

		for(i=0;i<1000;i++) Nmin[i]=0;

		int m=num;

		for(i=1;;i++)
		{
			if(num>=1000) 
			{
				num%=1000;
				Nmin[num]=i;
				break;
			}
			else num*=m;
		}
		i++;
		for(;;i++)
		{
			num*=m;
			num%=1000;
			if(Nmin[num]!=0)
			{
				cout<<Nmin[num]+i<<endl;
				break;
			}
			else Nmin[num]=i;
		}
	}
	return 0;
}