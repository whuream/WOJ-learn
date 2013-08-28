#include <stdio.h>

int main()
{
    int k, n, i, j, r; 
    int ans[30100];
    while(scanf("%d %d", &n, &k) == 2)
    {
        for(i = 1; i <=n; i ++)
        {
            r = (k - 1) % i;
            for(j = i + 1; j <= n; j ++)
            {
                r = (r + k) % j;
            }
            ans[i - 1] = r + 1;
        }
        for(i = n - 1; i >=0; i --)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}