#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a;
    scanf("%d",&a);
    float b;
    while(scanf("%d%%",&a)==1)
    {
        if(a==100) b=1.0;
        else b=a*a*1.0/(10000.0-2.0*a*100+2.0*a*a);
        printf("%.2f%%\n",b*100);
    }
    return 0;
}
