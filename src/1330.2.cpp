#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a[1000],b[1000];
    int i,j,k;
    while(scanf("%s%s",a,b)==2)
    {
        char c[1000];
        c[0]='\0';
        int num=-1;
        for(i=0;i<1000;i++)
        {
            if(a[i]=='\0') break;
            for(j=0;j<1000;j++)
            {
                if(b[j]=='\0') break;
                if(a[i]==b[j])
                {
                    for(k=0;k<1000;k++)
                    {
                        if(c[k]==a[i]) break;
                        if(c[k]=='\0')
                        {
                            c[k]=a[i];
                            c[k+1]='\0';
                            num++;
                            break;
                        }

                    }
                }
            }
        }
        for(i=num;i>=0;i--)
        {
            printf("%c",c[i]);
        }
        printf("\n");
    }
    return 0;
}
