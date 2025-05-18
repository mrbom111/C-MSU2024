#include "2D_ARR_1.h"
void delete_max_columns(int **a, int max_N, int *max_M) {
    for (int j = 0; j < *max_M; j++) { 
        int flag = 1;
        for (int i = 0; i < max_N; i++) {
            for (int k = 0; k < *max_M; k++) {
                if (k != j && a[i][j] <= a[i][k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) break;
        }
        if (flag == 1) {
            column_del(a, max_N, max_M, j); 
            break;
        }
    }
}