#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

// Двусвязный список
struct node {
    node_t *prev; // указатель на структуру node_t (указывает на предыдущий элемент)
    int val; // value - некоторое целочисленное значение
    node_t *next; // указатель на структуру (будет указывать на следующий элемент либо равна NULL)
};

// Выделяет память под новый элемент списка, зануляет указатель на следующий и присваивает значение val из аргумента val
node_t *new_node(int val) {

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->prev = NULL;
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
            prev_node = cur_node;
            my_list = cur_node;
        } else {
            cur_node = new_node(i);
            prev_node->next = cur_node;
            cur_node->prev = prev_node;
        }
        prev_node = cur_node;
    }

    // Выводим на экран наш список
    printf("My list:\n");
    print_list(my_list);

    printf("Press 'a' to go left and 'd' to go right. Any other key to exit\n");
    node_t *list_ptr = my_list;
    while(1) {
        char key = ' ';

        printf("Value: %d; Addr prev: %p next: %p\n", list_ptr->val, list_ptr->prev, list_ptr->next);
        scanf("%c%*c", &key);

        printf("Key entered: '%c'\n", key);
        if (key == 'a') {
            if (list_ptr->prev)
                list_ptr = list_ptr->prev;
            else 
                printf("Can't go here: prev is NULL\n");
            
        } else if(key == 'd') {
            if (list_ptr->next)
                list_ptr = list_ptr->next;
            else
                printf("Can't go here: next is NULL\n");

        } else {
            printf("Exiting..\n");
            break;
        }
    }

    // Удаление списка
    free_list(my_list);
    my_list = NULL;


}