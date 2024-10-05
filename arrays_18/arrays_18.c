#include "header_34.h"

int main() {
    double * arr;
	char filename[50];
    int len;
	FILE * f;
	
	//
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
    func(len, arr);
    }
    return 0;
}