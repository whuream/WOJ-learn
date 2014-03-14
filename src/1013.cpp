#include<stdio.h>
#include<string.h>


void scan(char str[],int temp[],int &len)
{
    int i;
    char min='z'+1;
    int llen=len;
    for(i=0;i<llen;i++)
    {
        if(str[temp[i]]<min)
        {
            len=1;
            temp[0]=temp[i];
            min=str[temp[i]];
        }
        else if(str[temp[i]]==min)
        {
            temp[len]=temp[i];
            len++;
        }
    }
}

void add(int temp[],int len,int &count,int slen)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(temp[i]!=slen-1)
        {
            temp[i]+=1;
        }
        else
        {
            temp[i]=0;
        }
    }
    count++;
}

void tryonce(char str[],int temp[],int &len,int slen,int &count)
{
    while(1)
    {
        scan(str,temp,len);
        if(len==1)
        {
            break;
        }
        add(temp,len,count,slen);
    }
    int i;
    int real=temp[0]-count;
    if(real<0)
    {
        real+=slen;
    }
    for(i=real;i<slen;i++)
    {
        printf("%c",str[i]);
    }
    for(i=0;i<real;i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}


int main()
{
    char str[105];
    int slen;
    int i,flag=0;
    while(scanf("%s",str)!=EOF)
    {
        slen=strlen(str);
        int temp[105];
        for(i=0;i<105;i++)
        {
            temp[i]=i;
        }
        int len=slen;
        int count=0;
        for(i=1;i<slen;i++)
        {
            if(str[i]!=str[0])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            tryonce(str,temp,len,slen,count);
        }
        else
        {
            printf("%s\n",str);
        }
    }
    return 0;
}