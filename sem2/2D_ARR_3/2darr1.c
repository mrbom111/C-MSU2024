#include <stdlib.h>
#include <stdio.h>
void column_del(int **a, int max_N, int *max_M, int num) {
    if (num < 0 || num >= *max_M) return;

    for (int i = 0; i < max_N; i++) {
        for (int j = num; j < *max_M - 1; j++) {
            a[i][j] = a[i][j + 1];
        }
    }

    (*max_M)--;
}

int main(void) {
    int max_N, max_M;
    int **a;
    FILE *f;

    f = fopen("data.dat", "r");
    if (f == NULL) {
        printf("file error\n");
        return 1;
    }

    fscanf(f, "%d %d", &max_N, &max_M);

    a = (int **)malloc(max_N * sizeof(int *)); 
    if (a == NULL) {
        printf("pointer memory error");
        fclose(f);
        return 1;
    }

    for (int i = 0; i < max_N; i++) {
        a[i] = (int *)malloc(max_M * sizeof(int));
        if (a[i] == NULL) {
            printf("memory error");
            for (int j = 0; j < i; j++) free(a[j]);
            free(a);
            fclose(f);
            return 1;
        }
    }

    for (int i = 0; i < max_N; i++) {
        for (int j = 0; j < max_M; j++) {
            if (fscanf(f, "%d", &a[i][j]) != 1) {
                printf("data error\n");
                return 1;
            }
        }
    }

    fclose(f);

    for (int j = 0; j < max_M; j++) { 
        int flag = 1;
        for (int i = 0; i < max_N; i++) {
            for (int k = 0; k < max_M; k++) {
                if (k != j && a[i][j] <= a[i][k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) break;
        }
        if (flag == 1) {
            column_del(a, max_N, &max_M, j); 
            break;
        }
    }

    f = fopen("data.res", "w");
    if (f == NULL) {
        printf("write file error");
        return 1;
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

    return 0;
}