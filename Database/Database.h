#ifndef Database
#define Database

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#define DATABASE_LIMIT 10
#define NUMBER_OF_ELEMENTS 10

typedef struct StudentDB
{
    char cStudent_ID[NUMBER_OF_ELEMENTS];

    uint32_t u32Year_of_study ;

    unsigned char ucCourse1_ID[NUMBER_OF_ELEMENTS];
    uint32_t u32Course1_grade ;

    unsigned char ucCourse2_ID[NUMBER_OF_ELEMENTS];
    uint32_t u32Course2_grade ;

    struct StudentDB *pNext ;

}Member;

enum Operation
{
    OP1 = 1,
    OP2,
    OP3,
    OP4,
    OP5,
    OP6,
    OP7,
    OP8,
    OP9,
    OP10,
    OP11,
    OP12,
    OP13,
    OP14
};

extern uint32_t Create_DB(Member *pElement );
extern void Print_DB(void);
extern uint32_t Get_student_info(Member *pElement);
extern uint8_t Add_tail_member (Member *pElement);
extern uint8_t Add_head_member (Member *pElement);
extern uint8_t Add_member_by_index(Member *pElement , uint32_t u32Index);
extern uint8_t Delete_head_member (void);
extern uint8_t Delete_tail_member (void);
extern void Print_length_of_database (void);
extern uint8_t Delete_member_by_index (uint32_t u32Index);
extern uint8_t Is_DB_full(void);
extern uint8_t Delete_member_by_ID( char cID[NUMBER_OF_ELEMENTS]);
extern void Search_ID (char *pcID);
extern void Print_member(uint32_t u32Index);
extern void Swap(Member *pu32Element1,Member *pu32Element2);
extern void Sort_DB_grade1_ascend(void);
extern uint8_t Get_free_member(Member *pElement[] , uint32_t *u32free_member);
extern uint8_t Get_deleted_head_member(Member *pElement[] , uint32_t *u32Deleted_element);
extern uint8_t Get_deleted_tail_member(Member *pElement[] , uint32_t *u32Deleted_element);
extern uint8_t Get_indexed_deleted_member(Member *pElement[] ,uint32_t u32Index, uint32_t *u32Deleted_element);


#endif // Database

