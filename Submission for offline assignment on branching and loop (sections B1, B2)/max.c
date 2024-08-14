#include<stdio.h>

int main()
{

    char ch,c='0';
    int cnt=0;
    while(ch!='\n'){
        scanf("%c",&ch);
        if(ch>c){
            cnt=0;
            c=ch;
        }
        if(ch==c){
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
