#include<stdio.h>
#include<math.h>

typedef struct
{
	int x,y;
}cell;

double D(cell a,cell b)
{
	return sqrt(pow(double(a.x-b.x),2)+pow(double(a.y-b.y),2));
}

int main()
{
	cell A[100];
	int N,i;
	double pie=3.141592653589793;
	double k1=2*pie/3-sqrt(3.0)/2;
	double k2=pie/2-1;
	double k3=sqrt(2.0);
	double area=0;
	while(scanf("%d",&N)==1)
	{
		for(i=0;i<N;i++)
		{
			scanf("%d %d",&A[i].x,&A[i].y);
		}
		area=pie*N;
		int j;
		for(i=0;i<N;i++)
			for(j=i+1;j<N;j++)
			{
				if(fabs(D(A[i],A[j])-1.0)<0.001) area-=k1;
				else if(fabs(D(A[i],A[j])-k3)<0.001) area-=k2;
			}
		printf("%.2lf",area);
	}
	return 0;
}