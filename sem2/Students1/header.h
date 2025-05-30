#ifndef arr_18
#define arr_18

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    char Name[100];
    int Group;
    int School;
} Student;
int compare_students(const void *a, const void *b);
void sort_students(Student *arr, int n);
void generate_data(const char *filename, int N);
void redistribute(Student *arr, int len);

#endif