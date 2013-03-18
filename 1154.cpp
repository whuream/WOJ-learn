#include<stdio.h>
#include <ctype.h>

int main()
{
    char c;
    int num=1;
    while(1)
    {
        int n=0;
        c=getchar();
        if(c=='#') break;
        printf("Case %d: %c",num,c);
        while(1)
        {
            c=getchar();
            if(c=='\n') break;
            else if(n%2==0) printf("%c",toupper(c));
            else printf("%c",c);
            n++;
        }
        printf("\n");
        num++;
    }
    return 0;
}
