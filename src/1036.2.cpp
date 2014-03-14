#include<stdio.h>
#include<string.h>

typedef struct
{
    char a[200];
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



void sum(char *Q1,char* Q2,char *tmp)
{
    int i,j;
        cell a,b;
        int pre;
        cell *A=&a,*B=&b;

		strcpy(A->a,Q1);
		strcpy(B->a,Q2);

        A->len=strlen(A->a);
        B->len=strlen(B->a);
        if(a.len<b.len)
        {
            A=&b;
            B=&a;
        }
        if(add(A,B)==1)
        {
			char *M=tmp+1;
            strcpy(tmp,"1");
			strcpy(M,A->a);
        }
        //for(j=0;j<A->len;j++)
		else
		{
            //printf("%c",A->a[j]);
			strcpy(tmp,A->a);
        }
}


int main()
{
	char Q[501][200];
	char tmp[200];
	strcpy(Q[1],"1\0");
	strcpy(Q[2],"2\0");
	strcpy(Q[3],"3\0");

	for(int i=4;i<501;i++)
	{
		sum(Q[i-2],Q[i-3],tmp);
		sum(Q[i-1],tmp,Q[i]);
	}
	int N;

	//for(N=0;N<=500;N++) printf("%s\n",Q[N]);
	while(scanf("%d",&N)!=EOF)
	{
		
		if(N==0) break;
		printf("%s\n",Q[N]);
	}
	return 0;
}