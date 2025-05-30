#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double start;  // Начало отрезка
    double end;    // Конец отрезка
} Segment;
int compare(const void *a, const void *b);
void find_max_union(Segment *SegmArr, int len);
int compare(const void *a, const void *b) {
    Segment *seg1 = (Segment *)a;
    Segment *seg2 = (Segment *)b;
    
    if ((*seg1).start < (*seg2).start) return -1;
    if ((*seg1).start > (*seg2).start) return 1;
    return 0;
}

// Функция для объединения отрезков с максимальной длиной
void find_max_union(Segment *SegmArr, int len) {
    

    double maxLength = 0, maxStart = 0, maxEnd = 0; 
    double currStart = SegmArr[0].start;
    double currEnd = SegmArr[0].end;
	double length;
	
	/*for(int i = 0; i<len; i++){
		printf("segment: [%lf, %lf] \n", SegmArr[i].start,  SegmArr[i].end);
	}*/
	Segment *MaxSegments = (Segment *)malloc(len * sizeof(Segment)); //Текущие отрезки
	Segment *CurrSegments = (Segment *)malloc(len * sizeof(Segment)); //Отрезки при максимальной длине
	int CurrSegAmount = 1;
    int MaxSegAmount = 1;
	qsort(SegmArr, len, sizeof(Segment), compare);  // quicksort отрезков
	CurrSegments[0] = SegmArr[0];
	
    for (int i = 1; i < len; i++) {
        
        if (SegmArr[i].start <= currEnd) {
            
            if (SegmArr[i].end > currEnd) {
				
                currEnd = SegmArr[i].end;
				CurrSegments[CurrSegAmount] = SegmArr[i];
				CurrSegAmount++;
				
            }
			
        } else {
            length = currEnd - currStart;
            if (length > maxLength) {
				for (int j = 0; j < CurrSegAmount; j++){
					MaxSegments[j] = CurrSegments[j];
				}
				MaxSegAmount= CurrSegAmount;
                maxLength = length;
                maxStart = currStart;
                maxEnd = currEnd;
            }
			
			currStart = SegmArr[i].start;
			currEnd = SegmArr[i].end;
			CurrSegments[0] = SegmArr[i];
			CurrSegAmount = 1;
        }
    }

    //последний отрезок
    length = currEnd - currStart;
    if (length > maxLength) {
		for (int j = 0; j < CurrSegAmount; j++){
				MaxSegments[j] = CurrSegments[j];
				}
		MaxSegAmount= CurrSegAmount;
        maxLength = length;
        maxStart = currStart;
        maxEnd = currEnd;
    }
	for (int j = 0; j < MaxSegAmount; j++){
					printf("Segment %d : %lf %lf \n", j, MaxSegments[j].start, MaxSegments[j].end);
				}
    printf("Max segment: [%lf, %lf] with length %lf\n", maxStart, maxEnd, maxLength);
	free(MaxSegments);
	free(CurrSegments);
}




int main(void) {
    
	int len = 0;
	double start, end;
    Segment *SegmArr = NULL;
	FILE *f;
	f = fopen("Segments.txt", "r");
    if (f==NULL){
		printf("File error");
		return 0;
	}
	
	
	
    while (fscanf(f, "%lf %lf", &start, &end) == 2) {
        len++;
   
        SegmArr = (Segment *)realloc(SegmArr, len * sizeof(Segment));
        
        SegmArr[len - 1].start = start;
        SegmArr[len - 1].end = end;
    }
	

    fclose(f);
	/*for(int i = 0; i<len; i++){
		printf("segment1: [%lf, %lf] \n", SegmArr[i].start,  SegmArr[i].end);
	}*/

    find_max_union(SegmArr, len);

    free(SegmArr);
    return 0;
}
