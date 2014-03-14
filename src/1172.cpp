#include<stdio.h>

int main()
{
	int N,I=1;
	while(scanf("%d",&N)==1)
	{
		if(N==0) break;
		getchar();
		int i,flag=-1;
		int a[26]={0};
		a[0]=1;
		char A,B;
		for(i=0;i<N;i++)
		{
			scanf("%c",&A);
			getchar();
			getchar();
			getchar();
			scanf("%c",&B);
			getchar();
			//fflush(stdin);
			if(a[B-'a']==1) a[A-'a']=1;
			else a[A-'a']=0;
		}
		printf("Program %d\n",I);

		I++;
		for(i=0;i<26;i++)
		{
			if(a[i]==1) flag=i;
		}
		if(flag==-1) printf("none\n");
		else
		{
			for(i=0;i<26;i++)
			{
				if(a[i]==1)
				{
					printf("%c",'a'+i);
					if(i==flag) printf(" \n");
					else printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}