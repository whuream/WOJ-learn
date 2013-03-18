#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*
			这题算是水过去了，，开2500万数组，，，其实应该开3600万的数组再压缩成1800万的。。。
*/

void similar(int a,int b,short int **common,char **name)
{
	int la=strlen(name[a]),lb=strlen(name[b]),lmin;
	lmin=la<lb?la:lb;

	int i,count=0;
	for(i=0;i<lmin;i++)
	{
		if(name[a][i]==name[b][i]) count++;
		else break;
	}
	common[a][b]=common[b][a]=count;
}

int baoli(int a,int b,char **name)
{
	int la=strlen(name[a]),lb=strlen(name[b]),lmin;
	lmin=la<lb?la:lb;

	int i,count=0;
	for(i=0;i<lmin;i++)
	{
		if(name[a][i]==name[b][i]) count++;
		else break;
	}
	return count;
}


int main()
{
	//short int common[6000][6000]={-1};
	//char name[6000][1001];

	int N,i,i1;

	short int **common;
	common=(short int **)malloc(sizeof(short int *)*5001);
	for(i=0;i<5001;i++) common[i]=(short int *)malloc(sizeof(short int)*5001);    //3600万，内存爆掉
	for(i=0;i<5001;i++)
		for(i1=0;i1<5001;i1++)
			common[i][i1]=-1;

	char **name;
	name=(char **)malloc(sizeof(char *)*6001);
	for(i=0;i<6001;i++) name[i]=(char *)malloc(sizeof(char)*1001);

	scanf("%d",&N);

	for(i=0;i<N;i++)
	{
		int id;
		char tmp[1001];
		scanf("%d%s",&id,tmp);  //字符串中不能有空格！！！
		strcpy(name[id],tmp);
	}

	int M;
	scanf("%d",&M);
	for(i=0;i<M;i++)
	{
		int all=0,j,num;

		scanf("%d",&num);

		for(j=0;j<num;j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(a<=5000&&b<=5000)
			{
				if(common[a][b]!=-1) all+=common[a][b];
				else
				{
					similar(a,b,common,name);
					all+=common[a][b];
				}
			}
			else all+=baoli(a,b,name);
		}
		printf("%d\n",all);
	}
	return 0;

}