#include <stdio.h>       // Библиотека для ввода/вывода (printf, scanf)
#include <stdlib.h>      // Для работы с памятью (malloc, realloc, free)
#include <math.h>        // Для математических функций (sin, cos, fabs)

#define MAX_NEWTON_ITERATIONS 50
#define STEP 0.01                        // Шаг при разбиении отрезка при поиске корней
#define SOLUTION_ACCURACY 1.e-12        // Точность, с которой требуется найти корень
#define EPS 1.e-45                       // Практически ноль — для сравнения значений с нулём
#define ALLOCATION_STEP 5               // Количество элементов, на которые расширяется массив решений при нехватке памяти

// Функция f(x) = x^2 - 5 - sin(x + 5)
double func(double x) {
    return x * x - 5 - sin(x + 5);      // Это уравнение мы хотим решить: f(x) = 0
}

// Производная функции f(x)
double derivative(double x) {
    return 2 * x - cos(x + 5);          // Это f'(x), нужна для метода Ньютона
}

// Вывод всех найденных решений на экран
void print_all_solutions(int number_of_solutions, double *solution_array) {
    printf("\nList of solutions:\n");
    int i;
    for (i = 0; i < number_of_solutions; i++)               // Проход по массиву решений
        printf("Solution #%d: %.12lf\n", i + 1, solution_array[i]);  // Печать каждого корня с точностью до 12 знаков
    printf("\n");
}

// Функция для добавления нового корня в динамический массив решений
void add(int *number_of_solutions, int *allocated_memory_for_solutions, double **solution_array, double root) {
    ++(*number_of_solutions);                               // Увеличиваем счётчик найденных решений

    if (*allocated_memory_for_solutions == 0) {             // Если память ещё не выделялась
        *allocated_memory_for_solutions = ALLOCATION_STEP;  // Выделяем начальный блок
        *solution_array = (double *) malloc(*allocated_memory_for_solutions * sizeof(double));
    } else if (*allocated_memory_for_solutions < *number_of_solutions) {  // Если память закончилась
        *allocated_memory_for_solutions += ALLOCATION_STEP;               // Увеличиваем её
        *solution_array = (double *) realloc(*solution_array, *allocated_memory_for_solutions * sizeof(double));
    }

    (*solution_array)[*number_of_solutions - 1] = root;     // Сохраняем новый корень в массив
}

// Метод бисекции (деления отрезка пополам) — надёжный способ найти корень
double finding_root_with_division_by_two(double (*func)(double), double left, double right) {
    double middle;
	while (right - left > SOLUTION_ACCURACY) {              // Пока длина отрезка больше точности
        middle = (left + right) / 2;                 // Середина текущего отрезка
        if (fabs(func(middle)) < EPS) return middle;        // Если значение функции почти 0 — это корень
        if (func(left) * func(middle) < 0)                  // Если на отрезке [left, middle] знак меняется
            right = middle;                                 // Ищем в левой половине
        else
            left = middle;                                  // Иначе в правой
    }
    return (left + right) / 2;                              // Возвращаем приближённый корень
}

// Метод Ньютона (касательных) — быстрый способ уточнить корень
double newton_method(double (*f)(double), double (*df)(double), double x0) {
    double x = x0;
    int i;
    for (i = 0; i < 50; i++) {                              // Не больше 50 итераций
        double fx = f(x);                                   // Значение функции в текущей точке
        double dfx = df(x);                                 // Значение производной
        if (fabs(fx) < SOLUTION_ACCURACY)                   // Если достигнута нужная точность — выход
            return x;
        if (fabs(dfx) < 1e-14)                              // Если производная почти 0 — возможен разрыв
            break;
        x = x - fx / dfx;                                   // Формула Ньютона: x_{n+1} = x_n - f(x)/f'(x)
    }
    return x;                                               // Возвращаем уточнённый корень
}

// Главная функция для нахождения всех решений на отрезке
int find_solutions(double (*func)(double), double (*derivative)(double), double start_arg, double end_arg,int *number_of_solutions, double **solution_array) {
    int allocated_memory_for_solutions = 0;                 // Пока ничего не выделено
    double left = start_arg;
    double right = start_arg + STEP;

    while (right < end_arg + EPS) {                         // Пока не дошли до конца отрезка
        if (fabs(func(left)) < EPS) {                       // Если значение функции в левой границе почти 0
            add(number_of_solutions, &allocated_memory_for_solutions, solution_array, left);  // Считаем это корнем
            left += STEP / 10;                              // Немного сдвигаемся, чтобы не попасть снова туда же
            continue;
        }

        // Если на отрезке [left, right] происходит смена знака функции
        if (func(left) * func(right) < -EPS) {
            double root = finding_root_with_division_by_two(func, left, right); // сначала бисекция
            root = newton_method(func, derivative, root);                        // потом уточнение Ньютоном
            add(number_of_solutions, &allocated_memory_for_solutions, solution_array, root); // добавляем в массив
        }

        left = right;                                       // Переходим на следующий отрезок
        right += STEP;
    }

    return 0;                                               // Завершаем работу функции
}

// Главная точка входа в программу
int main(void) {
    double start_arg, end_arg;                              // Границы интервала
    int number_of_solutions;                                // Число найденных решений
    double *solution_array;                                 // Массив для хранения решений

    printf("Enter the segment for finding solutions: ");    // Просим пользователя ввести отрезок
    if (scanf("%lf %lf", &start_arg, &end_arg) != 2) {      // Читаем два числа
        printf("Invalid input\n");                          // Ошибка при вводе
        return 1;
    }

    if (end_arg < start_arg) {                              // Проверка порядка границ
        printf("\nWrong points order\n");                   // Нельзя: левая граница больше правой
        return 1;
    }

    number_of_solutions = 0;                                // Начинаем с нуля решений
    solution_array = NULL;                                  // Массив ещё не создан

    find_solutions(func, derivative, start_arg, end_arg,    // Ищем все корни на отрезке
                   &number_of_solutions, &solution_array);

    print_all_solutions(number_of_solutions, solution_array); // Печатаем все найденные корни

    free(solution_array);                                   // Освобождаем память, выделенную под массив решений

    return 0;                                               // Завершение программы
}
