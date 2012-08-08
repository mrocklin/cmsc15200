#include<stdbool.h>

#ifndef LIST_H 
#define LIST_H

typedef struct array *  List;

List mkEmptyList();
List mkNonEmptyList(int* items, int len); // mostly for testing

void append(List c, int element); // add to end
int length(List c);
int get(List c, int index);
void set(List c, int index, int value);
bool contains(List c, int element);

#endif
