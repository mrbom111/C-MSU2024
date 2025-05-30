#include "header_11.h"

int main() {
    double * arr;
	double x;
	char filename[50];
    int len,res;
	FILE * f;
	
	//
	printf("Enter x: ");
	scanf("%lf", &x);
	printf("Enter length: ");
	scanf("%d", &len);
	if (len < 0)
	{
		printf("Negative length error\n");
		return -1;
	}
	
	//
	
	arr = (double *)malloc(len * sizeof(double));
	
	//
	
	printf("Enter filename: ");

	scanf("%s", filename);
	f = fopen(filename, "r");
	
	//
	
	if (f == NULL){
		printf ("File error");
	}else{
	
	for (int i = 0; i<len; i++){
		
		if (fscanf(f, "%lf", &arr[i])!=1){
			printf("File is empty");
			return 0;
		};
	}
    res = func(x,len, arr);
	printf("Position: %d",res);
    }
    return 0;
}