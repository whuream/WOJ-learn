#include<stdio.h>
#include<stdlib.h>
typedef struct cell
{
    char c;
    cell *next;
}node;

int main()
{
    char a[1000],b[1000];
    int i,j;
    while(scanf("%s%s",a,b)==2)
    {
      //  puts(a);
      //  puts(b);
        node *q=(node *)malloc(sizeof(node));
        node *p=q;
        p->next=NULL;
        for(i=0;i<1000;i++)
        {
            if(a[i]=='\0') break;
            for(j=0;j<1000;j++)
            {
                if(b[j]=='\0') break;
                if(a[i]==b[j])
                {
                    p->next=(node *)malloc(sizeof(node));
                    p=p->next;
                    p->next=NULL;
                    p->c=a[i];
                //    system("pause");
                }
            }
        }
        p=q->next;
        while(p!=NULL)
        {
            free(q);
            printf("%c",p->c);
            q=p;
            p=q->next;
        }
        free(q);
        printf("\n");
    }
    return 0;
}
