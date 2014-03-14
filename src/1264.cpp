#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<int> > mint;

template<class T> T mmax(T a,T b){return a>b?a:b;}
template<class T> T mmin(T a,T b){return a<b?a:b;}
template<class T> T mabs(T a){return a>0?a:-a;}

#define MIMAX 0x7fffffff
#define MIMIN 0xffffffff
#define ZERO 1e-7

int main()
{
	string wek[7]={"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	int rund[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	int day;
	while(scanf("%d",&day)==1)
	{
		if(day==-1) break;

		int dayc=day;
		int y400=100*366+300*365-3;
		int y100a=25*366+75*365;
		int y100b=25*366+75*365-1;
		
		int y4a=4*365+1;
		int y4b=4*365;
		
		int addy=0;

		int tmp;
		tmp=day/y400;
		addy+=tmp*400;

		day%=y400;

		bool isy100=true;
		if(day>=y100a)
		{
			day-=y100a;
			addy+=100;
			isy100=false;
		
			tmp=day/y100b;
			addy+=tmp*100;
			day%=y100b;
		}

		bool isy4=true;
		if(isy100==true)
		{
			if(day>=y4a)
			{
				tmp=day/y4a;
				addy+=tmp*4;
				day%=y4a;
			}
		}
		else
		{
			if(day>=y4b)
			{
				day-=y4b;
				addy+=4;
				isy4=false;

				tmp=day/y4a;
				addy+=tmp*4;
				day%=y4a;
			}
		}

		bool isrun;
		if(isy100==false && isy4==true)
		{
			tmp=day/365;
			addy+=tmp;
			day%=365;
			isrun=false;
		}
		else
		{
			if(day<366) isrun=true;
			else
			{
				day-=366;
				addy++;

				tmp=day/365;
				addy+=tmp;
				day%=365;
				isrun=false;
			}
		}
		day++;
		if(isrun==false) rund[1]=28;
		else rund[1]=29;
		int i;
		for(i=0;i<12;i++)
		{
			if(day<=rund[i]) break;
			else
			{
				day-=rund[i];
			}
		}
		int m=i+1;
		int d=day;
		addy+=2000;
		printf("%d-%02d-%02d ",addy,m,d);
		cout<<wek[dayc%7]<<endl;

	}
	return 0;
}