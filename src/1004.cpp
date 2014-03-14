#include<stdio.h>
#include<string.h>

int main()
{
	double length,width,height;
	char c[3][20];
	char d[][20]={"meters","centimeters","inches","cubits","feet"};
	double rate[]={1.0,0.01,45.72/18/100,0.4572,13.716/45};
	while(scanf("%lf",&length)==1)
	{
		scanf("%s",c[0]);
		fflush(stdin);
		scanf("%lf %s",&width,c[1]);
		fflush(stdin);
		scanf("%lf %s",&height,c[2]);
		int i;
		for(i=0;i<5;i++)
		{
			if(!strcmp(c[0],d[i]))
			{
				//printf("aaaaaaa@@@\n");
				length*=rate[i];
				break;
			}
		}
		for(i=0;i<5;i++)
		{
			if(!strcmp(c[1],d[i]))
			{
				width*=rate[i];
				break;
			}
		}
		for(i=0;i<5;i++)
		{
			if(!strcmp(c[2],d[i]))
			{
				height*=rate[i];
				break;
			}
		}
		if(length-width<0.00000001&&length-width>-0.00000001)
		{
			printf("Spin\n\n");
		}
		else if(length-width*6<0.00000001&&length-width*6>-0.00000001)
		{
			printf("Excellent\n\n");
		}
		else printf("Neither\n\n");
		getchar();
	}
	return 0;

}