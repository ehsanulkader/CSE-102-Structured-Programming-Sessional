#include<stdio.h>
#include<string.h>

int main()
{
    char s1[1000],s2[1000];
    int n1,n2,i,j=0,k,c=0;

    scanf("%[^\n]s",s1);
    scanf(" %[^\n]s",s2);

    n1=strlen(s1);
    n2=strlen(s2);

    for(i=0;i<n1;i++){
        k=i;
        j=0;
        while(s1[k]==s2[j]){
            j++;
            k++;
            if(j==n2){
                c++;
                break;
            }
        }

    }
    printf("%d",c);

    return 0;
}

