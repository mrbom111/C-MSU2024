#include "2D_ARR_2.h"
void func(const char *input_filename) {
    int max_N, max_M, M, N, old_max_M;
    int **a;
    FILE *f;
    int* subset;
    int* ind;
    int subset_size,col1,col2;
    
    f = fopen(input_filename, "r");
    if (f == NULL) {
        printf("read file error\n");
        return;
    }

    fscanf(f, "%d %d", &M, &N);
    fscanf(f, "%d %d", &max_N, &max_M);

    a = (int **)malloc (max_N*sizeof(int *) + max_N*max_M*sizeof(int)); //память под указатели на строки
    a[0] = (int *)(a + max_N);
    for (int i=1; i < max_N; i++) {a[i] = a[i-1] + max_M;}

    

    for (int i = 0; i < max_N; i++) {
        for (int j = 0; j < max_M; j++) {
            if (fscanf(f, "%d", &a[i][j]) != 1) {
                printf("data error");
                fclose(f);
                return;
            }
        }
    }

    fclose(f);

    subset = (int *)malloc(max_M * sizeof(int)); //массив номеров столбцов
    ind = (int *)malloc(max_M * sizeof(int));  //
    subset_size = 0;

    for (int j = 0; j < max_M; j++) {
        int flag = 1;
        for (int i = 0; i < max_N; i++) {
            if (a[i][j] < M || a[i][j] > N) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            subset[subset_size] = j;
            subset_size++;
        }
    }
for (int j = 0; j < max_M; j++){
    ind[j] = 0;
}
        //shift = 0; //сдвиг

        for (int i = 0; i + 1 < subset_size; i += 2) {
        col1 = subset[i];// - shift;
        col2 = subset[i+1];// - shift;

    //первый элемент всегда минимум
    a[0][col1] = a[0][col2];

    //в остальных всегда минимум либо текущий, либо предыдущий 
    for (int row = 1; row < max_N; row++) {
        if (a[row][col2] < a[row - 1][col1]) {
            a[row][col1] = a[row][col2];
        } else {
        a[row][col1] = a[row - 1][col1];
        }
    }

    //column_del(a, max_N, &max_M, col2);
    ind[col2] = 1;
    
    //shift++;
	}
	    
	column_del(a, ind, max_N, &max_M);
	free(ind);
	
	
	
		//
	for (int i = 1; i < max_N; i++) {
		for (int j = 0; j < max_M; j++) {
			a[0][i * max_M + j] = a[i][j];
		}
	}

	for (int i = 1; i < max_N; i++) {
		a[i] = a[0] + i * max_M;
	}
//
    f = fopen("data.res", "w");
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

    free(a);
}