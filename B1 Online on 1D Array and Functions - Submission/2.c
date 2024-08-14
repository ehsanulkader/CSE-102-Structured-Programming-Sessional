#include<stdio.h>
int a[1000000],b[102],n,i,c,m;

int main()
{
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    c=0;
    for(i=0;i<=100;i++){
        if(b[i]>c){
            c=b[i];
            m=i;
        }

    }
    printf("%d",m);
    return 0;
}

