#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

typedef struct _node
{
    double x,y;
}node;


int main()
{
    int n,i,j;
    double ans;
    while(scanf("%d",&n))
    {
        if(n == 0)
        {
            break;
        }
        vector<node> v(n);
        for(i = 0; i < n; i ++)
        {
            scanf("%lf %lf", &v[i].x, &v[i].y);
        }
        if(i <= 2)
        {
            printf("0\n");
            continue;
        }
        ans = 0;
        for(i = 0, j = 1; i < n; i ++, j ++)
        {
            j = j % n;
            ans += v[i].x*v[j].y - v[i].y * v[j].x;
        }
        ans = fabs(ans * 0.5);
        printf("%d\n",int(ans + 0.5));
    }
    return 0;
}