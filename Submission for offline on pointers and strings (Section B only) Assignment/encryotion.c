#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,n;
    long long *a;
    char *s;
    scanf("%d",&n);
    s=(char*)malloc(n*sizeof(char));
    scanf(" %[^\n]",s);
    a=s;
    for(i=0;i<n/8;i++){
        printf("%lld\n",*(a+i));
    }

    return 0;
}


