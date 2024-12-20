#include "header_3s.h"


/*int sort_check(double * arr, int len)
{
	for (int i=0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1]) return 0;
	}
	return 1;
}*/

void array_generate(double * arr, int len)
{
	double value;
	srand(time(NULL));                            
	for (int i = 0; i < len; i++)
	{
		value = ((rand() % (2 * MAX_ARRAY_VALUE + 1)) - MAX_ARRAY_VALUE) * RAND_MULTIPLIER;
		arr[i] = value;
	}
}	
	
	
	
	void func(int len, double *arr, FILE * f) {
    double temp;
    int flag;
    do {
        flag = 0;

        for (int i = 0; i < len - 1; i++) {
            if (arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = 1; 
            }
        }

        for (int i = len - 1; i > 0; i--) {
            if (arr[i] < arr[i-1]) {
                temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
                flag = 1;
            }
        }

    } while (flag==1); 
	 for (int i = 0; i < len; i++) {
            fprintf(f, "%lf\n", arr[i]);
        }
}
