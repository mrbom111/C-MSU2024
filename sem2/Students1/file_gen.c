#include "header.h"

#define MAX_NAME_LEN 100
#define MAX_NAMES 1000

void generate_data(const char *filename, int N) {
    int group_min, group_max;
    int school_min, school_max;
    int i;
    int total_names;
    int name_index;
    int group, school;
    FILE *f;
    char names[MAX_NAMES][MAX_NAME_LEN];

    if (N <= 0) {
        printf("Nmber of studentrs must be positive.\n");
        return;
    }

    printf("enter min and max group number: ");
    scanf("%d %d", &group_min, &group_max);

    printf("enter min and max school number: ");
    scanf("%d %d", &school_min, &school_max);

    if (group_min > group_max || school_min > school_max) {
        printf("wrong parameters.\n");
        return;
    }

    // Загружаем имена из файла
    f = fopen(filename, "r");
    if (f == NULL) {
        printf("error opening %s\n", filename);
        return;
    }

    fscanf(f, "%d\n", &total_names);

    for (i = 0; i < total_names; i++) {
        if (fgets(names[i], MAX_NAME_LEN, f) == NULL) {
            printf("error reading naes from names.txt.\n");
            fclose(f);
            return;
        }

        names[i][strcspn(names[i], "\r\n")] = '\0'; // удаляем перевод строки
    }

    fclose(f);

    // Открываем выходной файл
    f = fopen("data.dat", "w");
    if (f == NULL) {
        printf("error opening data.dat\n");
        return;
    }

    srand((unsigned int)time(NULL));

    for (i = 0; i < N; i++) {
        name_index = rand() % total_names;
        group = group_min + rand() % (group_max - group_min + 1);
        school = school_min + rand() % (school_max - school_min + 1);

        fprintf(f, "%s %d %d\n", names[name_index], group, school);
    }

    fclose(f);
    printf("File data.dat succesfuly created.\n");
}
