#include<iostream>
#include<vector>

using namespace std;

vector< vector< vector<int> > > W(21,vector< vector<int> >(21,vector<int>(21,-1)));

int find(int a,int b,int c)
{
    if(W[a][b][c]!=-1) return W[a][b][c];
    else if(a<=0||b<=0||c<=0) W[a][b][c]=1;
    else if(a>20||b>20||c>20) W[a][b][c]=find(20,20,20);
    else if(a<b&&b<c) W[a][b][c]=find(a,b,c-1)+find(a,b-1,c-1)-find(a,b-1,c);
    else W[a][b][c]=find(a-1,b,c)+find(a-1,b-1,c)+find(a-1,b,c-1)-find(a-1,b-1,c-1);
    return W[a][b][c];
}

int main()
{
    int N,i;
    cin>>N;
    for(i=0;i<N;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int a1=a,b1=b,c1=c;
        if(a<=0||b<=0||c<=0)
        {
            a=0;
            b=0;
            c=0;
        }
        else if(a>20||b>20||c>20)
        {
            a=20;
            b=20;
            c=20;
        }
        cout<<"W("<<a1<<", "<<b1<<", "<<c1<<") = "<<find(a,b,c)<<endl;
    }
    return 0;
}