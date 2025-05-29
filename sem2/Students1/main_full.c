#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char Name[100];
    int Group;
    int School;
} Student;
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

        // если нашли найдём: студента из той же группы, но другой школы
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

int main() {
    FILE *f;
    char filename[100];
    int len;

    printf("Enter number of students: ");
    scanf("%d", &len);

    Student *arr = (Student *)malloc(len * sizeof(Student));

    printf("Enter filename: ");
    scanf("%s", filename);

    f = fopen(filename, "r");

    if (f == NULL) {
        printf("File error");
        return 1;
    }

    for (int i = 0; i < len; i++) {
        if (fscanf(f, "%s %d %d", arr[i].Name, &arr[i].Group, &arr[i].School) != 3) {
            printf("Error reading data or file is too short\n");
            free(arr);
            return 1;
        }
    }

    /*
    for (int i = 0; i < len; i++) {
        printf("Student %d: %s, Group %d, School %d\n", i + 1, arr[i].Name, arr[i].Group, arr[i].School);
    }*/

    fclose(f);
	//перераспределение
    redistribute(arr, len);
	FILE *f = fopen("data.res", "w");
    if (f == NULL) {
        printf("output file error\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < len; i++) {
        fprintf(f, "%s %d %d\n", arr[i].Name, arr[i].Group, arr[i].School);
    }

    fclose(f);
	
    free(arr);
    return 0;
}
