/*1:Խ����ľ���Ժ���ľ����Լ����Խ��,���Ҫ��Сľ������,
    ��ľ�����ȴӴ�С����,���������ھ����ܿ������ĵط�
    ��֦��
:�����ּ���ĳ��ľ��ǡ��������һ��ԭʼľ��,�����ں����
    ������ʧ����,�Ͳ��ؿ�������ľ����,ֱ���˳���ǰ��ö�١�
:����ÿ��ԭʼľ���ĵ�һ��ľ��,�����ǰö�ٵ�ľ��������
    ���ó��Ϸ���,�Ͳ��ؿ�����һ��ľ���ˣ���ǰľ��һ������
    Ϊĳ��ԭʼľ���ĵ�һ��ľ���ģ����ڲ���,�Ժ�Ҳ�����ܵ�
    ���Ϸ��⡣Ҳ����˵ÿ��ԭʼľ���ĵ�һ��Сľ��һ��Ҫ��
    ��,����ͷ��ء�
:ʣ��һ��ͨ�õļ�֦���������ظ����ȵ�ľ������ǰľ����
    ������ľ�����޷��ó��Ϸ��⣬�������һ�����ȵ�ľ��Ҳ
     �����ܵõ��Ϸ���,��Ϊ������ͬ����ľ����������,ǰ����
     ��ľ��Ҳ��������
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