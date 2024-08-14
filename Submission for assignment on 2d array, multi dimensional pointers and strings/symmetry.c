#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,c=0;
    int **a=NULL;

    scanf("%d",&n);

    a=(int**)malloc(n*sizeof(int*));

    for(i=0;i<n;i++){
        a[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j]==a[j][i])
                c++;
        }
    }

    if (c==(n*n))
        printf("YES");
    else printf("NO");
    free(a);
    return 0;
}

