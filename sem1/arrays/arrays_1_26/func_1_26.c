#include "header_34.h"

void func(int len, double * arr) {
    int count = 0;
    double a1,a2,a3,a4;
    if (len < 4){
        printf("Amount of elements is less than 4");
        
    }else{
    a1=arr[0]; a2=arr[1]; a3=arr[2]; a4=arr[3];
	for (int i = 4; i<len; i++){
		if (fabs(arr[i]-a1) < 1.e-10 || fabs(arr[i]-a2) < 1.e-10 || fabs(arr[i]-a3) < 1.e-10 || fabs(arr[i]-a4) < 1.e-10){
            count ++;
        }
	}
	printf ("\n count: %d",count);
    }
}
