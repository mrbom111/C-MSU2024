#ifndef arr_18
#define arr_18

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char Name[100];
    int Group;
    int School;
} Student;


void redistribute(Student *arr, int len);

#endif