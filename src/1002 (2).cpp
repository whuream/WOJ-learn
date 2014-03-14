#include<stdio.h>
#include<stdlib.h>


int main()
{
    int a,b,i,num=0,flag=1;
    char c,front='\0',f2='\0',f3='\0';
    while(scanf("%d:%d",&a,&b)!=EOF)
    {
        num=0;
        while(1)
        {
            c=getchar();
            if(c=='\n'&&front=='.')
            {
                break;
            }
            if(c=='\n'&&front==','&&f2=='k') break;
            if(c=='\0'&&front==':'&&f2=='s') break;
            if(c=='\0'&&front==':'&&f2=='d'&&f3=='o') break;
            if((c==';'||c==','||c==':'||c=='.'||c=='\''||c=='\"'||c==' '||c=='\n'))
            {
                flag=1;
            }
            if(!(c==';'||c==','||c==':'||c=='.'||c=='\''||c=='\"'||c==' '||c=='\n')&&flag==1)
            {
                num++;
                flag=0;
            }
            f3=f2;
            f2=front;
            front=c;
        }
        printf("%d:%d %d\n",a,b,num);
    }
    return 0;
}
