#include <stdio.h>
#include <stdlib.h>

int main()
{
	char name[20];
	signed int grade;
	signed int IF_OR_SWITCH = 0;
	signed int operation = 0;


do{
			system("CLS");

			printf("This program evaluates whether a student passed the exams or not , and print his name and grade \n\n");
			printf("Please choose a method : 1) If Else      2) Switch Case  \n\n");

			scanf(" %d", &IF_OR_SWITCH);

			if (IF_OR_SWITCH == 1)
			{

				do {

					printf("\nEnter student's name :    ");
					scanf("%s", &name, sizeof(name));


					printf("\nEnter student's marks :  ");
					scanf(" %d", &grade);


					if (grade < 50)
					{
						printf("\nName : %s\t grade : Fail" ,name);
					}
					else if (grade >=50 && grade < 60)
					{
						printf("\nName : %s\t grade : Pass",name);
					}
					else if (grade >= 60 && grade < 70)
					{
						printf("\nName : %s\t grade : Good",name);
					}
					else if (grade >= 70 && grade < 80)
					{
						printf("\nName : %s\t grade : Very good",name);
					}
					else if (grade >= 80 && grade <= 100)
					{
						printf("\nName : %s\t grade : Excellent",name);
					}
					else
					{
						printf("\nUnexpected values please try again\n");
					}
				} while ((grade < 0) || (grade > 100));
			}


			else if (IF_OR_SWITCH == 2)
			{

				do {

					printf("\nEnter student's name :    ");
					scanf("%s", &name, sizeof(name));


					printf("\nEnter student's marks :  ");
					scanf("%d", &grade);



					switch (grade)
					{

					case 0 ... 49:
						printf("\nName : %s\t grade : Fail",name);
						break;

					case 50 ... 59:
						printf("\nName : %s\t grade : Pass",name);
						break;

					case 60 ... 69:
						printf("\nName : %s\t grade : Good",name);
						break;

					case 70 ... 79:
						printf("\nName : %s\t grade : Very good",name);
						break;

					case 80 ... 100:
						printf("\nName : %s\t grade : Excellent",name);
						break;

					default:
						printf("\nUnexpected values please try again\n");
					}
				} while ((grade < 0) || (grade > 100));
			}


			else
			{
				printf("\n\nWrong choice please choose a right operation \n");
			}





		do {
			printf("\n\nDo you want to enter another name ?  1) Yes    2)No \n");
			scanf(" %d", &operation);

            if (operation ==1)
            {
                break;
            }

			else if (operation == 2)
            {
               return 0;
            }
            else
            {
                printf("\n\nWrong choice please choose a right option \n");
            }
		} while (operation!=1 || operation !=2);


}while (operation !=2);


	return 0;
}


