#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char c[105];
	int i;
	while(1)
	{
		gets(c);
		fflush(stdin);
		if(c[0]=='$') break;
		for(i=0;;i++)
		{
			if(c[i]=='\0') break;
			c[i]=(c[i]-'A'-i-1+26*5)%26+'A';
		}
		puts(c);
	}
	return 0;
}