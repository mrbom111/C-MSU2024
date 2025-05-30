#include "header.h"

int compare_students(const void *a, const void *b) {
    const Student *s1 = (const Student *)a;
    const Student *s2 = (const Student *)b;

    if (s1->Group != s2->Group)
        return s1->Group - s2->Group;

    return s1->School - s2->School;
}


void sort_students(Student *arr, int n) {
    qsort(arr, n, sizeof(Student), compare_students);
}