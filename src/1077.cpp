#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

template<class T> T mmax(T a,T b){return a>b?a:b;}
template<class T> T mmin(T a,T b){return a<b?a:b;}
template<class T> T mabs(T a){return a>0?a:-a;}

#define MIMAX 0x7fffffff
#define MIMIN 0xffffffff

int main()
{
    string data;
    while(cin>>data)
    {
        mint d(data.length(),vector<int>(data.length()));

        int i;
        for(i=0;i<data.length();i++) d[i][i]=1;
        int j;

        int len;
        for(len=1;len<data.length();len++)
        {
            for(i=0;i<data.length();i++)
            {
                if(len+i>=data.length()) break;
                int t;
                if((data[i]=='(' && data[i+len]==')') || (data[i]=='{' && data[i+len]=='}') || (data[i]=='[' && data[i+len]==']') || (data[i]=='<' && data[i+len]=='>'))
                    t=d[i+1][i+len-1];
                else t=d[i+1][i+len-1]+2;

                for(j=i;j<i+len;j++) if(d[i][j]+d[j+1][i+len]<t) t=d[i][j]+d[j+1][i+len];
                d[i][i+len]=t;
            }
        }
        printf("%d\n",d[0][data.length()-1]);
    }
    return 0;
}