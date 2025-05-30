#include <stdio.h>
#include <math.h>
int first_or_second(FILE *f);
int first_or_second(FILE *f)
{
  double first = 0., second = 0., next = 0., 
  int x = 0, y = 0;
  if (fscanf(f, "%lf", &first) != 1)
  {
   // printf("File is empty");
    return -1;
  }
  if (fscanf(f, "%lf", &second) != 1)
  {
  //  printf("File is empty");
    return -1;
  }
  while (fscanf(f, "%lf", &next) == 1)
  {
    if (fabs(next - first) < 1.e-10 ){
		x += 1;
	}
    else if(fabs(next - second) < 1.e-10){
	y += 1;
	} 
  }
   if (x == y) {
	   return 0;
   }
   else if (x > y) {
	   return 1;
   }
   else if (x < y) {
	   return 2;
   }
}

int main(void)
{
	int answer;
     FILE *f = fopen("1_or_2.txt", "r");
   if (f == NULL)
   {
     printf("File error");

   }
   else
   {
       answer = first_or_second(f);
	   if (answer == -1){
		   printf("Файл пустой");
	   }
       else if (answer == 1) {
		   printf("Равных первому больше");
		   }
       else if (answer == 2){ 
	   printf("Равных второму больше");
	   }
	   else if (answer == 0){ 
	   printf("Равное количество");
	   }
   
   }
   
   
   return 0;
}



