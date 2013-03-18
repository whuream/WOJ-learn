#include<stdio.h>

int main()
{
	int N;
	//while(1)
	{
		long int i=2,A=3,B=6; 
		//scanf("%d",&N);
		//fflush(stdin);
		for(N=0;N<50;N++){
		if(N==-1) break;
		if(N==0) printf("0\n");
		else if(N==1) printf("1\n");
		else if(N==2) printf("3\n");
		else if(N==3) printf("6\n");
		else
		{
			while(N>3*i+1)
			{
				A=4*i-1+B;
				B=7*i+B;
				i*=3;
			}
			if(N==3*i+1) printf("%ld\n",7*i+B);
			else if(N==3*i) printf("%ld\n",4*i-1+B);
			else
			{
				if((N-i)%2==0) printf("%ld\n",A-(N-i)/2);
				else printf("%ld\n",B+(N-i-1)/2);
			}
		}
		}
	}
	return 0;
}