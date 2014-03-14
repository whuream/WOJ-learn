#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

typedef vector<vector<int> > mint;

int F(mint &data,int m,int n)
{
    if(m<0) return 0;
    if(data[m][n]==-1)
    {
        data[m][n]=F(data,m,n-1)+F(data,m-n,n);
    }
    return data[m][n];
}

int main()
{
    int m,n;
    while(scanf("%d %d",&m,&n)==2)
    {
        mint data(m+1,vector<int>(n+1,-1));
       
        int i;
        for(i=0;i<=n;i++)
        {
            data[0][i]=1;
        }
        for(i=0;i<=m;i++)
        {
            data[i][1]=1;
        }

        printf("%d\n",F(data,m,n));
    }
    return 0;
}