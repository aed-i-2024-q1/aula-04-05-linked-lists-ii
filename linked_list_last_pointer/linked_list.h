#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "element.h"

#include <stdbool.h>

typedef struct LinkedList LinkedList;

LinkedList *list_create();
bool list_destroy(LinkedList *list);
void list_insertFirst(LinkedList *list, Element element);
void list_insertLast(LinkedList *list, Element element);
void list_insertAfter(LinkedList *list, int position, Element element);
void list_removeFirst(LinkedList *list);
void list_removeLast(LinkedList *list);
void list_removeAt(LinkedList *list, int position);
int list_get(LinkedList *list, int position);
int list_size(LinkedList *list);
int list_isEmpty(LinkedList *list);
void list_print(LinkedList *list);

#endif