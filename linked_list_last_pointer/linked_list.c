#include "linked_list.h"

#include <stdlib.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct LinkedList {
    Node* first;
    Node* last;
};

LinkedList* list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    list->first = NULL;
    list->last = NULL;

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

}

void list_insertAfter(LinkedList *list, int position, Element element) {
    Node* cur = list->first;
    int i = 0;

    while (cur != NULL && i < position) {
        cur = cur->next;
        i++;
    }

    if (cur != NULL) {
        Node* newNode = malloc(sizeof(Node));

        newNode->element = element;
        newNode->next = cur->next;
        cur->next = newNode;

        if (cur == list->last) {
            list->last = newNode;
        }
    }
}

void list_removeFirst(LinkedList *list) {
    if (list->first != NULL) {
        Node* trash = list->first;

        list->first = list->first->next;

        if (list->first == NULL) {
            list->last = NULL;
        }

        free(trash);
    }
}

void list_removeLast(LinkedList *list) {
    if (list->first != NULL) {
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
    }
}
void list_removeAt(LinkedList *list, int position) {
    if (position == 0) {
        list_removeFirst(list);
    } else {
        Node* cur = list->first;
        int i = 0;

        while (cur != NULL && i < position - 1) {
            cur = cur->next;
            i++;
        }

        if (cur != NULL && cur->next != NULL) {
            Node* trash = cur->next;

            cur->next = cur->next->next;

            if (trash == list->last) {
                list->last = cur;
            }

            free(trash);
        }
    }

}

int list_get(LinkedList *list, int position) {
    Node* cur = list->first;
    int i = 0;

    while (cur != NULL && i < position) {
        cur = cur->next;
        i++;
    }

    if (cur != NULL) {
        return cur->element;
    } else {
        return -1;
    }
}

int list_size(LinkedList *list) {
    Node* cur = list->first;
    int size = 0;

    while (cur != NULL) {
        cur = cur->next;
        size++;
    }

    return size;

}

int list_isEmpty(LinkedList *list) {
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