#include<stdio.h>

int main(){
    FILE* fp;
    int a,b;
    fp = fopen("test.txt","r");
    if(fp==NULL){
        printf("error\n");
        exit(1);
    }
    fscanf(fp,"%d %d",&a,&b);
    printf("%d %d",a,b);

    fclose(fp);
    return 0;

}
