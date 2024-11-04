#include <stdio.h>

// Самое важное что следует запомнить при работе с указателями и функциями это то, что чтобы поменять что-либо
// внутри функции через аргумент, то необходимо передать это через адрес. 
// Например если хотим изменить значение указателя в функции, то необходимо передать адрес переменной указателя

// Меняем значение переменной ptr
void set_ptr_value_to_NULL(int **ptr) {
    *ptr = NULL;
}

// Так значение переменной ptr не изменится после вызова функции
void set_ptr_value_to_NULL_wrong(int *ptr) {
    ptr = NULL;
}

void swap(double *a, double *b); // Обьявляем прототип функции swap(), чтобы main() ее смог найти

// функция, что возвращает сумму двух целых чисел
int sum(int a, int b) {
    return a + b;
}

// Функция, что записываем сумму двух чисел в третий аргумент res
void add(int a, int b, int *res) {
    *res = a + b;
}

int main(void) {

    // 1.
    int a = sum(5, 3);
    int res;
    add(5, 3, &res); // передаем адрес переменной res в функцию, чтобы изменить res внутри функции
    printf("a = %d, res = %d\n", a, res);

    // 2.
    double t1 = 5.4, t2 = 1.2;
    printf("t1 = %lf, t2 = %lf\n", t1, t2);
    swap(&t1, &t2); // Поменяем местами значения t1 и t2 передав адреса в функцию swap()
    printf("t1 = %lf, t2 = %lf\n", t1, t2);

    // 3. 
    // ВАЖНО: если хотим поменять переменную в функции, то необходимо передать ее адрес
    // Если функцию вызвать как set_ptr_value_to_NULL(ptr), то мы не изменим значение переменной ptr внутри функции
    int *ptr = &a;
    printf("ptr = %p\n", ptr);
    set_ptr_value_to_NULL_wrong(ptr); // ptr не поменяется
    printf("ptr = %p\n", ptr);

    set_ptr_value_to_NULL(&ptr); // ptr поменяется
    printf("ptr = %p\n", ptr); // NULL (nil)

    return 0;
}


// Функция, что поменяет значения двух double переменных местами, т.е. в a будет лежать значение b и наоборот
void swap(double *a, double *b) {
    double tmp = *b;
    *b = *a;
    *a = tmp;
}