#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int exist(char **c,int N)
{
	int i,j,k;
	for(i=0;i<N;i++)
	{
		int len=strlen(c[i]);
		for(j=0;j<N;j++)
		{
			int lenj=strlen(c[j]);
			if(len>=lenj) continue;
			for(k=0;k<len;k++)
			{
				if(c[i][k]!=c[j][k]) break;
			}
			if(k==len) return 1;
		}
	}
	return 0;
}


int main()
{
	int N;
	while(1)
	{
		scanf("%d",&N);
		getchar();

		if(N==0) break;
		int i;
		char **c;

		c=(char **)malloc(sizeof(char *)*N);
		for(i=0;i<N;i++) c[i]=(char *)malloc(sizeof(char)*11);
		for(i=0;i<N;i++) gets(c[i]);
		
		if(exist(c,N)) printf("Exist!\n");
		else printf("None!\n");
		
		getchar();
	}
	return 0;
}