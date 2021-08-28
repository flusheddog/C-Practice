#include <stdio.h>
#include <stdlib.h>

typedef struct listElem {
    int data;
    struct listElem *next;
} ListElem;
typedef ListElem *LIST_PTR;

typedef struct List {
    struct listElem *head;
    struct listElem *tail;
} List;

void init_list(List *list) {
    list->head = NULL;
    list->tail = NULL;
}

void pop_front(List *list) {
    LIST_PTR temp = list->head;
    list->head = temp->next;
    free(temp);
}


void pop_back(List* list) {
	ListElem temp = list->head;
	if (list->head->next == NULL) {
		list->head = NULL;
		list->tail = NULL;
		return;
	}
	while (temp->next != list->tail) {
		temp = temp->next;
	}
	list->tail = temp;
	temp = temp->next;
	free(temp);
	list->tail->next = NULL;
}

int front(List *list) {
    return list->head->data;
}

void push_front(List *list, int new_data) {
    LIST_PTR new_element = (LIST_PTR) malloc(sizeof(*new_element));
    new_element->data = new_data;
    new_element->next = list->head;
    list->head = new_element;
}


void push_back(List *list, int new_data) {
    LIST_PTR new_element = (LIST_PTR) malloc(sizeof(*new_element));
    new_element->data = new_data;
    new_element->next = NULL;
    if(list->head == NULL) {
        list->head = new_element;
        list->tail = list->head;
        return;
    }

    list->tail->next = new_element;
    list->tail = list->tail->next;
}

void print_list(List list) {
    while(list.head != NULL) {
        printf("%d ", list.head->data);
        list.head = list.head->next;
    }
    printf("\n");
}

int main(void) {
    List list;
    init_list(&list);

    push_back(&list,13);

    push_back(&list,14);
    push_back(&list,17);
    push_back(&list,1312);
    push_back(&list,1);
    push_front(&list,45);
    printf("%d\n",front(&list));
    print_list(list);
    pop_front(&list);
    print_list(list);

    return 0;
}