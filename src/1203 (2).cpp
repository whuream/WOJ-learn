#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int num;
    int sum;
    node *next;
}cell;

int main()
{
   int n;
   while(scanf("%d",&n)==1)
   {
      cell *p=(cell *)malloc(sizeof(cell));
      cell *q;
      p->next=NULL;
      p->num=1000001;
      p->sum=-10000;
      int i;
      for(i=0;i<n;i++)
      {
          int tem;
          scanf("%d",&tem);
          q=p;
          while(1)
          {
              if(q->num==tem)
              {
                  q->sum++;
                  break;
              }
              if(q->next==NULL)
              {
                  cell *t;
                  t=(cell *)malloc(sizeof(cell));
                  p->next=t;
                  t->next=NULL;
                  t->num=tem;
                  t->sum=1;
                  break;
              }
              q=q->next;
          }
      }
      q=p;
      while(q->next!=NULL)
      {
          if(q->sum>=(n+1)/2)
          {
              printf("%d\n",q->sum);
              break;
          }
          q=q->next;
      }
   }
   return 0;
}
