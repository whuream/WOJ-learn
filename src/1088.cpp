#include<stdio.h>
#include<math.h>

int Cab(int low,int up)
{
	int i,ans=1;
	for(i=low;i>=low-up+1;i--) ans*=i;
	for(i=up;i>=2;i--) ans/=i;
	return ans;
}


long double Cnn(int n,int m,long double *tmp)
{
	if(m==0) 
	{
		if(tmp[m]==0)
		{
			tmp[m]=(long double)(n);
		}
		return tmp[m];
	}
	else if(m==1) 
	{
		if(tmp[m]==0)
		{
			tmp[m]=(long double)(n)*(n+1)/2;
		}
		return tmp[m];
	}
	else if(m==2) 
	{
		if(tmp[m]==0)
		{
			tmp[m]=(long double)(n)*(n+1)*(2*n+1)/6;
		}
		return tmp[m];
	}
	else if(m==3) 
	{
		if(tmp[m]==0)
		{
			tmp[m]=pow((long double)(n)*(n+1),2)/4;
		}
		return tmp[m];
	}
	else if(m==4)
	{
		if(tmp[m]==0)
		{
			tmp[m]=(long double)(n)*(n+1)*(2*n+1)*(3*n*n+3*n-1)/30;
		}
		return tmp[m];
	}
	else
	{
		tmp[m]=pow(long double(n+1),m+1)-1;
		int i;
		for(i=0;i<=m-1;i++)
		{
			if(tmp[i]==0)
			{
				tmp[i]=Cnn(n,i,tmp);
			}
			tmp[m]=tmp[m]-Cab(m+1,i)*tmp[i];
		}
		tmp[m]/=Cab(m+1,m);
		return tmp[m];
	}

}

int main()
{
	int N,M;
	while(scanf("%d%d",&N,&M)==2)
	{
		long double tmp[21]={0};
		printf("%.2e\n",Cnn(N,M,tmp));
		//printf("%.2e\n",pow(7.0,20));
	}
	return 0;
}