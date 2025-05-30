#include "2D_ARR_2.h"

void column_del(int **a,int* ind, int max_N, int *max_M) {
int k = 0;

for (int j = 0; j < *max_M; j++) {
    printf("ind: %d \n",ind[j]);
            if(ind[j]==0){
                for (int i = 0; i<max_N;i++){
                    a[i][k] = a[i][j];
                }
                k++;
                
                
            }
            
        }
        (*max_M)=k;
}

/* if (num < 0 || num >= *max_M) return;

    for (int i = 0; i < max_N; i++) {
        for (int j = num; j < *max_M - 1; j++) {
            a[i][j] = a[i][j + 1];
        }
    }

    (*max_M)--;
}*/
