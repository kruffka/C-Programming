#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

// Односвязный список
struct node {
    int val; // value - некоторое целочисленное значение
    node_t *next; // указатель на структуру node_t (будет указывать на следующий элемент либо равна NULL)
};

// Выделяет память под новый элемент списка, зануляет указатель на следующий и присваивает значение val из аргумента val
node_t *new_node(int val) {

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = NULL;

    return new_node;
}

// Вставляем элемент в конец списка
void push_back(node_t **list, int val) {
    node_t *tmp = *list;
    if (tmp == NULL) {
        *list = new_node(val);
        return;
    }
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = new_node(val);
}

// Удаляем элемент вначале списка
void pop_front(node_t **list) {

    node_t *head = *list;
    node_t *new_list = head->next;
    free(head);
    *list = new_list;
}


// Вставляем новый элемент посреди списка
void insert(node_t *prev, int val) {
    if (prev == NULL) {
        printf("prev node is NULL!\n");
        return;
    }
 
    // Выделяем память под новый элемент
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    // Заполняем новый элемент
    new_node->val = val;
    // Вставляем новый элемент между двумя
    new_node->next = prev->next;
    prev->next = new_node;

}


// Рекурсивное освобождение списка
void free_list(node_t *node) {

    if (node) {
        free_list(node->next);
        free(node);
    }

}

// Не рекурсивный вывод на экран списка
void print_list(node_t *node) {
    
    while (node) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: ./a.out N\n");
        return -1;
    }
    int N = atoi(argv[1]);

    node_t *prev_node = NULL, *my_list = NULL;

    // Создаем список из N элементов
    for (int i = 0; i < N; i++) {
        node_t *cur_node = NULL;
        if (prev_node == NULL) {
            cur_node = new_node(i);
            my_list = cur_node;
        } else {
            cur_node = new_node(i);
            prev_node->next = cur_node;
        }
        prev_node = cur_node;
    }

    // Выводим на экран наш список
    printf("My list:\n");
    print_list(my_list);

    // push_back
    printf("List after push back:\n");
    push_back(&my_list, 123);
    push_back(&my_list, 42);

    print_list(my_list);

    printf("List after pop front:\n");
    pop_front(&my_list);

    print_list(my_list);

    printf("List after insert after third elem:\n");
    node_t *tmp = my_list;
    for (int i = 0; i < 3; i++) {
        tmp = tmp->next;
    }
    insert(tmp, 555);
    print_list(my_list);

    // Удаление списка
    free_list(my_list);
    my_list = NULL;


}