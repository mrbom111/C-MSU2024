
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