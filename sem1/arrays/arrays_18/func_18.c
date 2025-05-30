#include "header_34.h"

void func(int len, double * arr) {
	double min=arr[0], alm_min;
    for (int i = 0; i<len; i++){
		if (arr[i] <= min){
			min = arr[i];
		}else {alm_min = arr[i];}
	}
	for (int i = 0; i<len; i++){		
		if (arr[i] > min && arr[i] < alm_min){
			alm_min = arr[i];
		}
	}
	for (int i = 0; i<len; i++){		
		if (fabs(arr[i] - min) < 1.e-10){
			arr[i] = alm_min;
		}
		printf ("arr[%d] = %lf \n",i,arr[i]);
	}
}