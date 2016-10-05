#ifndef _DATA_BUTLER_H_
#define _DATA_BUTLER_H_

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
void addToFront(LinkedList *, void *);
void addAfterIndex(LinkedList *, void *, int);
void removeFirst(LinkedList *);
void removeListIndex(LinkedList *, int);
void printLinkedList(LinkedList *);

#endif
