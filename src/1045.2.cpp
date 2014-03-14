#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	int N,i,j;
	char c[10010];

	scanf("%d",&N);
	getchar();

	for(i=0;i<N;i++)
	{
		char pre=' ';
		int lc=strlen(c),flag=0;

		gets(c);

		for(j=0;j<lc;j++)
		{
			if(pre==' ')
			{
				if(flag==0)
					c[j]=toupper(c[j]);
			}
			else
			{
				c[j]=tolower(c[j]);
				flag=1;
			}
			pre=c[j];
		}
		puts(c);
	}
	return 0;
}