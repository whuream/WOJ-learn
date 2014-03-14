#include<stdio.h>
#include<string.h>

int main()
{
	int N,i;
	scanf("%d",&N);
	getchar();

	char a[8][20]={{"littleken"},{"knuthocean"},{"dongfangxu"},{"zap"},{"kittig"},{"robertcui"},{"forest"},{"flirly"}};

	for(i=0;i<N;i++)
	{
		char c[1000002];
		scanf("%s",c);
		getchar();

		int j,k,f=-1;
		int max[8]={0};
		int lc=strlen(c);

	/*	j=0;
		if(c[j]=='z') f=3;
		if(c[j]=='d') f=2;
		if(c[j]=='l') f=0;
		if(c[j]=='k'&&c[j+1]=='n') f=1;
		if(c[j]=='k'&&c[j+1]=='i') f=4;
		if(c[j]=='r') f=5;
		if(c[j]=='f'&&c[j+1]=='o') f=6;
		if(c[j]=='f'&&c[j+1]=='l') f=7;
	*/	

		for(j=0;j<lc;)
		{
			if(c[j]=='z')
			{
				max[3]++;
				j+=3;
			}
			if(c[j]=='d')
			{
				max[2]++;
				j+=10;
			}
			if(c[j]=='l')
			{
				max[0]++;
				j+=9;
			}
			if(c[j]=='k'&&c[j+1]=='n')
			{
				max[1]++;
				j+=10;
			}
			if(c[j]=='k'&&c[j+1]=='i')
			{
				max[4]++;
				j+=6;
			}
			if(c[j]=='r')
			{
				max[5]++;
				j+=9;
			}
			if(c[j]=='f'&&c[j+1]=='o')
			{
				max[6]++;
				j+=6;
			}
			if(c[j]=='f'&&c[j+1]=='l')
			{
				max[7]++;
				j+=6;
			}
		}
		int MAX=0,TMP=max[0];
		for(j=0;j<8;j++) 
		{
			//if(max[j]!=TMP) break;
		//	printf("%d\n",max[j]);
		}
		//if(j==8) printf("%s\n",a[f]);
		//else
		{
			for(j=0;j<8;j++)
				if(max[j]>TMP)
				{
					TMP=max[j];
					MAX=j;
				}
			printf("%s\n",a[MAX]);
		}
	}
	return 0;
}