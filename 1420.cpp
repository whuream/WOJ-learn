#include <stdio.h>
#include <stdlib.h>

int charge(long int a,long int b)
{
   long int i,j,c;
   c=0;
   for(i=1;i<a;i++)
   for(j=1;j<b;j++)
   {
     if(a/i==b/j)
     c++;
    }
    if(c!=0)
    c=1;
    else c=0;
    return (c);
}
int main()
{
    long int a,j,k,i;
    scanf("%d",&a);
    long int *b,*c,*d;
	b=(long int *)malloc(sizeof(long int)*a);
	c=(long int *)malloc(sizeof(long int)*a);
	d=(long int *)malloc(sizeof(long int)*a);
    for(i=0;i<a;i++)
    {
    scanf("%d %d",&b[i],&c[i]);
    d[i]=0;
}
    for(i=0;i<a;i++)
    for(j=1;j<=b[i];j++)
    for(k=1;k<=c[i];k++)
    {if(charge(j,k)==0)
    d[i]++;}
    for(i=0;i<a;i++)
    printf("%d\n",d[i]);
	system("pause");
    return (0);
}
