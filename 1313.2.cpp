#include <iostream>
#include <memory>
#include<cstring>
     
using namespace std;

int Nmin[1000];      // 用以记录的一维数组
     
int KTail( int K )
{
     memset( Nmin, 0, sizeof(Nmin) );    

     long long int num = 1;                         
     bool flag = false;                 // 需要一个标记，用以判断是否>=1000

     /*if ( K>=1000 )
     {
        flag = true;
        K=K%1000;                 
     } */                            
     
     for ( int i = 1; ; ++ i)
     {
         num *= K;               // num = (K^i-1)%1000 * K
         if ( flag || num>=1000 )     // 必须符合题目的条件 K^i>=1000
         {
              flag = true;               // 考虑到有可能之前是false，再赋值
              num = num%1000;

              if ( Nmin[num]==0 )       
                    Nmin[num] = i;
                 else
                       return i + Nmin[num];   
             }
         }
    }
     
    int main()
    {
         int k;
         while(1)
         {
             cin>>k;
			 if(k==0) break;
             cout<<KTail(k)<<endl;
		 }
         return 0;
    }

     