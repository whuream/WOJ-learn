#include<stdio.h>
#include<stdlib.h>


void soft(int candy[],int low,int high)
{
	int i=low,j=2*i;
	int temp=candy[i];
	while(j<=high)
	{
		if(j<high&&candy[j]>candy[j+1])
		{
			j++;
		}

		if(temp>candy[j])
		{
			candy[i]=candy[j];
			i=j;
			j=2*i;
		}
		else break;
	}
	candy[i]=temp;
}



int main()
{
	int N,K;
	while(scanf("%ld %ld",&N,&K)==2)
	{
		int *candy,tmp,count=0,pre=-1;
		candy=(int *)malloc(sizeof(int)*N+1);


		int i,j;
		for(i=1;i<=N;i++)
		{
			scanf("%ld",&candy[i]);
		}


		for(i=N/2;i>=1;i--)
			soft(candy,i,N);


		for(i=N;i>=2;i--)
		{
			tmp=candy[1];
			candy[1]=candy[i];
			candy[i]=tmp;


			//if(tmp!=pre)
			{
				count++;
				pre=tmp;
				if(count==K)
				{
					printf("%ld\n",tmp);
					break;
				}
			}

			soft(candy,1,i-1);
		}
	}
	return 0;
}