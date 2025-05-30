#include <stdio.h>
#include <math.h>

int count_amount(FILE *f);

int count_amount(FILE *f)
{
    int sum  = 0, current = 0, is_empty =-10;  
	
	
    while (fscanf(f, "%d", &current) == 1) 
    {
		is_empty = 1;
        if (current == 1 || current == 2 || current == 3 || current == 4 || current == 5) 
        {
            sum += 1;
        }
    }
	
	if (is_empty == -10){ 
	 
			return -10; 
	}
	else { return sum;} 
}

int main(void)
{
	int a; 
    FILE * f = fopen("25.txt", "r");
    if (f == NULL)
    {
        printf("File error");
    }
    else // сюда пойдет, если файл есть
    {
		a = count_amount(f);
		if (a==-10){
			printf("The file is empty");
		} else{
			 printf("Answer: %d", a); 
			 }
		
	  
        
    }
	return 0; 
}




