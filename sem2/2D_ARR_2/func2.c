#include "2D_ARR_2.h"
void func(const char *input_filename, const char *output_filename) {
    int max_N, max_M, M, N;
    int **a;
    FILE *f;

    f = fopen(input_filename, "r");
    if (f == NULL) {
        printf("file error\n");
        return;
    }

    fscanf(f, "%d %d", &M, &N);
    fscanf(f, "%d %d", &max_N, &max_M);

    a = (int **)malloc(max_N * sizeof(int *));
    if (a == NULL) {
        printf("pointer memory error");
        fclose(f);
        return;
    }

    for (int i = 0; i < max_N; i++) {
        a[i] = (int *)malloc(max_M * sizeof(int));
        if (a[i] == NULL) {
            printf("memory error");
            for (int j = 0; j < i; j++) free(a[j]);
            free(a);
            fclose(f);
            return;
        }
    }

    for (int i = 0; i < max_N; i++) {
        for (int j = 0; j < max_M; j++) {
            if (fscanf(f, "%d", &a[i][j]) != 1) {
                printf("data error\n");
                fclose(f);
                return;
            }
        }
    }

    fclose(f);

    int* subset = (int *)malloc(max_M * sizeof(int));
    int subset_size = 0;

    for (int j = 0; j < max_M; j++) {
        int flag = 1;
        for (int i = 0; i < max_N; i++) {
            if (a[i][j] < M || a[i][j] > N) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            subset[subset_size++] = j;
        }
    }

    int shift = 0;

    for (int i = 0; i + 1 < subset_size; i += 2) {
        int col1 = subset[i] - shift;
        int col2 = subset[i + 1] - shift;

        for (int row = 0; row < max_N; row++) {
            int min_value = a[0][col2];
            for (int k = 1; k <= row; k++) {
                if (a[k][col2] < min_value) {
                    min_value = a[k][col2];
                }
            }
            a[row][col1] = min_value;
        }

        column_del(a, max_N, &max_M, col2);
        shift++;
    }

    free(subset);

    f = fopen(output_filename, "w");
    if (f == NULL) {
        printf("write file error");
        return;
    }

    for (int i = 0; i < max_N; i++) {
        for (int j = 0; j < max_M; j++) {
            fprintf(f, "%d ", a[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);

    for (int i = 0; i < max_N; i++) {
        free(a[i]);
    }
    free(a);
}
