#include <stdio.h>
#include <math.h>

int func(FILE *f);
int func(FILE *f){
	double a,b;
	int cnt=1, v=-1;
	while (fscanf(f,"%lf", &b) == 1){
		if (v == -1){
			v=1;
		}else if (b>a){
			v=0;
		}else if (b<a){
			cnt=1;
			v=1;
		}else if (b==a && v==1){
			cnt+=1;
		}
		a=b;
		
	}
	return cnt;
}

int main(void)
{
	FILE * f = fopen ("input1309.txt","r");
	int a;
	a= func(f);
	printf("%i",a);
	
	return 0;
}