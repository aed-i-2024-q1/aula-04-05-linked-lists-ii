#include "element.h"

#include <stdio.h>

void element_print(Element element) {
    printf("%d", element);
}

int element_compare(Element element1, Element element2) {
    return element1 - element2;
}