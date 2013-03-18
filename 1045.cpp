#include<stdio.h>
#include<ctype.h>

int main()
{
	int t,i,j,flag;
	char pre;
	char c[10005];
	scanf("%d",&t);
	fflush(stdin);
	for(i=0;i<t;i++)
	{
		gets(c);
		fflush(stdin);
		pre='F';
		flag=0;
		for(j=0;;j++)
		{
			if(c[j]=='\0') break;
			if(j==0) c[j]=toupper(c[j]);
			else
			{
				if(pre!=' '&&flag==1)
				{
					c[j]=tolower(c[j]);
				}
				pre=c[j];
				if(c[j]==' ') flag=1;
			}
		}
		puts(c);
	}
	return 0;
}