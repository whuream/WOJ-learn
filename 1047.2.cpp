#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
		ÄÚ´æ±¬µô
*/

int main()
{
	int N,i,j,k;
	char a[2005],b[2005];
	scanf("%d",&N);
	fflush(stdin);
	for(k=0;k<N;k++)
	{
		int **c;
		c=(int **)malloc(sizeof(int *)*2005);
		for(i=0;i<2005;i++) c[i]=(int *)malloc(sizeof(int)*2005);
		int la,lb,max=0;
		gets(a);
		fflush(stdin);
		gets(b);
		fflush(stdin);
		la=strlen(a);
		lb=strlen(b);
		for(i=0;i<=la;i++) c[i][0]=0;
		for(i=0;i<=lb;i++) c[0][i]=0;
		for(i=1;i<=la;i++)
			for(j=1;j<=lb;j++)
				if(a[i-1]==b[j-1])
				{
					c[i][j]=c[i-1][j-1]+1;
					max=max>c[i][j]?max:c[i][j];
				}
		printf("%d\n",max);
	}
	return 0;
}