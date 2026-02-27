#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // для bool

struct node
{
    int data; // Пусть в качестве данных у нас будут числа
    struct node *next; // Указатель на следующий узел, если нет узла = NULL
};

// Чтобы каждый раз не писать struct node будем писать node_t
typedef struct node node_t;

// Ф-ия выделяет память под новый элемент списка, 
// зануляет указатель на следующий (т.к. данный узел не имеет следующего) 
// и присваивает значение data из аргумента data
node_t *newNode(int data) {

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// Вывод на экран списка
void printList(node_t *head) {

    node_t* cur = head;
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// Функция поиска длины списка
int lengthList(node_t* head)
{
    int length = 0;

    node_t* cur = head;
    while (cur != NULL) {
        length++;
        cur = cur->next;
    }
    return length;
}

// Функция поиска, проходим по списку, если элемент в списке вернем true иначе false
bool searchList(node_t* head, int target)
{
    while (head != NULL) {
        if (head->data == target) {
            return true; // Нашли
        }
        head = head->next;
    }
    return false; // Не нашли
}

// Функция для вставки в начало списка
node_t* appendFront(node_t* head, int data)
{
    node_t* new_node = newNode(data);
    new_node->next = head;
    return new_node;
}

// Функция по удалению первого узла
node_t* removeFront(node_t* head)
{
    if (head == NULL) {
        return NULL;
    }

    node_t* temp = head;
    head = head->next;

    free(temp);

    return head;
}

// Функция для вставки нового элемента в конец списка
node_t* appendBack(node_t* head, int data)
{
    node_t* new_node = newNode(data);

    if (head == NULL) {
        return new_node;
    }

    node_t* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = new_node;

    return head;
}

// Функция для удаления элемента из конца списка
node_t* removeBack(node_t* head)
{
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node_t *second_last = head; // предпоследний узел
    while(second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    // Освобождаем последний узел
    free(second_last->next);

    // Предпоследний теперь становится последним
    second_last->next = NULL;

    return head;
}

int main(void) {

    // Создадим 3 узла с данными 1 2 3, данные могут быть любыми, 
    // но чтоб было по красоте сделаем данные равным номеру узла.
    node_t *node1 = newNode(1);
    node_t *node2 = newNode(2);
    node_t *node3 = newNode(3);

    // свяжем узлы 1 и 2, 2 и 3
    node1->next = node2;
    node2->next = node3;
    // Получится список из трех элементов 1 -> 2 -> 3 -> NULL

    // удалим узел 2 из списка
    node1->next = node2->next; // связываем 1 и 3 узлы
    free(node2);
    node2 = NULL;
    // Получится список 1 -> 3 -> NULL

    node_t* head = NULL; // Список пустой
    head = node1; // привяжемся к списку 1 -> 3

    printList(head); // выведет 1 -> 3 -> NULL

    printf("appendFront(): ");
    head = appendFront(head, 0);
    printList(head); // выведет 0 -> 1 -> 3 -> NULL

    printf("removeFront(): ");
    head = removeFront(head);
    printList(head); // выведет 1 -> 3 -> NULL

    printf("appendBack(): ");
    head = appendBack(head, 4);
    printList(head); // выведет 1 -> 3 -> 4 -> NULL

    printf("removeBack(): ");
    head = removeBack(head);
    printList(head); // выведет 1 -> 3 -> NULL

}