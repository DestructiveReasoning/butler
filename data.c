#include "data.h"

linknode *createLinkNode(void *data) {
	linknode *node = (linknode *)malloc(sizeof(linknode));
	node->data = data;
	node->next = NULL;
	return node;
}

LinkedList *createLinkedList(void *data) {
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	if(data) {
		list->head = createLinkNode(data);
		list->size = 1;
	}
	else {
		list->head = NULL;
		list->size = 0;
	}
}

void addToFront(LinkedList *list, void *data) {
	linknode *node = createLinkNode(data);
	node->next = list->head;
	list->head = node;
	list->size = list->size + 1;
}

void removeFirst(LinkedList *list) {
	linknode *node = list->head->next;
	list->head = node;
	list->size = list->size - 1;
}

void printLinkedList(LinkedList *list) {
	linknode *node = list->head;
	while(node->next != NULL) {
		printf("%d -> ",node->data);
		node = node->next;
	}
	printf("%d\n",node->data);
}
