#include<stdio.h>
#include<stdlib.h>

int BFS(int **a,int Animal,int a1,int a2)
{
	int *queue,*visited,i,w,time=0,tmp;
	queue=(int *)malloc(sizeof(int)*Animal);
	visited=(int *)malloc(sizeof(int)*Animal);
	int front=0,rear=0;
	for(i=0;i<Animal;i++) visited[i]=-2;
	visited[a1]=-1;
	rear=(rear+1)%Animal;
	queue[rear]=a1;
	while(front!=rear)
	{
		front=(front+1)%Animal;
		w=queue[front];
		for(i=0;i<Animal;i++)
		{
			if(visited[i]==-2&&a[w][i]==1)
			{
			visited[i]=w;
			if(i==a2)
			{
				tmp=a2;
				while(visited[tmp]!=-1)
				{
					time++;
					tmp=visited[tmp];
				}
				return time-1;
			}
			rear=(rear+1)%Animal;
			queue[rear]=i;
			}
		}
	}
	return -1;
}

int main()
{
	int Animal,line,Q,i,j,a1,a2;
	scanf("%d %d",&Animal,&line);
	fflush(stdin);
	int **a;
	a=(int **)malloc(sizeof(int *)*Animal);
	for(i=0;i<Animal;i++)
	{
		a[i]=(int *)malloc(sizeof(int)*Animal);
	}
	for(i=0;i<Animal;i++)
		for(j=0;j<Animal;j++)
		{
			if(i==j) a[i][j]=1;
			else a[i][j]=0;
		}
	for(i=0;i<line;i++)
	{
		scanf("%d %d",&a1,&a2);
		fflush(stdin);
		a[a1][a2]=a[a2][a1]=1;
	}
	scanf("%d",&Q);
	fflush(stdin);
	for(i=0;i<Q;i++)
	{
		scanf("%d %d",&a1,&a2);
		fflush(stdin);
		if(a1==a2) printf("0\n");
		else printf("%d\n",BFS(a,Animal,a1,a2));
	}
	return 0;
}