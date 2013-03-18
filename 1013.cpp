#include<stdio.h>
#include<string.h>


void scan(char str[105],int temp[105],int &len)
{
	int i;
	char min='z'+1;
	int llen=len;
	for(i=0;i<llen;i++)
	{
		if(str[temp[i]]<min)
		{
			len=1;
			temp[0]=temp[i];
			min=str[temp[i]];
		}
		else if(str[temp[i]]==min)
		{
			temp[len]=temp[i];
			len++;
		}
	}
}

void add(int temp[105],int len,int &count,int slen)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(temp[i]!=slen-1)
		{
			temp[i]+=1;
		}
		else
		{
			temp[i]=0;
		}
	}
	count++;
}

void tryonce(char str[105],int temp[105],int &len,int slen,int &count)
{
	while(1)
	{
		scan(str,temp,len);
		if(len==1)
		{
			break;
		}
		add(temp,len,count,slen);
	}
	int i;
	int real=temp[0]-count;
	if(real<0)
	{
		real+=slen;
	}
	for(i=real;i<slen;i++)
	{
		printf("%c",str[i]);
	}
	for(i=0;i<real;i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
}


int main()
{
	char str[105];
	int slen;
	int i;
	while(scanf("%s",str)!=EOF)
	{
		slen=strlen(str);
		int temp[105];
		for(i=0;i<105;i++)
		{
			temp[i]=i;
		}
		int len=slen;
		int count=0;
		tryonce(str,temp,len,slen,count);
	}
	return 0;
}