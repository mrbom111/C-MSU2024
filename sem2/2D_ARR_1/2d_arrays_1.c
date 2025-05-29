#include "2D_ARR_1.h"


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
    a = (int **)malloc (max_N*sizeof(int *) + max_N*max_M*sizeof(int));
    a[0] = (int *)(a + max_N);
    for (int i=1; i < max_N; i++) {a[i] = a[i-1] + max_M;}
    if (a == NULL) {
        printf("pointer memory error");
        fclose(f);
        return 1;
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

    delete_max_columns(a, max_N, &max_M); 
		
	for (int i = 1; i < max_N; i++) {// Сжимаем данные в памяти a[0]
		for (int j = 0; j < max_M; j++) {
			a[0][i * max_M + j] = a[i][j];
		}
	}

	
	for (int i = 1; i < max_N; i++) {// Переназначаем указатели
		a[i] = a[0] + i * max_M;
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
    fprintf(f, "проверка памяти\n");
    for (int m = 0; m < max_N * max_M; m++) {
        
        fprintf(f, "|%d|",a[0][m]);
    }
    fclose(f);

//     for (int i = 0; i < max_N; i++) {
//         free(a[i]);
//     }
    free(a);
	printf("Done");
	
    return 0;
}
