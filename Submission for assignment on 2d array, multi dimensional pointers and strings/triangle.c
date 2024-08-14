#include<stdio.h>
#include<math.h>

void triangle(float a,float b,float c,int *p){
//    float d,e,f;
//    d=a*a;
//    e=b*b;
//    f=c*c;
    if((a+b<=c)||(b+c<=a)||(c+a<=b))
        return;
    else *p=1;
    p++;
    //if(abs(d+e-f)==0||abs(e+f-d)==0||abs(f+d-e)==0)
        //*p=1;
    if(((a*a)+(b*b)==(c*c))||((b*b)+(c*c))==(a*a)||((c*c)+(a*a))==(b*b))
       *p=1;
}

int main()
{
    float a,b,c;
    int n[2]={0,0};

    scanf("%f %f %f",&a,&b,&c);

    triangle(a,b,c,n);

    if(n[0]){
        printf("valid triangle\n");
        if(n[1])
            printf("the triangle has a right angle");
        else
            printf("the triangle does not have a right angle");
    }
    else
        printf("the triangle is not valid");

    return 0;
}
//    if(pow(a,2)+pow(b,2)==pow(c,2)||pow(c,2)+pow(b,2)==pow(a,2)||pow(a,2)+pow(c,2)==pow(b,2))
//        *p=1;
