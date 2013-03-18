#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n;
    scanf("%d",&n);
    double *a;
    a=(double *)malloc(sizeof(double)*n);
    for(int i=0;i<n;i++)
    {
        long int b,c,d;
        scanf("%ld%ld%ld",&b,&c,&d);
        a[i]=c*1.0/(b*1.0)*d;
    }
    for(int i=0;i<n;i++)
    {
        printf("%.2lf",a[i]);
        if(i!=n-1)
        printf("\n");
    }
}
