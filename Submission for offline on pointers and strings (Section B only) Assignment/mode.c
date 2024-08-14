#include<stdio.h>
#include<stdlib.h>

int main()
{

    int b,i,cnt=0,k=-1,n;
    int *a;
    scanf("%d",&n);
    a=(int*)malloc(10001*sizeof(int));
    for(i=0;i<=10000;i++)
        *(a+i)=0;
    for(i=0;i<n;i++){
        scanf("%d",&b);
        (*(a+b))++;
        if(*(a+b)>=cnt){
            cnt=*(a+b);
            if(b>k)
                k=b;
        }
    }
    for(i=0;i<=k;i++){
        if(*(a+i)==cnt)
            printf("%d ",i);
    }
    return 0;
}
