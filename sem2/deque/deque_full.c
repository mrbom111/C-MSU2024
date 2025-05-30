#include <stdio.h>
#include <stdlib.h>

typedef struct DequeNode {
    double value;
    struct DequeNode *left;
    struct DequeNode *right;
} DequeNode;

typedef struct Deque {
    DequeNode *left_end;
    DequeNode *right_end;
    DequeNode *current;
} Deque;

// a. создать дек с заданным элементом
Deque* create_deque(double value) {
    DequeNode *node;
    Deque *deque;

    node = malloc(sizeof(DequeNode));
    node->value = value;
    node->left = node->right = NULL;

    deque = malloc(sizeof(Deque));
    deque->left_end = deque->right_end = deque->current = node;

    return deque;
}
// b. очистить дек
void clear_deque(Deque *deque) {
    DequeNode *node;
    DequeNode *next;

    node = deque->left_end;
    while (node) {
        next = node->right;
        free(node);
        node = next;
    }
    deque->left_end = NULL;
	deque->right_end = NULL;
	deque->current = NULL;
}

// c. Добавить элемент в правый конец дека
void push_right(Deque *deque, double value) {
    DequeNode *node;  // Объявляем указатель на новый элемент

    node = malloc(sizeof(DequeNode));  // Выделяем память под новый элемент
    node->value = value;
    node->right = NULL;
    node->left = deque->right_end;
	
    if (deque->right_end) {// Если дек не пуст (уже есть правый конец)
        deque->right_end->right = node; 
    } else { // Если дек пуст (нет правого конца)
        deque->left_end = node;
    }
    deque->right_end = node;
}
// d.  Добавить элемент в левый конец дека

void push_left(Deque *deque, double value) {
    DequeNode *node;

    node = malloc(sizeof(DequeNode));
    node->value = value;
    node->left = NULL;
    node->right = deque->left_end;

    if (deque->left_end) {
        deque->left_end->left = node;
    } else {
        deque->right_end = node;
    }
    deque->left_end = node;
}

// e.	Извлечь элемент из правого конца дека 

double pop_right(Deque *deque) {
    DequeNode *node;
    double value;

    if (deque->right_end == NULL) {
        printf("pop_right error: deque is empty.\n");
        return 0;
    }
    node = deque->right_end;
    value = node->value; 

    deque->right_end = node->left;
    if (deque->right_end !=NULL) { // пустой ли дек
        deque->right_end->right = NULL;
    } else {
        deque->left_end = NULL; // если дек пуст, левый конец тоже NULL
    }

    if (deque->current == node) { // если текущий элемент указывал элемент, который мы удалили
        deque->current = deque->right_end; // Обновляем current на новый правый конец (или NULL)
    }

    free(node);
    return value;
}
// f.	Извлечь элемент из левого конца дека

double pop_left(Deque *deque) {
    DequeNode *node;
    double value;

    if (deque->left_end == NULL) {
        printf("pop_left error: deque is empty.\n");
        return 0;
    }
    node = deque->left_end;
    value = node->value;

    deque->left_end = node->right;
    if (deque->left_end) {
        deque->left_end->left = NULL;
    } else {
        deque->right_end = NULL;
    }

    if (deque->current == node) {
        deque->current = deque->left_end;
    }

    free(node);
    return value;
}

// G??

void move_current_pointer_left(Deque *deque) {
    if (deque->current && deque->current->left) {
        deque->current = deque->current->left;
    }
}
// H??
void move_current_pointer_right(Deque *deque) {
    if (deque->current && deque->current->right) {
        deque->current = deque->current->right;
    }
}

// G???

void move_current_value_left(Deque *deque) {
    if (deque->current && deque->current->left) {
        double temp = deque->current->value;
        deque->current->value = deque->current->left->value;
        deque->current->left->value = temp;
    }
}

// H??

void move_current_value_right(Deque *deque) {
    if (deque->current && deque->current->right) {
        double temp = deque->current->value;
        deque->current->value = deque->current->right->value;
        deque->current->right->value = temp;
    }
}

void print_deque(Deque *deque) {
    DequeNode *node;

    node = deque->left_end;
    printf("Deque: \n");
    while (node) {
        if (node == deque->current) {
            printf("[%g] ", node->value);
        } else {
            printf("%g ", node->value);
        }
        node = node->right;
    }
    printf("\n");
}


int main() {
    Deque *deque = NULL;
    char cmd,temp;
    double value;

    while (1) {
        printf("\nКоманды:\n");
        printf("a. Создать дек с заданным элементом\n");
        printf("b. Очистить дек\n");
        printf("c. Добавить элемент в правый конец дека\n");
        printf("d. Добавить элемент в левый конец дека\n");
        printf("e. Извлечь элемент из правого конца дека\n");
        printf("f. Извлечь элемент из левого конца дека\n");
        printf("g. Переместить указатель на текущий элемент налево\n");
        printf("h. Переместить указатель на текущий элемент направо\n");
        printf("i. Поменять значение текущего элемента со значением слева\n");
        printf("j. Поменять значение текущего элемента со значением справа\n");
        printf("k. Вывести дек на экран\n");
        printf("x. Выход\n");

        printf("Введите команду: ");
        scanf(" %c", &cmd);

        switch (cmd) {
            case 'a':
                printf("Введите начальное значение: ");
                scanf("%lf", &value);
                if (deque) {
                    clear_deque(deque);
                    free(deque);
                }
                deque = create_deque(value);
                break;

            case 'b':
                if (deque) clear_deque(deque);
                break;

            case 'c':
                if (deque) {
                    printf("Введите значение для добавления вправо: ");
                    scanf("%lf", &value);
                    push_right(deque, value);
                } else {
                    printf("Сначала создайте дек (a).\n");
                }
                break;

            case 'd':
                if (deque) {
                    printf("Введите значение для добавления влево: ");
                    scanf("%lf", &value);
                    push_left(deque, value);
                } else {
                    printf("Сначала создайте дек (a).\n");
                }
                break;

            case 'e':
                if (deque) pop_right(deque);
                else printf("Сначала создайте дек (a).\n");
                break;

            case 'f':
                if (deque) pop_left(deque);
                else printf("Сначала создайте дек (a).\n");
                break;

            case 'g':
                if (deque) move_current_pointer_left(deque);
                else printf("Сначала создайте дек (a).\n");
                break;

            case 'h':
                if (deque) move_current_pointer_right(deque);
                else printf("Сначала создайте дек (a).\n");
                break;

            case 'i':
                if (deque) move_current_value_left(deque);
                else printf("Сначала создайте дек (a).\n");
                break;

            case 'j':
                if (deque) move_current_value_right(deque);
                else printf("Сначала создайте дек (a).\n");
                break;

            case 'k':
                if (deque) print_deque(deque);
                else printf("Сначала создайте дек (a).\n");
                break;

            case 'x':
                if (deque) {
                    clear_deque(deque);
                    free(deque);
                }
                printf("Выход.\n");
                return 0;

            default:
                printf("Неверная команда.\n");
        }

        if (deque) {print_deque(deque);
		
		}
		printf("Нажмите Enter, чтобы продолжить...");
		getchar();
		getchar();
    }

    return 0;
}




