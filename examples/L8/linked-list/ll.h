#include<stdbool.h>

#ifndef LL_H
#define LL_H

typedef struct node *       Node;

int length(Node n);
Node prepend(Node n, int item);
Node append(Node n, int item);
int get(Node n, int index);
void set(Node n, int index, int value);
bool contains(Node n, int value);

#endif
