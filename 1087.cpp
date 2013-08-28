#include<stdio.h>

typedef struct _node
{
    long long int x,y;
}node;

node star[310];

int main()
{
    int N, i, j, k, tmp, MAX = 0;
    double tmpx,tmpy;
    while(scanf("%d", &N)==1)
    {
        MAX = 0;
        for(i = 0; i < N; i ++)
        {
            scanf("%lf %lf", &tmpx, &tmpy);
            star[i].x = (long long int)(tmpx * 10);
            star[i].y = (long long int)(tmpy * 10);
        }

        if(N <= 2)
        {
            printf("%d\n", N);
            continue;
        }

        for(i = 0; i < N; i ++)
        {
            for(j = i + 1; j < N; j ++)
            {
                tmp = 0;
                for(k = 0; k < N; k ++)
                {
                    if((star[i].x - star[j].x) * (star[k].y - star[j].y) ==\
                        (star[i].y - star[j].y) * (star[k].x - star[j].x))
                    {
                        tmp ++;
                    }
                }
                if(tmp > MAX)
                {
                    MAX = tmp;
                }
            }
        }
        printf("%d\n", MAX);
    }
    return 0;
}