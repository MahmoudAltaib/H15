#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define Num_of_rows 3
#define Num_of_columns 3

int main()
{

    uint32_t u32Arr1[Num_of_rows][Num_of_columns] = {0};
    uint32_t u32Arr2[Num_of_rows][Num_of_columns] = {0};
    uint32_t u32Arr[Num_of_rows][Num_of_columns] = {0};

    uint32_t u32Repeat_row = 0;
    uint32_t u32Repeat_column = 0;
    uint32_t u32Repeat_operation = 0;
    uint32_t u32Mul_aid = 0;

do{
        /* Entering the first matrix */
    for (u32Repeat_row = 0; u32Repeat_row < Num_of_rows ; u32Repeat_row++)
    {
        for (u32Repeat_column = 0; u32Repeat_column < Num_of_columns ; u32Repeat_column++)
        {
            printf("Enter the element number %d   in Row   %d    in matrix 1  :     ",u32Repeat_column,u32Repeat_row);
            scanf("%d",&u32Arr1[u32Repeat_row][u32Repeat_column]);
        }
    }

    /* Printing the array values */

     printf("Matrix 1 =  \n ");

    for (u32Repeat_row =0;u32Repeat_row < Num_of_rows;u32Repeat_row++)
    {
        for (u32Repeat_column = 0;u32Repeat_column < Num_of_columns;u32Repeat_column++)
        {
            printf("          %d\t",u32Arr1[u32Repeat_row][u32Repeat_column]);
        }
        printf("  \n");

    }
        /*Entering the second matrix */


         for (u32Repeat_row = 0; u32Repeat_row < Num_of_rows ; u32Repeat_row++)
    {
        for (u32Repeat_column = 0; u32Repeat_column < Num_of_columns ; u32Repeat_column++)
        {
            printf("Enter the element number %d   in Row   %d     in matrix  2 :     ",u32Repeat_column,u32Repeat_row);
            scanf("%d",&u32Arr2[u32Repeat_row][u32Repeat_column]);
        }
    }

    /* Printing the second matrix */

     printf("Matrix 2 =  \n ");

    for (u32Repeat_row =0;u32Repeat_row < Num_of_rows;u32Repeat_row++)
    {
        for (u32Repeat_column = 0;u32Repeat_column < Num_of_columns;u32Repeat_column++)
        {
            printf("          %d\t",u32Arr2[u32Repeat_row][u32Repeat_column]);
        }
        printf("  \n");
    }

    /* Performing multiplication process on mat1 and mat2*/

    for (u32Mul_aid = 0; u32Mul_aid < 3; u32Mul_aid++)
    {
        u32Arr[0][u32Mul_aid] = u32Arr1[0][0] * u32Arr2[0][u32Mul_aid] + u32Arr1[0][1] * u32Arr2[1][u32Mul_aid] + u32Arr1[0][2] * u32Arr2[2][u32Mul_aid];
    }

    for (u32Mul_aid = 0; u32Mul_aid < 3; u32Mul_aid++)
    {
        u32Arr[1][u32Mul_aid] = u32Arr1[1][0] * u32Arr2[0][u32Mul_aid] + u32Arr1[1][1] * u32Arr2[1][u32Mul_aid] + u32Arr1[1][2] * u32Arr2[2][u32Mul_aid];
    }

    for (u32Mul_aid = 0; u32Mul_aid < 3; u32Mul_aid++)
    {
        u32Arr[2][u32Mul_aid] = u32Arr1[2][0] * u32Arr2[0][u32Mul_aid] + u32Arr1[2][1] * u32Arr2[1][u32Mul_aid] + u32Arr1[2][2] * u32Arr2[2][u32Mul_aid];
    }


    /* Printing the result */

      printf("The result of M1* M2 =   \n ");

    for (u32Repeat_row =0;u32Repeat_row < Num_of_rows;u32Repeat_row++)
    {
        for (u32Repeat_column = 0;u32Repeat_column < Num_of_columns;u32Repeat_column++)
        {
            printf("          %d\t",u32Arr[u32Repeat_row][u32Repeat_column]);
        }
        printf("  \n");
    }



    printf("\n\nDo you want to enter another matrix    ?   1) Yes      2) No     \n");
    scanf("%d",&u32Repeat_operation);

  }while(u32Repeat_operation !=2);
    return 0;
}
