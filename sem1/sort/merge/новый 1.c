#include <stdio.h>
#include <stdlib.h>

// Функция для слияния двух подмассивов
void merge(int *array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создаем временные массивы
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Копируем данные во временные массивы
    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

    // Слияние временных массивов обратно в основной массив
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы, если есть
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    // Освобождаем временные массивы
    free(L);
    free(R);
}

// Рекурсивная функция сортировки слиянием
void mergeSort(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Рекурсивная сортировка двух половин
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Слияние отсортированных половин
        merge(array, left, mid, right);
    }
}

// Функция для вывода массива
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Основная функция
int main() {
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    //int size = sizeof(array) / sizeof(array[0]);

    printf("Исходный массив:\n");
    printArray(array, size);

    mergeSort(array, 0, size - 1);

    printf("Отсортированный массив:\n");
    printArray(array, size);

    return 0;
}
