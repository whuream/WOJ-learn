/*1:越长的木棍对后面木棍的约束力越大,因此要把小木棍排序,
    按木棍长度从大到小搜索,这样就能在尽可能靠近根的地方
    剪枝。
:当出现加上某根木棍恰好能填满一根原始木棍,但由在后面的
    搜索中失败了,就不必考虑其他木棍了,直接退出当前的枚举。
:考虑每根原始木棍的第一根木棍,如果当前枚举的木棍长度无
    法得出合法解,就不必考虑下一根木棍了，当前木棍一定是作
    为某根原始木棍的第一根木棍的，现在不行,以后也不可能得
    出合法解。也就是说每根原始木棍的第一根小木棍一定要成
    功,否则就返回。
:剩下一个通用的剪枝就是跳过重复长度的木棍，当前木棍跟
    它后面木棍的无法得出合法解，后面跟它一样长度的木棍也
     不可能得到合法解,因为后面相同长度木棍能做到的,前面这
     根木棍也能做到。
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p1,const void*p2)
{
    return *(int*)p2-*(int*)p1;
}
int a[100],v[100];
int n,len,s,tot,min;
bool dfs(int k,int mi,int left)
{
    int i;
    if(left==min) 
        return 1;
    for(i=k;i<=n;i++)
        if(!v[i]&&a[i]<=mi)
        {
            v[i]=1;
            if(a[i]==mi&&dfs(1,len,left-a[i]))
                return 1;
            else if(dfs(i+1,mi-a[i],left-a[i]))
                return 1;
            v[i]=0;
            if(a[i]==min)return 0;
            if(left==tot)return 0;
            if(mi==len)  return 0;
            while(a[i+1]==a[i])
                i++;
        }
    return 0;
}
int main()
{
    int i,res;
    while(scanf("%d",&n),n)
    {
        tot=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            tot+=a[i];
        }
        qsort(a+1,n,sizeof(a[0]),cmp);
        len=a[1];
        res=len;
        memset(v,0,sizeof(v));
        res=tot;
        for(;len<tot;len++)
            if(tot%len==0&&dfs(1,len,tot))
            {
                res=len;
                break;
            }
        printf("%d\n",res);
    }
    return 0;
}