
int new_amount_of_elements = 0;
for (int i = 0; i < max_N; i++) {
    new_amount_of_elements += row_len[i];
}


int **arr_compact = malloc(max_N * sizeof(int *) + new_amount_of_elements * sizeof(int));
arr_compact[0] = (int *)(arr_compact + max_N);


int current = 0;
for (int i = 0; i < max_N; i++) {
    arr_compact[i] = arr_compact[0] + current;
    for (int j = 0; j < row_len[i]; j++) {
        arr_compact[i][j] = arr[i][j]; // копируем только оставшиеся элементы
    }
    current += row_len[i];
}


free(arr);


arr = arr_compact;

#include "2D_ARR_3.h"




void column_del_3(int **a, int *row_len, int max_N, int col) {
    for (int row = 0; row < max_N; row++) {
        if (col >= row_len[row])//если строка не достаточной длины
            continue; 
        for (int j = col; j < row_len[row] - 1; j++) {
            a[row][j] = a[row][j + 1]; //сдвигаем элементы влево
        }

        row_len[row]--; //уменьшаем длину строки
    }
}
