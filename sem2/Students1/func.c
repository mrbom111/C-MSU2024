#include "header.h"

void redistribute(Student *arr, int len) {
    for (int i = 0; i < len; i++) {
        int group_i = arr[i].Group;
        int school_i = arr[i].School;

        //ищем студента из другой группы, но той же школы
        int j = -1;
        for (int m = i + 1; m < len; m++) {
            if (arr[m].Group != group_i && arr[m].School == school_i) {
                j = m;
                break;
            }
        }

        if (j == -1) continue; //не нашли j

        //если нашли найдём: студента из той же группы, но другой школы
        int k = -1;
        for (int m = i + 1; m < len; m++) {
            if (arr[m].Group == group_i && arr[m].School != school_i) {
                k = m;
                break;
            }
        }

        if (k == -1) continue; //не нашли k

        // Меняем группы у студентов j и k
        int temp = arr[j].Group;
        arr[j].Group = arr[k].Group;
        arr[k].Group = temp;
    }
}