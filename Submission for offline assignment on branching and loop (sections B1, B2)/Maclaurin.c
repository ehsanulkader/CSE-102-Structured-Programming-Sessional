#include<stdio.h>
int main()

{
    double x,a=1,sum=1,pi=3.141592653;
    int i,b;
    scanf("%d",&b);
    b=b%360;
    x=b*pi/180.0;

    for(i=1;i<100;i++){
        a=(a*-x*x)/((2*i-1)*(2*i));
        sum=sum+a;
    }
    printf("%0.6lf",sum);
    return 0;
}

