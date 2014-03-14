#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int room;
	int point;
	double ppr;
}animal;

void equal(animal a,animal b)
{
	a.point=b.point;
	a.room=b.room;
	a.ppr=b.ppr;
}

void sort(animal cou[],int s,int t)
{
	int i=s,j=t;
	animal tmp;
	if(s<t)
	{
		equal(tmp,cou[s]);
		while(i!=j)
		{
			while(j>i&&cou[j].ppr>tmp.ppr)
			{
				j--;
			}
			equal(cou[i]=cou[j];
			while(i<j&&cou[i].ppr<tmp.ppr)
			{
				i++;
			}
			equal(cou[j],cou[i]);
		}
		equal(cou[i],tmp);
		sort(cou,s,i-1);
		sort(cou,i+1,t);
	}
}

int main()
{
	int line;
	while(scanf("%d",&line)!=EOF)
	{
		int size,i,j;
		animal *cou;
		//int *biao;
		//biao=(int *)malloc(sizeof(int)*line);
		cou=(animal *)malloc(sizeof(animal)*line);
		for(i=0;i<line;i++)
		{
			scanf("%d %d",&cou[i].room,&cou[i].point);
			cou[i].ppr=(double)cou[i].point/cou[i].room;
		}
		scanf("%d",&size);
		sort(cou,0,line-1);
		int size_all=0;
		double ppr_all;
		int point_all=0;
		int *list;
		//int room_min=1000001;
		list=(int *)malloc(sizeof(int)*line);
		for(i=0;i<line;i++)
		{
			list[i]=0;
		}
		for(i=0;i<line;i++)
		{
			if(size_all+cou[i].room<=size)
			{
				size_all+=cou[i].room;
				list[i]=1;
				point_all+=cou[i].point;
				//if(cou[i].room<room_min)
				//{
					//room_min=cou[i].room;
				//}
			}
			else
			{
				break;
			}
		}
		ppr_all=(double)point_all/size;
		while(1)
		{
			if(cou[i].ppr>=ppr_all)
			{
				for(j=0;j<i-1;j++)
				{
					if(cou[j].room<cou[i].room&&size_all-cou[j].room+cou[i].room<=size)
					{
						list[]
					}
				}
			}
		}
		//for(i=0;i<line;i++)
		//{
			//biao[i]=i;
		//}
		//for(i=0;i<)
	}
}