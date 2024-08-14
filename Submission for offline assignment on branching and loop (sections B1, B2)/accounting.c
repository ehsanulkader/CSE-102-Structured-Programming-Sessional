#include<stdio.h>
int main()
{
    int n;
    double sum=0;
    scanf("%d",&n);
    if(n>200){
        sum+=(n-200)*1.2;
        n=200;
    }
    if(n>100){
        sum+=(n-100)*0.8;
        n=100;
    }
    sum+=n*0.5;
    printf("%lf",sum);
    return 0;
}
