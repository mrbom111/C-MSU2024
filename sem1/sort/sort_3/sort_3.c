#include "header_3s.h"

int main(void) {
    double * arr;
	double curr = 0;
	char filename[50];
    int len;
	FILE * f;

	scanf("%d",&len);
	if (len <= 0) {
        printf("Invalid array length.\n");
        return 1;
    }
	
	arr = (double *)malloc(len * sizeof(double));
	
	printf("Enter filename: ");

	scanf("%s", filename);
	
	f = fopen(filename, "w");
	
	
	if (f == NULL){
		printf ("File error");
		return 0;
	}
	
	
	array_generate(arr, len);
	
	clock_t start = clock();
	
	func(len, arr, f);
	
	clock_t end = clock();
	
	double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
	
    printf("Sorting took %lf seconds.\n", time_taken);
	
	free(arr);
	
	fclose(f);
	
    return 0;
}