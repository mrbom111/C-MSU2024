#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 20000000
#define MAX_ARRAY_VALUE 10000
#define RAND_MULTIPLIER 1e-2
#define MAX_NUM_ITERATIONS 1000000
#define DUMMY_SORT_CYCLE 1000
#define MAX_PRINT_LEN 10

void two_arrays_generate(double * arr1, double *arr2, int len);
void dummy_sort(double * arr, int len);
int sort_check(double * arr, int len);
void print_arr(double * arr, int len, const char * str);
int cmp(const void * a, const void * b);
void quick_sort(double * arr, int len);

void print_arr(double * arr, int len, const char * str)
{
	printf("\n%s:\n", str);
	for (int i=0; i < len; i++) printf("arr[%d] = %.2lf\n", i, arr[i]);
	printf("\n");
}

void two_arrays_generate(double * arr1, double *arr2, int len)
{
	double value;
	srand(time(NULL));                            
	for (int i = 0; i < len; i++)
	{
		value = ((rand() % (2 * MAX_ARRAY_VALUE + 1)) - MAX_ARRAY_VALUE) * RAND_MULTIPLIER;
		//value = rand();
		arr1[i] = value;
		arr2[i] = value;
	}
}

int sort_check(double * arr, int len)
{
	for (int i=0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1]) return 0;
	}
	return 1;
}



int cmp(const void * a, const void * b)
{ 
	if (*(const double *)a > *(const double *)b) return 1; 
	else if (*(const double *)a < *(const double *)b) return -1;
	return 0;
}



int main(void)
{
        int len;
	double *arr1 = NULL, *arr2 = NULL;
        printf("Enter lenght of array: ");
	scanf("%d", &len);
	if (len < 1 || len > MAX_LEN) 
	{
		printf("Incorrent array length");
		return -1;
	}
	
	arr1 = (double *)malloc(len * sizeof(double));
	arr2 = (double *)malloc(len * sizeof(double));
	two_arrays_generate(arr1, arr2, len);
	dummy_sort(arr1, len);
	quick_sort(arr2, len);
	free(arr1);
	free(arr2);
	return 0;
}

