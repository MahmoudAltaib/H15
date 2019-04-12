#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Grade=0;
    printf("Enter Grade:\n");
    scanf("%d",&Grade);
    switch (Grade)
    {
        case(0)...(49):
           printf("Fail:\n");
           break;
        case(50)...(59):
           printf("Pass:\n");
           break;
        case(60)...(69):
            printf("Good:\n");
            break;
        case(70)...(84):
            printf("VeryGood:\n");
            break;
        case(85)...(100):
            printf("Excellent:\n");
            break;


    }
    return 0;
}
