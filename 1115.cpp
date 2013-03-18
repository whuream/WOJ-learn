#include<stdio.h>

int main()
{
	long long int a,b;
	while(1)
	{
		char c1,c2;
		scanf("%c%lld%c%lld",&c1,&a,&c2,&b);
		getchar();
		if(a==0&&b==0) break;
		char c[100];
		int i=0;
		while(b!=0)
		{
			if(b%26==0)
			{
				c[i]='Z';
				b=b/26-1;
			}
			else
			{
				c[i]='A'+b%26-1;
				b=b/26;
			}
			i++;
		}
		for(int j=i-1;j>=0;j--) printf("%c",c[j]);
		printf("%lld\n",a);
	}
	return 0;
}