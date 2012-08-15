#include<stdbool.h>

#ifndef LL_H
#define LL_H

typedef struct node *       List;

int length(List n);
List mkEmptyList();
List mkList(int item);
List prepend(List n, int item);
List append(List n, int item);
int get(List n, int index);
void set(List n, int index, int value);
bool contains(List n, int value);

#endif
