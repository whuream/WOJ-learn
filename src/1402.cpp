#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n;
    while(1)
    {
        fflush(stdin);
        scanf("%d",&n);
        if(n==0) return 0;
        if(n<=2) printf("0\n");
        else
        {
            float *a=(float *)malloc(sizeof(float)*n*2);
            int i;
            double sum=0;
         //   fflush(stdin);
            for(i=0;i<n*2;i++)
            {
                scanf("%f",&a[i]);
            }
            for(i=0;i<=n-3;i++)
            {
              // double a1,b,c,d;
              //a1=sqrt((a[0]-a[2*i+2])*(a[0]-a[2*i+2])+(a[1]-a[2*i+3])*(a[1]-a[2*i+3]));
              // b=sqrt((a[0]-a[2*i+4])*(a[0]-a[2*i+4])+(a[0]-a[2*i+5])*(a[0]-a[2*i+5]));
              // c=sqrt((a[2*i+2]-a[2*i+4])*(a[2*i+2]-a[2*i+4])+(a[2*i+3]-a[2*i+5])*(a[2*i+3]-a[2*i+5]));
              // d=(a1+b+c)/2.0;
              // sum+=sqrt(d*(d-a1)*(d-b)*(d-c));
               sum+=fabs((a[0]*a[2*i+3]+a[1]*a[2*i+4]+a[2*i+2]*a[2*i+5]-a[2*i+4]*a[2*i+3]-a[0]*a[2*i+5]-a[1]*a[2*i+2])/2.0);
            }
            printf("%d\n",(int)(sum+0.5));
        }
    }
}
