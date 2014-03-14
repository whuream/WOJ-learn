#include<algorithm>

#include<stdio.h>
#include<string.h>

using namespace std;

int T, N;

typedef struct _node
{
    int t, p;
}node;

node list[3010];

int ans[3010];

bool cmp(node a, node b)
{
    return a.p > b.p;
}

int main()
{
    int i, j, index, sum, psum;;
    scanf("%d", &T);
    for(i = 0; i < T;i ++)
    {
        sum = 0, psum = 0;
        scanf("%d", &N);
        for(j = 0; j < N; j ++)
        {
            scanf("%d %d", &list[j].t, &list[j].p);
            sum += list[j].p;
        }
        sort(list, list + N, cmp);
        memset(ans + 1, 0, sizeof(ans[0]) * (N+1));
        for(j = 0; j < N; j ++)
        {
            index = list[j].t;
            while(ans[index] != 0)
            {
                index --;
                if(index == 0)
                {
                    break;
                }
            }
            if(index == 0)
            {
                continue;
            }
            ans[index] = list[j].p;
            psum += list[j].p;
        }
        printf("Case %d:\n%d\n", i+1, sum-psum);
        if(i != N - 1)
        {
            printf("\n");
        }
    }
    return 0;
}