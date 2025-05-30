#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-10  // Погрешность для проверки фиксированных радиусов

typedef struct {
    double x, y, rad; 
	int stop;
} Circles;


// Функция для вычисления расстояния между двумя центрами окружностей
double distance(Circles a, Circles b) {
	if (a.stop == 1 && b.stop ==1){
		return -1;
	}else if (a.stop == 1){
		return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)) - a.rad;
	}else if (b.stop == 1){
		return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)) - b.rad;
	}else{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));}
}


// Основная функция для вычисления радиусов
void segments(Circles *arr, int len) {
	printf("start\n");
    int ChangedAmount=1, ChangedIndex1, ChangedIndex2;
	double changedRad1, changedRad2, currminrad, currdistance;
	while (ChangedAmount !=0){
		printf("iter\n");
		ChangedAmount=0;
		currminrad = -1;
		for (int i =0; i<len; i++){
			for (int j = i+1; j < len; j++){
				if (arr[i].stop != 1 || arr[j].stop !=1){ //если хоть 1 не фиксирован
					
					currdistance=distance(arr[i],arr[j]); //считаем расстояние
					printf("%lf %d %d\n",currdistance, i,j);
					if (arr[i].stop ==1){ //если первый фиксирован
						if (currminrad == -1){ //если минимум пока не задан
							currminrad=currdistance;
							ChangedAmount=1;
							ChangedIndex1= j;
							changedRad1 = currdistance;
						}else{ //если минимум уже задан
							if (currminrad> currdistance){
								currminrad=currdistance;
								ChangedAmount=1;
								ChangedIndex1= j;
								changedRad1 = currdistance;
							}
						}
					}
					else if (arr[j].stop == 1){ // если фиксирован второй
						if (currminrad == -1){
							currminrad=currdistance;
							ChangedAmount=1;
							ChangedIndex1= i;
							changedRad1 = currdistance;
						}else{
							if (currminrad> currdistance){
								currminrad=currdistance;
								ChangedAmount=1;
								ChangedIndex1= i;
								changedRad1 = currdistance;
							}
						}
					}
					else{ //если ни один не фиксирован
						if (currminrad == -1){
							currminrad=currdistance/2;
							ChangedAmount=2;
							ChangedIndex1= i;
							ChangedIndex2=j;
							changedRad1 = currdistance/2;
							changedRad2 = currdistance/2;
						}else{
							if (currminrad > currdistance){
								currminrad=currdistance/2;
								ChangedAmount=2;
								ChangedIndex1= i;
								ChangedIndex2=j;
								changedRad1 = currdistance/2;
								changedRad2 = currdistance/2;
							}
						}
					}
				} 
			}//конец for_j
			
		}//конец for_i
		if (ChangedAmount ==1){
			arr[ChangedIndex1].rad = changedRad1;
			arr[ChangedIndex1].stop = 1;
		}else if(ChangedAmount == 2){
			arr[ChangedIndex1].rad = changedRad1;
			arr[ChangedIndex2].rad = changedRad2;
			arr[ChangedIndex1].stop = 1;
			arr[ChangedIndex2].stop = 1;
		}
	}//конец while
	for(int i = 0; i<len; i++){
		printf("Radius %d : %lf\n", i, arr[i].rad);
	}
}

int main() {
    FILE *f = fopen("centers.txt", "r");
	Circles * arr=NULL;
	int len =0;
	double x1,y1;
    if (f == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }
	
	while (fscanf(f, "%lf", &x1)==1)
    {
        if (fscanf(f, "%lf", &y1)==1)
        {
            len++;
            arr=(Circles*)realloc(arr, len*sizeof(Circles));
            arr[len-1].x=x1;
            arr[len-1].y=y1;
			arr[len-1].rad = 0;
			arr[len-1].stop = 0;
			
        }
	}

    
    segments(arr,len);  // Вызов функции для расчета радиусов
	free(arr);
    fclose(f);  // Закрываем файл
    return 0;
}
