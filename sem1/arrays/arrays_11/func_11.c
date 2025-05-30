#include "header_11.h"

int func(double x, int len, double * arr) {
    int start = 0,end = len,c;
	while (end - start>1){
		c = start + ((end-start)/2);
		if (arr[c] < x){
			start = c;
			printf("<: start %d end %d \n",start,end);
		}else if (arr[c] > x){
			end = c;
		}else {
			return c+1;
		}
	}
	if (arr[start] >x){
		return start;
	}else{
		return start+1;
		}
	
}