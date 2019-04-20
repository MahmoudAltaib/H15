#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t u32Get_length(char c8Str[100]);
void c8Copy(char c8Str1[100],char (*c8Str2)[100]);

int main()
{
    uint32_t u32Operation = 0;
    char c8String1[100] = {0};
    char c8String2[100] = {0};

do{

    u32Operation = 0;

    printf("Enter  string1  :   ");
    scanf("%s", c8String1);

    c8Copy(c8String1,&c8String2);

    printf("The original string is %s     \n",c8String1);
    printf("The cloned string is %s     \n",c8String2);


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

void c8Copy(char c8Str1[100],char (*c8Str2)[100])
{
    uint32_t u32Size_of_cloned_string = 0;
    uint32_t u32Copy_sequence = 0;

    uint32_t (*pfu32Get_length)(char c8Str[100]);

    pfu32Get_length = &u32Get_length ;

    u32Size_of_cloned_string = (*pfu32Get_length)(c8Str1);

    for (u32Copy_sequence = 0;u32Copy_sequence <u32Size_of_cloned_string;u32Copy_sequence++)
    {
        (*c8Str2)[u32Copy_sequence] = c8Str1[u32Copy_sequence];
    }


}

