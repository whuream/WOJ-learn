#include<stdio.h>
#include<string.h>
void mine(int *b,int &len_b,char a[],int &deep,int &now);

void mine(int *b,int &len_b,char a[],int &deep,int &now)
{
    deep++;
    char min='z'+1;
    int i;
    int tmp[105];
    int len=0;
    for(i=0;i<len_b;i++)
    {
        if(a[b[i]]==min)
        {
            tmp[len]=b[i];
            len++;
        }
        if(a[b[i]]<min)
        {
            len=1;
            min=a[b[i]];
            tmp[0]=b[i];
        }
    }
    if(len==1)
    {
        now=tmp[0]-deep+1;
        return;
    }
    else
    {
        for(i=0;i<len;i++)
        {
            tmp[i]++;
        }
        mine(tmp,len,a,deep,now);
    }
}

int main()
{
    char a[105];
    while(scanf("%s",a)==1)
    {
        int len=strlen(a);
        int b[105],deep=0,now;
        for(now=0;now<len;now++)
            b[now]=now;
        mine(b,len,a,deep,now);
        for(deep=0;deep<len;deep++)
        {
            printf("%c",a[(now+deep)%len]);
        }
        printf("\n");
    }
    return 0;
}
