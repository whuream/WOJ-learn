#include<stdio.h>
#include<string.h>

int main()
{
	int N,i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		char a[2005],b[2005];
		char *A,*B;
		fflush(stdin);
		scanf("%s%s",a,b);
		int len_A,len_B;
		int common=0,temp=0;
		if(strlen(a)>strlen(b))
		{
			A=a;
			len_A=strlen(a);
			B=b;
			len_B=strlen(b);
		}
		else
		{
			A=b;
			len_A=strlen(b);
			B=a;
			len_B=strlen(a);
		}

		int k,j;
		for(k=0;k<len_A;k++)
		{
			if(temp>common)
			{
				common=temp;
			}
			temp=0;
			for(j=len_B-1;j>=0;j--)
			{
				if(j+len_A-len_B-k>=0)
				{
					if(B[j]==A[j+len_A-len_B-k])
					{
						temp++;
					}
					else
					{
						if(temp>common)
						{
							common=temp;
						}
						temp=0;
					}
				}
			}
		}
		printf("%d\n",common);
	}
	return 0;
}