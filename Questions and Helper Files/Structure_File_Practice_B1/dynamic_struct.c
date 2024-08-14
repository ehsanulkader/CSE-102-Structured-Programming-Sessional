#include <stdio.h>
#include <stdlib.h>

struct studentInfo {
    char name[80];
    int roll;
    int age;
    unsigned is_enrolled :1;
    unsigned is_resident :1;
};

struct studentGrades{
    struct studentInfo info;
    float marks[3];
};

enum {bangla, english, math};
//enum subject SUBJECT;

typedef struct studentGrades grade;

void printName(grade *p)
{
    printf("%s\n",p->info.name);
}

int main()
{
    int n;
    scanf("%d",&n);

    grade *S = (grade*)
    malloc(sizeof(grade)*n);

    int i;

    for(i=0;i<n;i++)
    {
        //input info
        printf("Enter Info for student %d: \n",(i+1));

        printf("Name: ");
        scanf("%s",S[i].info.name);
        printf("Roll: ");
        scanf("%d",&S[i].info.roll);
        printf("Age: ");
        scanf("%d",&S[i].info.age);

        //input marks:
        printf("Marks in Bangla: ");
        scanf("%f",&S[i].marks[bangla]);
        printf("Marks in English: ");
        scanf("%f",&S[i].marks[english]);
        printf("Marks in Math: ");
        scanf("%f",&S[i].marks[math]);

        printName(&S[i]);
    }

    float max_marks = S[0].marks[math];
    int max_index = 0;

    for(i=1;i<n;i++)
    {
        if(S[i].marks[math]>max_marks)
        {
            max_marks = S[i].marks[math];
            max_index = i;
        }
    }

    printf("Roll of highest marks in math: %d\n",S[max_index].info.roll);

    return 0;
}
