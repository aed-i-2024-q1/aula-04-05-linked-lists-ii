#ifndef ELEMENT_H
#define ELEMENT_H

#include <limits.h>

typedef int Element;

#define ELEMENT_NULL INT_MIN;

int element_compare(Element element1, Element element2);
void element_print(Element element);

#endif