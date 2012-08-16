#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>

struct array
{
    int *data;
    int len;
};
typedef struct array *      Array;

Array mkEmptyList()
{
    // Make space for the pointer to data and the int length
    Array A = malloc(sizeof(struct array));

    A->len = 0;
    A->data = NULL;
    
    return A;
}

Array append(Array A, int item)
{
    int* oldData = A->data;
    A->data = malloc(sizeof(int) * (A->len + 1));

    // Copy old values over
    int i;
    for(i = 0; i < A->len; i++)
        A->data[i] = oldData[i];

    A->data[A->len] = item; // add new item
    A->len = A->len + 1;
    return A;
}

int get(Array A, int index)
{
    return A->data[index];
}
void set(Array A, int index, int value)
{
    A->data[index] = value;
}
int length(Array A)
{
    return A->len;
}
bool contains(Array A, int value)
{
    int i;
    for(i = 0; i < A->len; i++)
        if (A->data[i] == value)
            return true;
    return false;
}
