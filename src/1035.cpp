#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        double a=ceil((double((n+1)/2)));
        printf("%d\n",int(a));
    }
    return 0;
}