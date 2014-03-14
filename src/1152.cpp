#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;

int main()
{
    int N,K;
    while(cin>>N>>K)
    {
        vector<int> data;
        for(int i=0;i<N;i++)
        {
            int p;
            scanf("%d",&p);
            data.push_back(p);
        }
        sort(data.begin(),data.end());
        vector<int>::iterator pointer=data.begin();
        for(int i=0;i<K-1;i++) pointer++;
        cout<<*pointer<<endl;
    }
    return 0;
}