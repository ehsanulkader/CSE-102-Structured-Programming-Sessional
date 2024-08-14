#include<stdio.h>

void biggest_digit(int n){
    int i,j=0;
    for(;n!=0;){
        i=n%10;
        if(i>j)
            j=i;
        n=n/10;
    }
    printf("%d",j);
}

int main()
{
    int a;
    scanf("%d",&a);
    biggest_digit(a);

    return 0;
}



