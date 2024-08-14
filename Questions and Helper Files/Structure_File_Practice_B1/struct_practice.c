#include <stdio.h>
#include <stdlib.h>

struct studentInfo {
    char name[80];
    int roll;
    int age;
};

struct studentGrades{
    struct studentInfo info;
    float marks[3];
};

enum {bangla, english, math};
//enum subject SUBJECT;

int main()
{
    struct studentGrades S[3];
    int i;

    for(i=0;i<3;i++)
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
    }

    float max_marks = S[0].marks[math];
    int max_index = 0;

    for(i=1;i<3;i++)
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
