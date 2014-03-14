#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

typedef struct _node
{
	int num;
	int count;
	int pre;
}node;

node data[100010];

int main()
{
	int N;
	while(1)
	{
		scanf("%d",&N);
		if(N==0) break;

		memset(data,-1,sizeof(data));

		int count=0;
		int i;
		for(i=0;i<N;i++)
		{
			int itmp;
			scanf("%d",&itmp);

			itmp--;
			if(data[itmp].pre==-1)
			{
				data[itmp].pre=itmp;
				data[itmp].num=i+1;
				data[itmp].count=1;
				data[itmp+1].pre=itmp;
				if(itmp>count) count=itmp;
			}
			else
			{
				int key=data[itmp].pre;
				while(data[key].pre==key) key+=data[key].count;
				data[key].num=i+1;
				data[key+1].pre=data[key].pre;
				data[data[key].pre].count++;
				if(key>count) count=key;
			}
		}
		
		printf("%d\n",count+1);
		for(i=0;i<count;i++)
		{
			if(data[i].num==-1) data[i].num=0;
			printf("%d ",data[i].num);
		}
		if(data[i].num==-1) data[i].num=0;
		printf("%d\n",data[i].num);
	}
	return 0;
}