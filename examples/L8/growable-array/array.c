#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>
#include "array.h"

struct array
{
    int *data;
    int len;
};

Collection mkEmptyCollection()
{
    // Make space for the pointer to data and the int length
    Collection C = malloc(sizeof(struct array));

    C->len = 0;
    C->data = NULL;
    
    return C;
}

void append(Collection C, int item)
{
    int* oldData = C->data;
    C->data = malloc(sizeof(int) * (C->len + 1));

    // Copy old values over
    int i;
    for(i = 0; i < C->len; i++)
        C->data[i] = oldData[i];

    C->data[C->len] = item; // add new item
    C->len = C->len + 1;
}

int get(Collection C, int index)
{
    return C->data[index];
}
void set(Collection C, int index, int value)
{
    C->data[index] = value;
}
int length(Collection C)
{
    return C->len;
}
bool contains(Collection C, int value)
{
    int i;
    for(i = 0; i < C->len; i++)
        if (C->data[i] == value)
            return true;
    return false;
}

