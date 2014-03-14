#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int N,M;
	while(scanf("%d%d",&N,&M)==2)
	{
		getchar();
		int _n,_m,sum=0;
		vector<int> count(M,0);

		for(_n=0;_n!=N;++_n)
		{
			for(_m=0;_m!=M;++_m)
			{
				char c;
				c=getchar();

				if('w'==c)
				{
					++count.at(_m);
				}
				else
				{
					count.at(_m)=0;
				}

				sum+=count.at(_m);

				int __m=_m,min=count.at(_m);
				while(__m!=0)
				{
					--__m;
					min=min<count.at(__m)?min:count.at(__m);
					sum+=min;
				}
			}
			getchar();
		}
		printf("%d\n",sum);
	}
	return 0;
}