#include "header34.h"



int main(void)
{
	FILE * f = fopen ("input1309.txt","r");
	int a;
	a= func(f);
	if (a==0){
		printf("The file is empty");
	} else{
		printf("Last local min size is %i",a);
	}
	return 0;
}