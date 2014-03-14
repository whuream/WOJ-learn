#include<stdio.h>
#include<math.h>

int main()
{
	int T,N,i,x1,x2,y1,y2,x3,y3;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		fflush(stdin);
		scanf("%d%d%d%d%d",&N,&x1,&y1,&x2,&y2);
		x3=abs(x1-x2);
		y3=abs(y1-y2);
		if((x3-y3)%2==1||(x3-y3)%2==-1) printf("Case %d:\n-1\n\n",i);
		else printf("Case %d:\n%d\n\n",i,x3>y3?x3:y3);
	}
	return 0;
}