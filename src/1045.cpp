#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    int N,i;
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++)
    {
        char c[10005],pre='F';
        int ls,j;
        gets(c);
        ls=strlen(c);

        c[0]=toupper(c[0]);
        for(j=1;j<ls;j++)
        {
            if(pre!=' ') c[j]=tolower(c[j]);
            pre=c[j];
        }
        printf("%s\n",c);
    }
    return 0;
}