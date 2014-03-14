#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int N,i,j,k;
	char a[2005],b[2005];
	scanf("%d",&N);
	getchar();
	//fflush(stdin);
	for(k=0;k<N;k++)
	{
		int c[2005];
		int la,lb,max=0,tmp,pre;
		gets(a);
		//fflush(stdin);
		gets(b);
		//fflush(stdin);
		la=strlen(a);
		lb=strlen(b);
		for(i=0;i<lb;i++) c[i]=0;
		for(i=0;i<la;i++)
		{
			pre=0;
			for(j=0;j<lb;j++)
			{
				tmp=c[j];
				if(a[i]==b[j])
				{
					c[j]=pre+1;
					max=max>c[j]?max:c[j];
				}
				else c[j]=0;
				pre=tmp;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}