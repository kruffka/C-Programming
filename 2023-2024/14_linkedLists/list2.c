#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node node_t;

// Многосвязный список
struct node {
    node_t *prev;
    int val;
    node_t *next;
};

int main() {

    node_t *list_p;

    node_t *first_up = (node_t *)malloc(sizeof(node_t));
    first_up->val = 0;
    first_up->next = NULL;
    first_up->prev = NULL;

    /*
    |-----------------|
    | null | 0 | null |
    |-----------------|
    */
    node_t *second_up = (node_t *)malloc(sizeof(node_t));
    second_up->val = 1;
    second_up->next = NULL;
    second_up->prev = NULL;
    /*
    |-----------------|
    | null | 1 | null |
    |-----------------|
    */

    first_up->next = second_up;
    /*
    |-----------------|              |-----------------|
    | null | 0 |  =---|------------> | null | 1 | null |
    |-----------------|              |-----------------|
    */

    list_p = first_up;

    /*
     list_p          first_up                        second_up
     ---       |-----------------|              |-----------------|
    | =-|----->| null | 0 |  =---|------------> | null | 1 | null |
     ---       |-----------------|              |-----------------|
    */
    while (list_p != NULL) {
        printf("%d %p %p\n", list_p->val, list_p->prev, list_p->next);
        list_p = list_p->next;
    }


    node_t *first_down = (node_t *)malloc(sizeof(node_t));
    first_down->val = 3;
    first_down->next = NULL;
    first_down->prev = NULL;

    /*
    |-----------------|
    | null | 3 | null |
    |-----------------|
    */
    node_t *second_down = (node_t *)malloc(sizeof(node_t));
    second_down->val = 2;
    second_down->next = NULL;
    second_down->prev = NULL;
    /*
    |-----------------|
    | null | 2 | null |
    |-----------------|
    */
    second_down->prev = first_down;

    /*
    |-----------------|              |-----------------|
    | null | 3 | null |<-------------|---=  | 2 | null |
    |-----------------|              |-----------------|
    */
    
    list_p = second_down;
    /*   first_down                      second_down           list_p
    |-----------------|              |-----------------|       ---
    | null | 3 | null |<-------------|---=  | 2 | null |<-----|-= |
    |-----------------|              |-----------------|       ---
    */

    while (list_p != NULL) {
        printf("%d %p %p\n", list_p->val, list_p->prev, list_p->next);
        list_p = list_p->prev;
    }

    second_up->prev = second_down;
    first_down->prev = first_up;

    /*
          first_up                        second_up
    |-----------------|              |-----------------|
    | null | 0 |  =---|------------> | |=|  | 1 | null |
    |--|--------------|              |--|--------------|
       ^                                |
       |                                |
       | first_down                     V second_down           
    |--|--------------|              |-----------------|
    | |=|  | 2 | null |<-------------|---=  | 3 | null |
    |-----------------|              |-----------------|  
    */

   list_p = first_down;

    while (1) {
        printf("%d %p %p\n", list_p->val, list_p->prev, list_p->next);
        if (list_p->prev)
            list_p = list_p->prev;
        else if (list_p->next)
            list_p = list_p->next;
        else
            exit(1);
        
        sleep(1);

    }



    free(first_up);
    free(first_down);
    free(second_up);
    free(second_down);
    
}