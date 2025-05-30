#include <stdio.h>
#include <stdlib.h>

#define N 15

void print_arr(double * arr, int len);

void print_arr(double * arr, int len)
{
	printf("\nArray:\n");
	for (int i=0; i < len; i++) printf("arr[%d] = %.1lf\n", i, arr[i]);
	printf("\n");
}

int main(void)
{
	int len, capacity = 2;
	double current;
	// static array
	int arr1[N];
	char filename[50];
	// dynamic array
	double *arr;
	double *arr2;

	FILE *f;

	printf("Enter array length: ");
	scanf("%d", &len);
	
	if (len < 0)
	{
		printf("Negative length error\n");
		return -1;
	}
	
	arr = (double *)malloc(len * sizeof(double));

	for (int i=0; i < N; i++) arr1[i] = i;

	printf("\narr1[5] = %d\n", arr1[5]);
	
	for (int i=0; i < len; i++) arr[i] = len - i;
	
	print_arr(arr, len);

	free(arr);

	printf("Enter filename: ");

	scanf("%s", filename);
	
	f = fopen(filename, "r");
	
	if (f == NULL)
	{
		printf("Can't open the file\n");
		return -2;
	}

	len = 0;
	arr2 = (double *)malloc(capacity*sizeof(double));
	
	while (fscanf(f, "%lf", &current) == 1)
	{
		++len;
		if (len > capacity)
		{
			capacity *= 2;
			arr2 = (double *)realloc(arr2, capacity*sizeof(double));
		}	
		arr2[len - 1] = current;
	}

	print_arr(arr2, len);

	printf("\nActual length = %d, Capacity = %d", len, capacity);

	free(arr2);
	
}