#include<stdio.h>
int main()
{
    int n,i,j,sum=1,k,l=2,a;
    scanf("%d",&n);
    printf("1");
    if(n>1){
        for(i=2;i<=n;i++){
            printf("+(");
            for(j=0;j<i;j++){
                if(j==0){
                    printf("%d+",l);
                    sum=sum+l;
                    l++;
                }
                else{
                    a=1;
                    for(k=0;k<=j;k++){
                        printf("%d*",l);
                        a=a*l;
                        l++;
                    }
                    printf("\b+");
                    sum=sum+a;
                }

            }
            printf("\b)");
        }


    }

    printf("=%d",sum);
    return 0;
}
