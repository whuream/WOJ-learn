#include<stdio.h>
#include<math.h>


/*
			草，坐标竟然会上端溢出！！！！！！！！！！！！！！尼玛，坑爹的家伙！！！！！！
*/


int main()
{
	int N,i;
	long long int x1,x2,x3,y1,y2,y3;
	double a,b,c,answer,cos_b;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%lld %lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&x3,&y3);
		a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
		c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		cos_b=(a*a+c*c-b*b)/(2.0*a*c);
		answer=2*a*c*(1-cos_b*cos_b)/b;
		printf("%.3f\n",answer);
	}
	return 0;
}