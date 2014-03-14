#include<stdio.h>
#include<stdlib.h>

/*
			内存不足，，哭！！！
*/

typedef struct node
{
	int data;
	node *next;
}Node;


int main()
{
	int N;
	while(scanf("%d",&N)==1)
	{

		int i,num=0,loop=0,tmp;
		Node *p,*xia;
		p=(Node *)malloc(sizeof(Node));
		p->data=-1;
		p->next=NULL;
		xia=p;
		
		for(i=1;i<=N-1;i++)
		{
			scanf("%d",&tmp);
			xia->next=(Node *)malloc(sizeof(Node));
			xia=xia->next;
			xia->data=tmp;
			xia->next=NULL;

			if(loop==0)
			{
				loop++;
				num=tmp;
			}
			else
			{
				if(tmp==num) loop++;
				else loop--;
			}
		}
		scanf("%d",&tmp);
		xia->next=(Node *)malloc(sizeof(Node));
		xia=xia->next;
		xia->data=tmp;
		xia->next=NULL;

		int num_num=0,num_tmp=0;

		xia=p->next;
		while(xia!=NULL)
		{
			if(xia->data==num) num_num++;
			if(xia->data==tmp) num_tmp++;
			xia=xia->next;
		}

		printf("%d\n",num_num>num_tmp?num_num:num_tmp);
		//printf("%d\n",sizeof(Node));
	}
	return 0;
}