#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct LinkedList {
    Node* first;
    Node* last;
    int size;
};

LinkedList* list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;

}

void list_destroy(LinkedList *list) {
    Node* cur = list->first;

    while (cur != NULL) {
        Node* trash = cur;

        cur = cur->next;
        free(trash);
    }

    free(list);
}

void list_insertFirst(LinkedList *list, Element element) {
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = list->first;
    list->first = newNode;
    if (list->last == NULL) {
        list->last = newNode;
    }
    list->size++;
}

void list_insertLast(LinkedList *list, Element element) {
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = NULL;

    if (list->last != NULL) {
        list->last->next = newNode;
    }

    list->last = newNode;

    if (list->first == NULL) {
        list->first = newNode;
    }
    list->size++;
}

bool list_insertAfter(LinkedList *list, int position, Element element) {
    if (position < 0 || position >= list->size) {
        return false;
    }

    Node* cur = list->first;
    int i = 0;

    while (i < position) {
        cur = cur->next;
        i++;
    }

    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = cur->next;
    cur->next = newNode;

    if (cur == list->last) {
        list->last = newNode;
    }
    list->size++;

    return true;
}

bool list_removeFirst(LinkedList *list) {
    if (list->first == NULL) {
        return false;
    }
    
    Node* trash = list->first;

    list->first = list->first->next;
    if (list->first == NULL) {
        list->last = NULL;
    }
    free(trash);
    list->size--;

    return true;
}

bool list_removeLast(LinkedList *list) {
    if (list->first = NULL) {
        return false;    
    }

    if (list->first == list->last) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
    } else {
        Node* cur = list->first;

        while (cur->next != list->last) {
            cur = cur->next;
        }

        Node* trash = list->last;

        list->last = cur;
        list->last->next = NULL;

        free(trash);
    }

    return true;
}

bool list_removeAt(LinkedList *list, int position) {
    if (position < 0 || position >= list->size) {
        return false;
    }   
    if (position == 0) {
        return list_removeFirst(list);
    } else {
        Node* prev = list->first;
        int i = 0;

        while (i < position - 1) {
            prev = prev->next;
            i++;
        }

        Node* trash = prev->next;

        prev->next = trash->next;
        if (trash == list->last) {
            list->last = prev;
        }
        free(trash);

        return true;
    }
}

Element list_get(LinkedList *list, int position) {
    Node* cur = list->first;
    int i = 0;

    while (cur != NULL && i < position) {
        cur = cur->next;
        i++;
    }

    if (cur != NULL) {
        return cur->element;
    } else {
        return ELEMENT_NULL;
    }
}

int list_size(LinkedList *list) {
    return list->size;
}

bool list_isEmpty(LinkedList *list) {
    return list->first == NULL;
}

void list_print(LinkedList *list) {
    Node* cur = list->first;

    while (cur != NULL) {
        element_print(cur->element);
        if (cur->next != NULL)
            printf(" -> ");
        cur = cur->next;
    }

    printf("\n");
}