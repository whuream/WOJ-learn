#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	node *pre,*next;
}Node;


Node* input(Node *p)
{
	int tmp;
	scanf("%d",&tmp);
	if(tmp==0) return p;

	Node *one;

	one=(Node *)malloc(sizeof(Node));
	one->data=tmp;
	one->pre=p;
	one->next=NULL;

	p->next=one;
	input(one);
}

void sort(Node *s,Node *t)
{
	Node *i=s,*j=t;
	int tmp;
	tmp=s->data;
	while(i!=j)
	{
		while(i!=j&&j->data>=tmp) j=j->pre;

		i->data=j->data;

		while(i!=j&&i->data<=tmp) i=i->next;

		j->data=i->data;
	}
	i->data=tmp;

	if(s!=i&&s->next!=i)
		sort(s,i->pre);

	if(t!=i&&i->next!=t)
		sort(i->next,t);
}


void output(Node *p)
{
	int pre=-1;
	while(p!=NULL)
	{
		if(pre!=p->data)
		{
			pre=p->data;
			printf("%d ",p->data);
		}
		p=p->next;
	}
}

int main()
{
	Node *p,*end;
	p=(Node *)malloc(sizeof(Node));
	p->data=-1;
	p->pre=NULL;
	p->next=NULL;

	end=input(p);
	
	sort(p->next,end);

	output(p->next);

	return 0;
}