#include<stdbool.h>

#ifndef ARRAY_H
#define ARRAY_H

typedef struct array *  Collection;

Collection mkEmptyCollection();
Collection mkNonEmptyCollection(int* items, int len); // mostly for testing

void append(Collection c, int element); // add to end
int length(Collection c);
int get(Collection c, int index);
void set(Collection c, int index, int value);
bool contains(Collection c, int element);

#endif
