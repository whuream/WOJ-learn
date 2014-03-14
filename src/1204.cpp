#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N,i,SIZE_2=10,SIZE_1=50000;
    int **a;
    a=(int **)malloc(sizeof(int *)*SIZE_2);
    for(i=0;i<SIZE_2;i++) a[i]=(int *)malloc(sizeof(int)*SIZE_1);

    while(scanf("%d",&N)==1)
    {
        int i,num=0,loop=0,tmp,j;
        int A=0,B=0;

        for(i=1;i<N;i++)
        {
            scanf("%d",&tmp);
            a[A][B]=tmp;
            B++;
            if(B==SIZE_1)
            {
                A++;
                B=0;
            }
            if(loop==0)
            {
                loop++;
                num=tmp;
            }
            else
            {
                if(tmp==num) loop++;
                else loop--;
            }
        }
        int num_num=0,num_tmp=0;

        scanf("%d",&tmp);
        a[A][B]=tmp;

        A=0;
        B=0;
        for(i=0;i<N;i++)
        {
            if(a[A][B]==num) num_num++;
            if(a[A][B]==tmp) num_tmp++;
            B++;
            if(B==SIZE_1)
            {
                A++;
                B=0;
            }
        }
       
       
        printf("%d\n",num_num>num_tmp?num:tmp);
    }
    return 0;
}