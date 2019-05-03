#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
#include"inttypes.h"
#include "strings.h"



/*int SortArr(int i)
{
    int  j , temp , swapped ;


    while(1)
    {
        swapped =0;
        for (j=0;j<(i-1);j++)
        {
            temp = Arr[i];
            Arr[i]=Arr[i+1];
            Arr[i+1]=temp;
            swapped =1;
        }
    if (swapped==0)
    break;

    }
    return 0;

}*/



/*int Sorting()
        int i, j, a, n, number[30];
        printf("Enter the value of N \n");
        scanf("%d",&n);

        printf("Enter the numbers \n");
        for (i = 0; i < n; ++i)
            scanf("%d", &number[i]);

        for (i = 0; i < n; ++i)
        {

            for (j = i + 1; j < n; ++j)
            {

                if (number[i] > number[j])
                {

                    a =  number[i];
                    number[i] = number[j];
                    number[j] = a;

                }

            }

        }

        printf("The numbers arranged in ascending order are given below \n");
        for (i = 0; i < n; ++i)
            printf("%d\n", number[i]);
return 0;
    }*/


    int  BubbleSort(int n )
{
    int i,j,a[100],temp;

    printf("Enter the number of elements:\n") ;
    scanf("%d",&n) ;

    printf("Enter the elements\n") ;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]) ;
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }


    printf("Elements sorted in ascending order are\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]) ;
    }

    return 0;
    }





