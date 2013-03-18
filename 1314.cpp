#include<stdio.h>

int cell(int n,int i)
{
    if(n==1) return i;
    if(n%2==0) return cell(n/2,i+1);
    else return cell(3*n+1,i+1);
}

int main()
{
  //  printf("%d",cell(22,1));
    int m,n;
    while(scanf("%d%d",&m,&n)==2)
    {
        int i,tem,max=0;
        if(m==0&&n==0) break;
        for(i=m;i<=n;i++)
        {
            tem=cell(i,1);
            if(max<tem) max=tem;
        }
        printf("%d\n",max);
    }
}
