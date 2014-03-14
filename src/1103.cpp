#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
   // printf("n=%d\n",n);
    int *a;
    a=(int *)malloc(sizeof(int)*n);
   // printf("n=%d\n",n);
    float *b;
    b=(float *)malloc(sizeof(float)*n);
   // printf("n=%d\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%%",&a[i]);
       // printf("n=%d\n",n);
       // printf("%d\n",a[i]);
        if(a[i]==100) b[i]=1.0;
        else b[i]=a[i]*a[i]*1.0/(10000.0-2.0*a[i]*100+2.0*a[i]*a[i]);
        //printf("%d\n",a[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%.2f%%\n",b[i]*100);
    }
    return 0;
}
