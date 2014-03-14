#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int N,M;
	while(scanf("%d%d",&N,&M)==2)
	{
		getchar();
		int _n,_m;
		long long sum=0;
		vector<int> count(M,0);
		
		for(_n=0;_n!=N;++_n)
		{
			vector<int> min(M,0);
			vector<long long> microsum(M,0);
			for(_m=0;_m!=M;++_m)
			{
				char c;
				int pre=0;
				c=getchar();

				if('w'==c)
				{
					++count.at(_m);
				}
				else
				{
					count.at(_m)=0;
				}
			}
			getchar();

			for(_m=0;_m!=M;++_m)
			{
				if(0==_m)
				{
					microsum.at(_m)+=count.at(_m);
					min.at(_m)=1;
				}
				else
				{
					if(count.at(_m)>=count.at(_m-1))
					{
						microsum.at(_m)+=count.at(_m)+microsum.at(_m-1);
						min.at(_m)=1;
					}
					else
					{
						min.at(_m)=min.at(_m-1)+1;
						int pre=_m-min.at(_m);

						while(pre>=0)
						{
							if(count.at(pre)<=count.at(_m))
							{
								min.at(_m)=_m-pre;
								microsum.at(_m)+=microsum.at(pre)+min.at(_m)*count.at(_m);
								break;
							}
							else
							{
								pre-=min.at(pre);
							}
						}
						if(pre<0)
						{
							min.at(_m)=_m+1;
							microsum.at(_m)+=min.at(_m)*count.at(_m);
						}
					}
				}
				sum+=microsum.at(_m);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}