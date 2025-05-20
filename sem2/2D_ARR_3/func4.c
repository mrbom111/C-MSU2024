#include "2D_ARR_3.h"



int find_column(int **a, int *row_len, int max_N) {
    int max_cols = row_len[0];
	int curr;
    
    for (int i = 1; i < max_N; i++) {
        if (row_len[i] > max_cols)
            max_cols = row_len[i];
    }

    
    for (int col = 0; col < max_cols; col++) {//проходим по всем столбцам
        int valid = 1;
        

        for (int row = 0; row < max_N; row++) { //проходим по строкам
            if (col >= row_len[row]){ //если строка не достаточной длины
                continue;
		}

            curr = a[row][col];
            for (int k = 0; k < row_len[row]; k++) {  // проходим по строке
                if (k != col && a[row][k] >= curr) { //проверяем условие
                    valid = 0;
                    break;
                }
            }
            if (!valid)
                break;
        }

        if (valid) {
            return col; //нашли нужный столбец
        }
    }

    return -1; //если нет такого столбца
}