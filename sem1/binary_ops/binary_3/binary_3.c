#include "headerb_3.h"


#include<stdio.h>

void binary_print(int number);
void binary_print(int number)
{
	int index = 8 * sizeof(int) - 1;
	unsigned int mask = 1 << index;
	for (; index >= 0; index--, mask >>= 1)
	{
		if (number & mask) printf("1"); else printf("0");
		if (index % 8 == 0) printf(" "); 
	}
}

int count_bits(int num) {
    int count = 0;
    while (num != 0) {
        count += num & 1;  
        num >>= 1; 
    }
    return count;
}

void subsets(int N, int k, FILE *f) {
    int all_sub = 1 << N;  // 2^N — количество всех подмножеств
    for (int i = 0; i < all_sub; i++) {
        if (count_bits(i) == k) {  
            fprintf(f, "{");
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {  
                    fprintf(f, "%d ", j + 1);
                }
            }
            fprintf(f, "}\n");
        }
    }
}

int main() {
    int N = 4, k = 2;
	FILE *f = fopen("output.txt", "w");
    if (f == NULL) {
        printf("Ошибка при открытии файла!\n");
        return 1;
    }
    subsets(N, k, f);
	fclose(f);
    return 0;
}