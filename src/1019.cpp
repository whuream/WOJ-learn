#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<stdio.h>

using namespace std;

int main()
{
	int couse,i,j,k;
	while(scanf("%d",&couse)==1)
	{
		getchar();
		string data;
		vector< vector<string> > table(5,vector<string>(7));

		for(i=0;i<couse;i++)
		{
			getline(cin,data);
			//getchar();
			int place=data.find(':');
			string kecheng(data,0,place);
			if(kecheng.length()%2==0) kecheng.push_back(' ');

			string day(data,place+2,3);

			int num;
			if(day=="MON") num=0;
			else if(day=="TUE") num=1;
			else if(day=="WED") num=2;
			else if(day=="THU") num=3;
			else num=4;

			if(data[place+6]=='M') j=data[place+14]-'0'-1;
			else j=4+data[place+16]-'0'-1;

			table[num][j]=kecheng;
		}


		printf("+-----+-----------+-----------+-----------+-----------+-----------+\n");
		printf("|     |    MON    |    TUE    |    WED    |    THU    |    FRI    |\n");
		printf("+-----+-----------+-----------+-----------+-----------+-----------+\n");
		printf("|                          Morning                                |\n");
		printf("+-----+-----------+-----------+-----------+-----------+-----------+\n");
		for(i=0;i<4;i++)
		{
			printf("|  %d  |",i+1);
			for(j=0;j<5;j++)
			{
				if(0==table[j][i].empty())
				{
					int space=(11-table[j][i].length())/2;
					for(k=0;k<space;k++) printf(" ");
					cout<<table[j][i];
					for(k=0;k<space;k++) printf(" ");
					printf("|");
				}
				else printf("           |");
			}
			printf("\n");
			printf("+-----+-----------+-----------+-----------+-----------+-----------+\n");
		}
		printf("|                         Afternoon                               |\n"); 
		printf("+-----+-----------+-----------+-----------+-----------+-----------+\n");
		for(i=4;i<7;i++)
		{
			printf("|  %d  |",i-3);
			for(j=0;j<5;j++)
			{
				if(0==table[j][i].empty())
				{
					int space=(11-table[j][i].length())/2;
					for(k=0;k<space;k++) printf(" ");
					cout<<table[j][i];
					for(k=0;k<space;k++) printf(" ");
					printf("|");
				}
				else printf("           |");
			}
			printf("\n");
			printf("+-----+-----------+-----------+-----------+-----------+-----------+\n");
		}
		printf("\n");
	}
	return 0;
}