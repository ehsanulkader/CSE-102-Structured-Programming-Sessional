#include<stdio.h>
int main()

{
    int n,a=0,b,c,temp,i;

    scanf("%d",&n);

    for(i=1;i<n;i++){
        b=n;
        c=i;
        while(c!=0){
            temp=b%c;
            b=c;
            c=temp;
        }
        if(b==1){
            a++;
        }
    }
    printf("%d",a);

    return 0;
}
