#include<stdio.h>
#include<math.h>

int main()
{
	int D,H;
	double a,b,c,h;
	double pie=3.141592653589793;

	scanf("%d %d",&D,&H);

	while(1)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		if(a<0.0001) break;

		a=1/tan(a/180*pie);
		b=1/tan(b/180*pie);
		c=1/tan(c/180*pie);
		h=sqrt(2*D*D/(a*a-2*b*b+c*c))+H;
		printf("%d\n",int(h+0.5000));
	}
	return 0;
}