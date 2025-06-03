#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STEP 0.01
#define SOLUTION_ACCURACY 1.e-12
#define EPS 1.e-45
#define ALLOCATION_STEP 5
#define MAX_NEWTON_ITERATIONS 50

// Функция f(x)
double func(double x) {
    return x * x - 5 - sin(x + 5);
}

// f'(x)
double derivative(double x) {
    return 2 * x - cos(x + 5);
}

// Вывод найденных решений
void print_all_solutions(int number_of_solutions, double *solution_array) {
    printf("\nList of solutions:\n");
    int i;
    for (i = 0; i < number_of_solutions; i++)
        printf("Solution #%d: %.12lf\n", i + 1, solution_array[i]);
    printf("\n");
}

// Добавление решения в массив
void add(int *number_of_solutions, int *allocated_memory_for_solutions, double **solution_array, double root) {
    ++(*number_of_solutions);
    if (*allocated_memory_for_solutions == 0) {
        *allocated_memory_for_solutions = ALLOCATION_STEP;
        *solution_array = (double *) malloc(*allocated_memory_for_solutions * sizeof(double));
    } else if (*allocated_memory_for_solutions < *number_of_solutions) {
        *allocated_memory_for_solutions += ALLOCATION_STEP;
        *solution_array = (double *) realloc(*solution_array, *allocated_memory_for_solutions * sizeof(double));
    }
    (*solution_array)[*number_of_solutions - 1] = root;
}

// Метод деления пополам
double finding_root_with_division_by_two(double (*func)(double), double left, double right) {
    double middle;
	while (right - left > SOLUTION_ACCURACY) {// Пока длина отрезка больше точности
        middle = (left + right) / 2;          // Середина текущего отрезка
        if (fabs(func(middle)) < EPS) return middle;// Если значение функции почти 0 — это корень
        if (func(left) * func(middle) < 0)    // Если на отрезке [left, middle] знак меняется
            right = middle;                   // bщем в левой половине
        else
            left = middle;                    // bначе в правой
    }
    return (left + right) / 2;                // Возвращаем приближённый корень
}

// Метод Ньютона для уточнения корня
double newton_method(double (*f)(double), double (*df)(double), double x0) {
    double x = x0;
    int i;
	double fx,dfx;
    for (i = 0; i < MAX_NEWTON_ITERATIONS; i++) {
        fx = f(x);
        dfx = df(x);
        if (fabs(fx) < SOLUTION_ACCURACY)
            return x;
        if (fabs(dfx) < 1e-14) 
            break;
        x = x - fx / dfx;
    }
    return x;
}

// Поиск решений на отрезке с шагом STEP
int find_solutions(double (*func)(double), double (*derivative)(double), double start_arg, double end_arg, int *number_of_solutions, double **solution_array) {
    int allocated_memory_for_solutions = 0;
    double left = start_arg;
    double right = start_arg + STEP;

    while (right < end_arg + EPS) {
        if (fabs(func(left)) < EPS) {
            add(number_of_solutions, &allocated_memory_for_solutions, solution_array, left);
            left += STEP / 10;
            continue;
        }
        if (func(left) * func(right) < -EPS) {
            // Находим корень методом бисекции
            double root = finding_root_with_division_by_two(func, left, right);
            // Уточняем корень методом Ньютона
            root = newton_method(func, derivative, root);
            add(number_of_solutions, &allocated_memory_for_solutions, solution_array, root);
        }
        left = right;
        right += STEP;
    }
    return 0;
}

int main(void) {
    double start_arg, end_arg;
	 int number_of_solutions;
	  double *solution_array;
    printf("Enter the segment for finding solutions: ");
    if (scanf("%lf %lf", &start_arg, &end_arg) != 2) {
        printf("Invalid input\n");
        return 1;
    }
    if (end_arg < start_arg) {
        printf("\nWrong points order\n");
        return 1;
    }

    number_of_solutions = 0;
    solution_array = NULL;

    find_solutions(func, derivative, start_arg, end_arg, &number_of_solutions, &solution_array);

    print_all_solutions(number_of_solutions, solution_array);

    free(solution_array);

    return 0;
}
