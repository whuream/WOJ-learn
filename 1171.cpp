#include<stdio.h>

int f[20][20][20];   //全局变量会初始化为0

int W(int a,int b,int c)
{
	if(f[a][b][c]!=-100001) return f[a][b][c];
	else if(a<=0||b<=0||c<=0) return 1;
	else if(a<b&&b<c) 
	{
		if(f[a][b][c]==-100001)
		{
			f[a][b][c-1]=W(a,b,c-1);
			f[a][b-1][c-1]=W(a,b-1,c-1);
			f[a][b-1][c]=W(a,b-1,c);

			return f[a][b][c-1]+f[a][b-1][c-1]-f[a][b-1][c];
		}
		else return f[a][b][c];
	}
	else 
	{
		if(f[a][b][c]==-100001)
		{
			f[a-1][b][c]=W(a-1,b,c);
			f[a-1][b-1][c]=W(a-1,b-1,c);
			f[a-1][b][c-1]=W(a-1,b,c-1);
			f[a-1][b-1][c-1]=W(a-1,b-1,c-1);

			return f[a-1][b][c]+f[a-1][b-1][c]+f[a-1][b][c-1]-f[a-1][b-1][c-1];
		}
		else return f[a][b][c];
	}
}

int main()
{
	int N,i,j,k;

	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			for(k=0;k<20;k++)
				f[i][j][k]=-100001;
	scanf("%d",&N);

	for(i=0;i<N;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);

		if(a<=0||b<=0||c<=0) printf("W(%d, %d, %d) = 1\n",a,b,c);
		else if(a>=20||b>=20||c>=20) printf("W(%d, %d, %d) = 1048576\n",a,b,c);
		else printf("W(%d, %d, %d) = %d\n",a,b,c,W(a,b,c));
	}
	return 0;
}