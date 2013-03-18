#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    int *a;
    char X;
    a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        a[i]=0;
        char b[16][16];
        int num=1,p,q,bn=0,wn=0;
        for(j=0;j<15;j++)
        {
            scanf("%s",b[j]);
        }
        for(j=0;j<15;j++)
        for(k=0;k<15;k++)
        {
            if(b[j][k]=='W') wn++;
            if(b[i][k]=='B') bn++;
        }
        if(wn==bn) X='B';
        if(wn+1==bn) X='W';
      //  printf("***\n");
        for(j=0;j<15;j++)
        {
          //  printf("***\n");
            for(k=0;k<15;k++)
            {
              //  printf("***\n");
                if(b[j][k]=='.')
                {
                    p=k-1;
                    while(1)
                    {
                        if(p<0||p>=15) break;
                        if(b[j][p]!=X) break;
                        else num++;
                        p--;
                    }
                    p=k+1;
                    while(1)
                    {
                        if(p<0||p>=15) break;
                        if(b[j][p]!=X) break;
                        else num++;
                        p++;
                    }
                    if(num>=5)
                    {
                        a[i]=1;
                        break;
                    }
                    num=1;
                    p=j-1;
                    while(1)
                    {
                        if(p<0||p>=15) break;
                        if(b[p][k]!=X) break;
                        else num++;
                        p--;
                    }
                    p=j+1;
                    while(1)
                    {
                        if(p<0||p>=15) break;
                        if(b[p][k]!=X) break;
                        else num++;
                        p++;
                    }
                    if(num>=5)
                    {
                        a[i]=1;
                        break;
                    }
                    num=1;
                    p=j-1;
                    q=k-1;
                    while(1)
                    {
                        if(p<0||p>=15||q<0||q>=15) break;
                        if(b[p][q]!=X) break;
                        else num++;
                        p--;
                        q--;
                    }
                    p=j+1;
                    q=k+1;
                    while(1)
                    {
                        if(p<0||p>=15||q<0||q>=15) break;
                        if(b[p][q]!=X) break;
                        else num++;
                        p++;
                        q++;
                    }
                    if(num>=5)
                    {
                        a[i]=1;
                        break;
                    }
                    num=1;
                    p=j-1;
                    q=k+1;
                    while(1)
                    {
                        if(p<0||p>=15||q<0||q>=15) break;
                        if(b[p][q]!=X) break;
                        else num++;
                        p--;
                        q++;
                    }
                    p=j+1;
                    q=k-1;
                    while(1)
                    {
                        if(p<0||p>=15||q<0||q>=15) break;
                        if(b[p][q]!=X) break;
                        else num++;
                        p++;
                        q--;
                    }
                    if(num>=5)
                    {
                        a[i]=1;
                        break;
                    }
                }
            }
            if(a[i]==1) break;
        }
        char c;
        while((c=getchar())!='\n');
    }
    for(i=0;i<n;i++)
    {
       // printf("******\n");
        if(a[i]==1) printf("YES");
        else printf("NO");
        if(i!=n-1) printf("\n");
    }
   // printf("the last\n");
    return 0;
}
