#include<stdio.h>
#include<string.h>

typedef struct
{
    char a[1005];
    int len;
}cell;

int add(cell *A,cell *B)
{
    int i,pre=0;
    for(i=0;i<A->len;i++)
    {
        if(i<B->len) A->a[A->len-1-i]=A->a[A->len-1-i]+B->a[B->len-1-i]+pre-'0';
        else A->a[A->len-1-i]+=pre;
        if(A->a[A->len-1-i]>'9')
        {
            A->a[A->len-1-i]-=10;
            pre=1;
        }
        else
        {
            pre=0;
        }
    }
    return pre;
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    fflush(stdin);
    for(i=0;i<n;i++)
    {
        cell a,b;
        int pre;
        cell *A=&a,*B=&b;
        scanf("%s%s",A->a,B->a);
        A->len=strlen(A->a);
        B->len=strlen(B->a);
        if(a.len<b.len)
        {
            A=&b;
            B=&a;
        }
        if(add(A,B)==1)
        {
            printf("1");
        }
        for(j=0;j<A->len;j++)
        {
            printf("%c",A->a[j]);
        }
            if(i!=n-1) printf("\n");
    }
    return 0;
}