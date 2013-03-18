#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) return 0;
        if(n<=2)
        {
            printf("0\n");
            return 0;
        }
        float *a;
        a={float *}malloc(sizeof(float)*n*2);
        int i;
        double sun=0.0;
        for(i=1;i<n-1;i++)
        {
            sun+=
        }
    }
}
