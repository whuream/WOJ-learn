#include<stdio.h>

int main()
{
    unsigned long int a,b;
    while(scanf("%ld %ld",&a,&b)==2)
    {
        int min=60000;
        int tem;
        for(int i=0;i<a;i++)
        {
            scanf("%d",&tem);
            if(tem<min)
            {
                min=tem;
            }
        }
        printf("%d\n",b/min);
    }
    return 0;
}
