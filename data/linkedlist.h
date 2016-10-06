#ifndef _LINKEDLIST_BUTLER_H_
#define _LINKEDLIST_BUTLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _linknode{
	void *data;
	struct _linknode *next;
}linknode;

typedef struct {
	linknode *head;
	int size;
}LinkedList;

linknode *createLinkNode(void *);

LinkedList *createLinkedList(void *);
void ll_addToFront(LinkedList *, void *);
void ll_addAfterIndex(LinkedList *, void *, int);
void ll_removeFirst(LinkedList *);
void ll_removeIndex(LinkedList *, int);

void printLinkedList(LinkedList *);

#endif
