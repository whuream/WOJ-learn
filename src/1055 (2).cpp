#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a[300];
    char b[11]="ENDOFINPUT";
    char c[100][300];
    int m,n,t;
    for(m=0;m<100;m++)
    {
        fflush(stdin);
        gets(a);
        int i,flag=1;
        for(i=0;i<11;i++)
        {
            if(a[i]!=b[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==1) break;
        gets(a);
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='E') c[m][i]='Z';
            else if(a[i]>=65&&a[i]<=90)
            {
                c[m][i]=(a[i]-43)%26+64;
            }
            else c[m][i]=a[i];
        }
        c[m][i]='\0';
        fflush(stdin);
        scanf("%s",a);
        //printf("%s\n",c[m]);
    }
    for(n=0;n<=m;n++)
    {
        printf("%s",c[n]);
        if(n!=m) printf("\n");
    }
    return 0;
}
