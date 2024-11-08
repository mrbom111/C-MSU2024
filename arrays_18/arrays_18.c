#include "header_34.h"

int main() {
    double * arr;
	double curr = 0;
	char filename[50];
    int len=1;
	FILE * f;
	// Создание Массива под 1 эл-т
	
	arr = (double *)malloc(len * sizeof(double));
	
	//Имя файла
	
	printf("Enter filename: ");

	scanf("%s", filename);
	
	f = fopen(filename, "r");
	
	//Проверка файла
	
	if (f == NULL){
		printf ("File error");
		return 0;
	}else{
		if (fscanf(f, "%lf", &arr[0])!=1){
			printf("File is empty");
			return 0;
		}
	}
	
	// Ввод массива
	while (fscanf(f, "%lf", &curr) == 1){
		len++;
		arr = (double *)realloc(arr, len * sizeof(double));
		arr[len-1] = curr; 
    }
	func(len, arr);
	free(arr);
    return 0;
}