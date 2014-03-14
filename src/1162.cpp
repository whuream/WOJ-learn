#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n,i,j;
    scanf("%d",&n);
    char **a;
    a=(char **)malloc(sizeof(char *)*n);
    for(i=0;i<n;i++)
    a[i]=(char *)malloc(sizeof(char)*2002);
    int *pre,*m1,*m2;
    pre=(int *)malloc(sizeof(int)*n);
    m1=(int *)malloc(sizeof(int)*n);
    m2=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        pre[i]=0;
        fflush(stdin);
        for(j=0;j<2002;j++)
        {

            a[i][j]=getchar();
            if(a[i][j]==' ') m1[i]=j-1;
            if(a[i][j]=='\n')
            {
                m2[i]=j-1;
                break;
            }
        }
        if(m1[i]+1>=m2[i]-m1[i]-1)
        {
            for(j=m2[i];j>m1[i]+1;j--)
            {
                a[i][j-m2[i]+m1[i]]=a[i][j-m2[i]+m1[i]]+a[i][j]-'0'+pre[i];
                if(a[i][j-m2[i]+m1[i]]>'9')
                {
                    a[i][j-m2[i]+m1[i]]-=10;
                    pre[i]=1;
                }
                else pre[i]=0;
            }
            for(j=2*m1[i]-m2[i]+1;j>=0;j--)
            {
                a[i][j]+=pre[i];
                if(a[i][j]>'9')
                {
                    a[i][j]-=10;
                    pre[i]=1;
                }
                else
                {
                    pre[i]=0;
                    break;
                }
            }
        }
        else
        {
            for(j=m1[i];j>=0;j--)
            {
                a[i][j+m2[i]-m1[i]]=a[i][j+m2[i]-m1[i]]+a[i][j]-'0'+pre[i];
                if(a[i][j+m2[i]-m1[i]]>'9')
                {
                    a[i][j+m2[i]-m1[i]]-=10;
                    pre[i]=1;
                }
                else pre[i]=0;
            }
            for(j=m2[i]-m1[i]-1;j>m1[i]+1;j--)
            {
                a[i][j]+=pre[i];
                if(a[i][j]>'9')
                {
                    a[i][j]-=10;
                    pre[i]=1;
                }
                else
                {
                    pre[i]=0;
                    break;
                }
            }
        }
    }
    for (i=0;i<n;i++)
    {
        if(pre[i]==1)
        printf("%d",pre[i]);
        if(m1[i]+1>=m2[i]-m1[i]-1)
        {
            for(j=0;j<m1[i]+1;j++)
            {
                if(a[i][j]!=' ')
                    printf("%c",a[i][j]);
                else break;
            }
        }
        else
        {
            for(j=m1[i]+2;j<=m2[i];j++)
            {
                    printf("%c",a[i][j]);
            }
        }
        if(i!=n-1)
        printf("\n");
    }
    return 0;
}
