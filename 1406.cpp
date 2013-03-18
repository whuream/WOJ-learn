#include<stdio.h>

int main()
{
    long int a,b;
    while(scanf("%ld %ld",&a,&b)==2)
    {
        if(a==0) printf("0\n");
        else
        {
            printf("%ld\n",(long int)(double(b)/double(a)/2.00+0.5-0.000001));
        }
    }
    return 0;
}
