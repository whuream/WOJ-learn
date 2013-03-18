#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int num;
    int max;
}cell;


int main()
{
    int t;
    scanf("%d",&t);
    int *p;
    p=(int *)malloc(sizeof(int)*t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        cell *w;
        w=(cell *)malloc(sizeof(cell)*n);
        for(int j=0;j<n;j++)
        {
            w[j].num=-1;
            w[j].max=1;
        }
        for(int j=0;j<n;j++)
        {
            int s;
            scanf("%d",&s);
            int k,flag;
            for(k=0;k<n;k++)
            {
                if(w[k].num==s)
                {
                    w[k].max++;
                    flag=0;
                    break;
                }
                if(w[k].num==-1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                w[k].num=s;
            }
        }
        int max=-1;
        for(int k=0;k<n;k++)
        {
            if(w[k].num==-1)
            {
                break;
            }
            if(w[k].max>max)
            {
                max=w[k].max;
            }
        }
        p[i]=max;
    }
    for(int i=0;i<t;i++)
    {
        printf("%d",p[i]);
        if(i!=t-1)
        printf("\n");
    }
    return 0;
}
