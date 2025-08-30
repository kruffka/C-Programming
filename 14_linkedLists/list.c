#include <stdio.h>
#include <malloc.h>

typedef struct node node_t;

// Односвязный список
struct node {
    int val;
    node_t *next;
};

int main() {

    node_t *list_p;

    node_t *first = (node_t *)malloc(sizeof(node_t));
    first->val = 0;
    first->next = NULL;
    /*
    |----------|
    | 0 | null |
    |----------|
    */
    node_t *second = (node_t *)malloc(sizeof(node_t));
    second->val = 1;
    second->next = NULL;
    /*
    |----------|
    | 1 | null |
    |----------|
    */
    first->next = second;

    /*
    |----------|              |----------|
    | 0 |  =---|------------> | 1 | null |
    |----------|              |----------|
    */

    list_p = first;
/*
list_p       first                    second    
 ---     |----------|              |----------|
| =-|--->| 0 |  =---|------------> | 1 | null |
 ---     |----------|              |----------|
*/
    while (list_p != NULL) {
        printf("%d\n", list_p->val);
        list_p = list_p->next;
    }


    free(first);
    free(second);
    // exit(0);

    int num_of_nodes = 5;
    node_t *prev = (node_t *)malloc(sizeof(node_t));
    prev->next = NULL;
    prev->val = -1;

    // запомним первый элемент
    node_t *head = prev;

    for (int i = 0; i < num_of_nodes; i++) {
        // выделяем память под ноду
        node_t *tmp = (node_t *)malloc(sizeof(node_t));
        tmp->val = i;
        tmp->next = NULL;

        // связываем с предыдущей
        prev->next = tmp;
        prev = prev->next;

    }

    list_p = head->next;
    while (list_p != NULL) {
        printf("%d\n", list_p->val);
        list_p = list_p->next;
    }

    // освобождаем память
    list_p = head;
    while (list_p != NULL) {
        node_t *tmp = list_p;
        list_p = list_p->next;
        free(tmp);
    }    
}