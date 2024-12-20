#define MAX_ARRAY_VALUE 10000
#define RAND_MULTIPLIER 1e-2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int sort_check(double * arr, int len);
void array_generate(double * arr, int len);
void print_array(double *arr, int len, FILE * f);
void merge_sort(double *arr, int left, int right);
void merge(double *arr, int left, int mid, int right);
void array_generate(double * arr, int len){
	double value;
	srand(time(NULL));                            
	for (int i = 0; i < len; i++)
	{
		value = ((rand() % (2 * MAX_ARRAY_VALUE + 1)) - MAX_ARRAY_VALUE) * RAND_MULTIPLIER;
		arr[i] = value;
	}
}
int sort_check(double * arr, int len){
	for (int i=0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1]) return 0;
	}
	return 1;
}
void print_array(double *arr, int len, FILE * f) {
    for (int i = 0; i < len; i++) {
        fprintf(f,"%lf\n", arr[i]);
    }
}
void merge(double *arr, int left, int mid, int right) {
    int SizeL = mid - left + 1;
    int SizeR = right - mid;

    double *L = (double *)malloc(SizeL * sizeof(double));
    double *R = (double *)malloc(SizeR * sizeof(double));

    for (int i = 0; i < SizeL; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < SizeR; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < SizeL && j < SizeR) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < SizeL) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < SizeR) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(double *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


int main(void) {
    double * arr;
	char filename[50];
    int len;
	FILE * f;
	//time_t start_time;
    //time_t end_time;
	clock_t start_time, end_time;
    double time_taken;
	
	scanf("%d",&len);
	if (len <= 0) {
        printf("Invalid arr length.\n");
        return 1;
    }
	
	arr = (double *)malloc(len * sizeof(double));
	
	printf("Enter filename: ");
	scanf("%s", filename);
	f = fopen(filename, "w");
	
	
	if (f == NULL){
		printf ("File error");
		return -1;
	}
	
	array_generate(arr, len);
	
	//start_time = time(NULL);
	
	start_time = clock();

    merge_sort(arr, 0, len-1);

    end_time = clock();

    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken: %lf seconds\n", time_taken);
	
	//end_time = time(NULL);
	
	//printf("%lf\n",difftime(end_time, start_time));
	print_array(arr,len,f);
	free(arr);
	
	fclose(f);
	
    return 0;
}