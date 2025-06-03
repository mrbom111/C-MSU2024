#include "2D_ARR_3.h"


#define MAX_LINE 1024

int main(void) {
    FILE *f;
    char line[MAX_LINE];
    int max_N = 0;
    int amount_of_elements = 0;
    int *row_len = NULL;
    int **arr = NULL;
	int col_to_delete;
	int count;
	char *num;
	int current_point;
    //считаем max_N и amount_of_elements
    f = fopen("data.dat", "r");
    if (!f) {
        printf("file open error\n");
        return 1;
    }

    while (fgets(line, MAX_LINE, f)) {
        max_N++;
        num = strtok(line, " \n");
        count = 0;
        while (num != NULL) {
            count++;
            num = strtok(NULL, " \n");
        }
        row_len = realloc(row_len, sizeof(int) * max_N);
        row_len[max_N - 1] = count;
        amount_of_elements += count;
    }

    fclose(f);

    arr = malloc(max_N * sizeof(int *) + amount_of_elements * sizeof(int));

    arr[0] = (int *)(arr + max_N);

    // заполняем a
    f = fopen("data.dat", "r");
    if (!f) {
        printf("file reopen error\n");
        free(row_len);
        free(arr);
        return 1;
    }

    current_point = 0;
    for (int i = 0; i < max_N; i++) {
        fgets(line, MAX_LINE, f);
        num = strtok(line, " \n");
        for (int j = 0; j < row_len[i]; j++) {
            arr[0][current_point + j] = atoi(num);
            num = strtok(NULL, " \n");
        }
        arr[i] = arr[0] + current_point;
        current_point += row_len[i];
    }

    fclose(f);

    
     col_to_delete = find_column(arr, row_len, max_N);
    if (col_to_delete != -1) {
        column_del_3(arr, row_len, max_N, col_to_delete);

        // Починка указателей после удаления
        current_point = 0;
        for (int i = 0; i < max_N; i++) {
            arr[i] = arr[0] + current_point;
            current_point += row_len[i];
        }
    }
	f = fopen("data.res", "w");
	if (!f) {
		printf("file write error\n");
		free(arr);
		free(row_len);
		return 1;
	}

	for (int i = 0; i < max_N; i++) {
		for (int j = 0; j < row_len[i]; j++) {
			fprintf(f, "%d ", arr[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	free(arr);
	free(row_len);

    return 0;
}