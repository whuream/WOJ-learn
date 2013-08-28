#include<stdio.h>

typedef struct _node
{
    int l, r, m;
    int c;
}node;

node segtree[30100 * 3];

int get(int k ,int num)
{
    if(segtree[num].l + 1 == segtree[num].r)
    {
        segtree[num].c --;
        return segtree[num].l;
    }
    int t = segtree[2 * num].c;
    if(k < t)
    {
        segtree[num].c --;
        return get(k, 2 * num);
    }
    else
    {
        segtree[num].c --;
        return get(k - t, 2 * num + 1);
    }
}
/*
int up(int l, int r, int num)
{
    if(segtree[num].l == l && segtree[num].r == r)
    {
        return segtree[num].c;
    }
    if(r <= segtree[num].m)
    {
        return up(l, r, 2 * num);
    }
    else if(l >= segtree[num].m)
    {
        return up(l, r, 2 * num + 1);
    }
    else
    {
        return up(l, segtree[num].m, 2 * num) + \
            up(segtree[num].m,r,2*num+1);
    }
}
*/

void init(int l, int r, int num)
{
    segtree[num].l = l;
    segtree[num].r = r;
    segtree[num].m = (l+r)/2;
    segtree[num].c = r - l;
    if(l+1 != r)
    {
        init(l, segtree[num].m, 2 * num);
        init(segtree[num].m, r , 2 * num + 1);
    }
}

int main()
{
    int n, k, i;
    while(scanf("%d %d", &n, &k) == 2)
    {
        init(1, n+1, 1);
        int p = 0;
        for(i = 1; i <= n; i ++)
        {
            p = (p + k - 1) % segtree[1].c;
            printf("%d ",get(p,1));
        }
        printf("\n ");
    }
    return 0;
}