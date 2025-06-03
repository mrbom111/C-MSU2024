#include "2D_ARR_1.h"

void column_del(int **a, int max_N, int *max_M, int num) {
    if (num < 0 || num >= *max_M) return;

    for (int i = 0; i < max_N; i++) {
        for (int j = num; j < *max_M - 1; j++) {
            a[i][j] = a[i][j + 1];
        }
    }

    (*max_M)--;
}
