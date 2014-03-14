#include<stdio.h>
#include<string.h>

int main()
{
    char s[100],line[250],e[100];
    while(scanf("%s",s)==1)
    {
        if(!strcmp(s,"ENDOFINPUT")) break;
       
        getchar();
        gets(line);

        int l_line=strlen(line);
        int i;
        for(i=0;i<l_line;i++)
        {
            if(line[i]<='Z'&&line[i]>='A')
            {
                line[i]=(line[i]-'A'+21)%26+'A';
            }
        }
        puts(line);
        scanf("%s",e);
    }
    return 0;
}