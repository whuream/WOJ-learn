#include<stdio.h>

#include<vector>

using namespace std;

int main()
{
	int stock_number=0;
	while(scanf("%d",&stock_number)==1)
	{
		int tmp_longest=0;
		int longest=0;
		int pre_price=0xffffffff;

		for(int _stock_number=0;_stock_number<stock_number;++_stock_number)
		{
			int now_price;
			scanf("%d",&now_price);
			if(pre_price<now_price)
			{
				++tmp_longest;
			}
			else
			{
				longest=longest>tmp_longest?longest:tmp_longest;
				tmp_longest=1;
			}
			pre_price=now_price;
		}
		printf("%d\n",longest>tmp_longest?longest:tmp_longest);
	}
	return 0;
}