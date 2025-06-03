#include "2D_ARR_3.h"


int main(void) {
    FILE *f;
    int **a = NULL;           
    int *row_len = NULL;     
    int max_N = 0;            
    int *row;
    int count;
    char *num;
    char line[MAX_LINE];
	int col_to_delete;
	
	// ввод из файла
    f = fopen("data.dat", "r");
    if (f == NULL) {
        printf("file error");
        return 1;
    }

    while (fgets(line, MAX_LINE, f)) {
        row = (int *)malloc(sizeof(int) * MAX_LINE);
        count = 0;
        num = strtok(line, " \n");
        while (num != NULL) {
            row[count] = atoi(num);
            count++;
            num = strtok(NULL, " \n");
        }

        a = (int **)realloc(a, sizeof(int*) * (max_N + 1));
        row_len = (int *)realloc(row_len, sizeof(int) * (max_N + 1));
		a[max_N] = (int *)realloc(row, sizeof(int) * count);
        row_len[max_N] = count;
        max_N++;
    }
	
    fclose(f);
	
	col_to_delete = find_column(a, row_len, max_N);
	if (col_to_delete != -1) {
		column_del_3(a, row_len, max_N, col_to_delete);
	}
		
	// вывод в файл
    f = fopen("data.res", "w");
    if (f == NULL) {
        printf("file write error");
        for (int i = 0; i < max_N; i++) {
            free(a[i]);
        }
        free(a);
        free(row_len);
        return 1;
    }

    for (int i = 0; i < max_N; i++) {
        for (int j = 0; j < row_len[i]; j++) {
            fprintf(f, "%d ", a[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
	
	
	
    for (int i = 0; i < max_N; i++) {
        free(a[i]);
    }
    free(a);
    free(row_len);

    return 0;
}
