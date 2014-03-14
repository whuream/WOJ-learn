#include<stdio.h>
#include<string.h>

void biao(int *UP,char *str)
{
	char up[26];
	int len=strlen(str);
	int i,j,loop=len;

	strcpy(up,str);

	for(i='Z';i>'A';i--)
	{
		for(j=0;j<len;j++)
		{
			if(i==up[j]) break;
		}
		if(j==len)
		{
			up[loop]=i;
			loop++;
		}
	}

	for(i='A';i<='Z';i++)
	{
		for(j=0;j<26;j++)
		{
			if(up[j]==i) UP[i-'A']=j;
		}
	}
}

int main()
{
	int up[26];
	char str[30],line[100000];
	scanf("%s",str);
	getchar();
	biao(up,str);

	while(gets(line)!=NULL)
	{
		//getchar();
		int len=strlen(line),i;
		for(i=0;i<len;i++)
		{
			if(line[i]>='A'&&line[i]<='Z') line[i]=up[line[i]-'A']+'A';
			if(line[i]>='a'&&line[i]<='z') line[i]=up[line[i]-'a']+'a';
		}
		printf("%s\n",line);
	}
}