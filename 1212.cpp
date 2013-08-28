#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int a[74], v[74];
int n, sum, len;

bool dfs(int index, int slen, int sleft)
{
    if(sleft == 0)
    {
        return true;
    }

    int i;
    for(i = index; i < n; i ++)
    {
        if(v[i] == false && a[i] <= slen)
        {
            v[i] = true;
            if(a[i] == slen && dfs(1, len, sleft - a[i])\
                || dfs(i+1,slen-a[i],sleft-a[i]))
            {
                return true;
            }
            v[i] = false;
            if(a[i] == slen || sleft == sum || slen == len)
            {
                return false;
            }
            while(a[i] == a[i+1])
            {
                i ++;
            }
        }
    }
    return false;
}

int main()
{
    int i;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
        {
            break;
        }
        sum = 0;
        for(i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a,a+n,cmp);
        len = a[0];
        memset(v, 0, sizeof(v));
        for(;len <= sum/2;len++)
        {
            if(sum%len == 0 && dfs(0,len, sum))
            {
                printf("%d\n",len);
                break;
            }
        }
        if(len == sum/2 + 1)
        {
            printf("%d\n",sum);
        }
    }
    return 0;
}