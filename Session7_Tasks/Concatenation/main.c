#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t u32Get_length(char c8Str[100]);
void c8Conc(char c8Str1[100],char c8Str2[100],char (*c8Conc_string)[100] );

int main()
{
    uint32_t u32Operation = 0;
    char c8String1[100] = {0};
    char c8String2[100] = {0};
    char c8Conc_string[100] = {0};

do{

    u32Operation = 0;

    printf("Enter  string1  :   ");
    scanf("%s",c8String1);

     printf("\nEnter  string2  :   ");
    scanf("%s",c8String2);


    c8Conc(c8String1,c8String2,&c8Conc_string);

    printf("string1 is %s       and string2 is %s   \n",c8String1,c8String2);
    printf("The concatenated string is   %s     \n",c8Conc_string);

    printf("\n\nDo you want to continue ? 1) Yes    2) No  \n");
    scanf("%d",&u32Operation);

  }while (u32Operation != 2);

    return 0;
}

uint32_t u32Get_length(char c8Str[100])
{

    uint32_t u32Checker = 0;
    uint32_t u32Num_of_bytes = 0;

    for (u32Checker =0;u32Checker<100;u32Checker ++)
    {
        if (c8Str[u32Checker] != '0') /*   The 0 means Null in ASCII code */
        {
            u32Num_of_bytes ++;
        }
        else
        {
            return u32Num_of_bytes ;
        }
    }
    return u32Num_of_bytes;
}

void c8Conc(char c8Str1[100],char c8Str2[100],char (*c8Conc_string)[100] )
{
    uint32_t u32Size_str1 = 0;
    uint32_t u32Size_str2 = 0;
    uint32_t u32Conc_element = 0;
    uint32_t u32Conc_repeat = 0;

    uint32_t (*pfu32Get_length)(char c8Str[100]);

    pfu32Get_length = &u32Get_length ;

    u32Size_str1 = (*pfu32Get_length)(c8Str1);
    u32Size_str2 = (*pfu32Get_length)(c8Str2);

    for (u32Conc_repeat = 0;u32Conc_repeat<u32Size_str1;u32Conc_repeat++)
    {
        (*c8Conc_string)[u32Conc_element] = c8Str1[u32Conc_repeat];
        u32Conc_element ++;
    }

printf("%d",u32Conc_element);

    for (u32Conc_repeat = 0;u32Conc_repeat<u32Size_str2;u32Conc_repeat++)
    {
        (*c8Conc_string)[u32Conc_element] = c8Str2[u32Conc_repeat];
        u32Conc_element ++;
    }
printf("%d",u32Conc_element);
}


