#include<vector>

using namespace std;

#include<stdio.h>

int main()
{
	int test_case;
	scanf("%d",&test_case);
	for(int _test_case=0;_test_case<test_case;++_test_case)
	{
		int num_count,min;
		vector<int> data;

		scanf("%d%d",&num_count,&min);
		for(int _num_count=0;_num_count<num_count;++_num_count)
		{
			int tmp;
			scanf("%d",&tmp);
			data.push_back(tmp);
		}
		vector<int>::iterator it_now=data.begin(),it_end;
		int sum=0;
		int min_len=0x7fffffff;
		int tmp_len=0;

		while(it_now!=data.end())
		{
			sum+=*it_now;

			if(sum>=min)
			{
				it_end=it_now;
				sum=0;
				while(sum<min)
				{
					sum+=*it_now;
					tmp_len++;
					--it_now;
				}
				min_len=min_len<tmp_len?min_len:tmp_len;
				//it_now=it_end;
				it_now+=2;
				sum=0;
				tmp_len=0;
			}

			else
			{
				++it_now;
			}
		}
		if(0x7fffffff==min_len)
		{
			min_len=0;
		}
		printf("%d\n",min_len);
	}
	return 0;
}