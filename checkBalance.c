#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#pragma warning(disable : 4996)

typedef struct listElem {
	int data;
	struct listElem* next;
}listElem;
typedef listElem *ListElem;

typedef struct List {
	struct listElem* tail;
	struct listElem* head;
} List;

void init_list(List* list) {
	list->head = NULL;
	list->tail = NULL;
}

void push_front(List* list, int new_data) {
	ListElem new_element = (ListElem) malloc(sizeof(*new_element));
	new_element->data = new_data;
	new_element->next = list->head;
	list->head = new_element;
}

void pop_front(List* list) {
	ListElem temp = list->head;
	list->head = temp->next;
	free(temp);
}

int check_balance(char str[]) {
	List list;
	init_list(&list);
	int size = strlen(str); 
	for (int i = 0; i < size; i++) {
		if (str[i] == '{') {
			push_front(&list, 1);
		}
		if (str[i] == '(') {
			push_front(&list, 2);
		}
		if (str[i] == '}') {
			if (list.head == NULL || list.head->data != 1){
				return i;
			} else {
				pop_front(&list);
			}
		}
		if (str[i] == ')') {
			if (list.head == NULL || list.head->data != 2) {
				return i;
			}
			else {
				pop_front(&list);
			}
		}
		
	}
	if (list.head != NULL) {
		return size;
	} else { 
		return -1;
	}	
}

int main() {

	int i = check_balance("dfafdf{f()(()fds)fsd(f");
	printf("%d", i);
	return 0;
}
