#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct student
{int grade;
char* name;
int age;
};
int main()
{
    struct student arr[5];
arr[0].grade=2;
arr[0].name="ahmed";
arr[0].age=15;
arr[1].grade=3;
arr[1].name="mohamed";
arr[1].age=16;
arr[2].grade=4;
arr[2].name="ahmed";
arr[2].age=17;
arr[3].grade=2;
arr[3].name="ahmed";
arr[3].age=15;
arr[4].grade=2;
arr[4].name="ahmed";
arr[4].age=15;

for(int i=0;i<5;i++)
{


printf("Grade=%d\n",arr[i].grade);
printf("Name=%s\n",arr[i].name);
printf("Age=%d\n",arr[i].age);
}

    return 0;

}
