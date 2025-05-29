#include "header.h"


int main(void) {
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
		free(arr);
        return 1;
    }

    for (int i = 0; i < len; i++) {
        if (fscanf(f, "%s %d %d", arr[i].Name, &arr[i].Group, &arr[i].School) != 3) {
            printf("Error reading data or file is too short\n");
            free(arr);
			fclose(f);
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
