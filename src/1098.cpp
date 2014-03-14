#include<stdio.h>
#include<string.h>


int zuiduo(char *c,int lc,char *x,int lx)
{
	int j,k,tmp=0,max=0,pre=0;
	for(j=0;j<lc;j++)
	{
		for(k=0;k<lx;k++)
		{
			if(c[j+k]!=x[k])
			{
				if(k==0)
					j=j+k;
				else j=j+k-1;
				break;
			}
		}
		if(k==lx)
		{
			j=j+lx-1;
			tmp++;
			pre=1;
			tmp>max?max=tmp:1;
		}
		else
		{
			pre=0;
			tmp>max?max=tmp:1;
			tmp=0;
		}
	}
	return max;
}



int main()
{
	int N,i;
	char dong[]={"dongfangxu"};
	char zap[4]={"zap"};
	scanf("%d",&N);
	getchar();

	for(i=0;i<N;i++)
	{
		char c[100000];
		gets(c);
		int pre=0;
		
		int lc=strlen(c);

		int dm=zuiduo(c,lc,dong,strlen(dong));
		int zm=zuiduo(c,lc,zap,strlen(zap));
		//printf("%d\n%d\n",dm,zm);
		
		zm>dm?printf("zap!\n"):printf("dongfangxu!\n");
	}
	return 0;
}