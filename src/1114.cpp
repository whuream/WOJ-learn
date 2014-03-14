#include<stdio.h>

typedef struct
{
    double x,y;
    long double dis;
    int socer;
}cell;

int main()
{
    cell a[6];
    int i;
    while(scanf("%lf%lf",&a[0].x,&a[0].y)==2)
    {
        if(a[0].x==-100) break;
        a[0].dis=a[0].x*a[0].x+a[0].y*a[0].y;
        //printf("\n%llf\n",a[0].dis);
        if(0.00000<=a[0].dis&&a[0].dis<=9.00000) a[0].socer=100;
        else if(9.00000<a[0].dis&&a[0].dis<=36.00000) a[0].socer=80;
        else if(36.00000<a[0].dis&&a[0].dis<=81.00000) a[0].socer=60;
        else if(81.00000<a[0].dis&&a[0].dis<=144.00000) a[0].socer=40;
        else if(144.00000<a[0].dis&&a[0].dis<=225.00000) a[0].socer=20;
        else    a[0].socer=0;
        for(i=1;i<6;i++)
        {
            scanf("%lf%lf",&a[i].x,&a[i].y);
        a[i].dis=a[i].x*a[i].x+a[i].y*a[i].y;
        if(0.0<=a[i].dis&&a[i].dis<=9.0) a[i].socer=100;
        else if(9.0<a[i].dis&&a[i].dis<=36.0) a[i].socer=80;
        else if(36.0<a[i].dis&&a[i].dis<=81.0) a[i].socer=60;
        else if(81.0<a[i].dis&&a[i].dis<=144.0) a[i].socer=40;
        else if(144.0<a[i].dis&&a[i].dis<=225.0) a[i].socer=20;
        else    a[i].socer=0;
        }
        printf("SCORE: %d to %d, ",a[0].socer+a[1].socer+a[2].socer,a[3].socer+a[4].socer+a[5].socer);
        if(a[0].socer+a[1].socer+a[2].socer==a[3].socer+a[4].socer+a[5].socer) printf("TIE.");
        else if(a[0].socer+a[1].socer+a[2].socer>a[3].socer+a[4].socer+a[5].socer) printf("PLAYER 1 WINS.");
        else printf("PLAYER 2 WINS.");
        printf("\n");
    }
    return 0;
}
