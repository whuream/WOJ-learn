#include<stdio.h>
#include<math.h>
#define PAI 3.1415926
int main()
{
    int d,h;
    scanf("%d%d",&d,&h);
    while(1)
    {
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        if(a<=0||b<=0||c<=0) break;
        if(a<b&&a<c) printf("%f",h+d*tan(a/180.0*PAI)*tan(b/180*PAI)/(tan(b/180*PAI)-tan(a/180*PAI)));
        if(a==c) printf("%f",h+d*tan(a/180*PAI));
        if(c<a&&c<b) printf("%f",h+d*tan(c/180*PAI)*tan(b/180*PAI)/(tan(b/180*PAI)-tan(c/180*PAI)));
        printf("\n");
    }
    return 0;
}
