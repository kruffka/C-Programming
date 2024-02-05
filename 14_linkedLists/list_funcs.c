#include <stdio.h>
#include <malloc.h>

typedef struct node node_t;

// Односвязный список
struct node {
    int val;
    node_t *next;
};

node_t *new_node(int val) {

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = NULL;

    return new_node;
}

void insert(node_t *prev, node_t *next) {

}

void pop() {

}

// recursive
void free_list(node_t *node) {

    if (node) {
        free_list(node->next);
        free(node);
    }

}

void print_list(node_t *node) {
    
    while (node) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {


    node_t *list_p, *my_list = NULL;
    list_p = new_node(0);
    my_list = list_p;
    list_p->next = new_node(1);
    list_p = list_p->next;
    list_p->next = new_node(2);
    list_p = list_p->next;
    list_p->next = new_node(3);

    print_list(my_list);


    free_list(my_list);
}