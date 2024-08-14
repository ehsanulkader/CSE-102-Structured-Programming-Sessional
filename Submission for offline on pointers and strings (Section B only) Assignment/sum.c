#include<stdio.h>
#include<stdlib.h>

int main()
{

    int i,b[10001],odd=0,even=0,n;
    int *a;

    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        scanf("%d",a);
        if(i%2==0)
            even=even+*a;
        else
            odd=odd+*a;
        a++;
    }

    if(even>odd)
        printf("Even index sum is greater");
    else{
        if(odd>even)
            printf("Odd index sum is greater");
        else
            printf("Equal");
    }

    return 0;
}

