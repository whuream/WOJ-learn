#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    char **c;
    c=(char **)malloc(sizeof(char *)*n*2);
    fflush(stdin);
    //for(i=0;i<n*2;i++)

    for(i=0;i<n*2;i++)
    {
        c[i]=(char *)malloc(sizeof(char)*200);
    //    printf("****\n");
        scanf("%s",c[i]);

    }
   // printf("****\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<200;j++)
        {
            if(c[2*i+1][j]=='\0') break;
            if(j==0) printf("%c",toupper(c[2*i+1][j]));
            else printf("%c",tolower(c[2*i+1][j]));
        }
        printf(" ");
        for(j=0;j<200;j++)
        {
            if(c[2*i][j]=='\0') break;
            if(j==0) printf("%c",toupper(c[2*i][j]));
            else printf("%c",tolower(c[2*i][j]));
        }
        if(i!=n-1)
        printf("\n");
    }
}
