#include<iostream>

using namespace std;

int main()
{
    int N,i;
    cin>>N;
    for(i=0;i<N;i++)
    {
        int num;
        cin>>num;
        num%=7;
        if(num<=1) cout<<"Dzs\n";
        else cout<<"Sproblvem\n";
    }
    return 0;
}