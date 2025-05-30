#include "header_44.h"
double func(FILE *f){
 
    double x,sum=0,summax=0;
    
    int first = 1;
    while(fscanf(f,"%lf",&x) == 1) {
		if (first == 1){
			summax = x;
			first = 0;
		}
		if (x>summax) {
			summax = x;
		}
		sum = sum+x;
		if (sum > summax) {
		   summax = sum;
		}
		if (sum <=0){
			sum = 0;
		}
	}
	return summax;
}