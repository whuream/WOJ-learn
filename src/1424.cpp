#include<stdio.h>

#define e 2.71828

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int i;
        if(n==0) return 0;
        else if(n==1) printf("1\n");
        else if(n==2) printf("2\n");
        else if(n==4) printf("2 2\n");
        else
        {
            if(n%3==2)
            {
                printf("2 ");
                for(i=0;i<n/3;i++)
                {
                    printf("3");
                    if(i!=n/3-1) printf(" ");
                    else printf("\n");
                }
            }
            if(n%3==1)
            {
                printf("2 2 ");
                for(i=0;i<n/3-1;i++)
                {
                    printf("3");
                    if(i!=n/3-2) printf(" ");
                    else printf("\n");
                }
            }
            if(n%3==0)
            {
                for(i=0;i<n/3;i++)
                {
                    printf("3");
                    if(i!=n/3-1) printf(" ");
                    else printf("\n");
                }
            }
        }
    }
}
