#include<stdio.h>
#include<stdlib.h>

void quick(int *a,int s,int t)
{
	int i=s,j=t;
	int tmp;
	if(s<t)
	{
		tmp=a[s];
		while(i!=j)
		{
			while(j>i&&a[j]>=tmp) j--;
			a[i]=a[j];
			while(j>i&&a[i]<=tmp) i++;
			a[j]=a[i];
		}
		a[i]=tmp;
		quick(a,s,i-1);
		quick(a,i+1,t);
	}
}

int input(int **a)
{
	int i,j,count=0;
	int tmp;
	for(i=0;i<100;i++)
	{
		for(j=0;j<100000;j++)
		{
			scanf("%d",&tmp);
			if(tmp==0) return count;
			a[i][j]=tmp;
			count++;
		}
	}
	return count;
}


void sort(int **a,int big,int small)
{
	int i,j;
	for(i=0;i<=big-1;i++) quick(a[i],0,100000-1);
	quick(a[big],0,small);
}


void output(int **a,int big,int small)
{
	int pre=-1,i,j;
	for(i=0;i<big-1;i++)
		for(j=0;j<100000-1;j++)
		{
			if(a[i][j]!=pre)
			{
				pre=a[i][j];
				printf("%d ",a[i][j]);
			}
		}
	for(j=0;j<small;j++)
	{
		if(a[big][j]!=pre)
		{
			pre=a[i][j];
			printf("%d ",a[i][j]);
		}
	}
	//printf("\n");
}

int main()
{
	int **a,i,j,big,small;

	a=(int **)malloc(sizeof(int *)*100);
	for(i=0;i<10;i++) a[i]=(int *)malloc(sizeof(int)*100000);

	int num=input(a);

	if(num%100000==0)
	{
		big=num/100000-1;
		small=100000-1;
	}
	else
	{
		big=num/100000;
		small=num%100000-1;
	}

	sort(a,big,small);

	output(a,big,small);

	return 0;
}