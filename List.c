#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} *LIST_PTR;

void append(LIST_PTR *head_ptr, int new_data) {
    LIST_PTR new_element = (LIST_PTR) malloc(sizeof(struct list));
    new_element->data = new_data;
    new_element->next = NULL;
    if(*head_ptr == NULL) {
        *head_ptr = new_element;
        return;
    }
    LIST_PTR tail = *head_ptr;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = new_element;
    return;
}

void printlist(LIST_PTR head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}



int main(void) {

    LIST_PTR head = NULL;
    append(&head,1);
    append(&head,2);
    append(&head,1);
    append(&head,2561);
    append(&head,12342);
    append(&head,23);
    append(&head,5);
    append(&head,2);
    printlist(head);
    return 0;
}
