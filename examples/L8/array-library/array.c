#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>
#include "array.h"

struct array
{
    float *data;
    int len;
};

bool fEq(float a, float b)
{
    return fabs((a-b)/b) < .001 || a==b ;
}

Array mkEmptyArray(int len)
{
    // Make space for the pointer to data and the int length
    Array A = malloc(sizeof(struct array));
    
    // Make empty array. Set A->data to point to it
    A->data = malloc(sizeof(float) * len);

    // Fill A->data with zeros
    int i;
    for(i = 0; i < len; i++)
        A->data[i] = 0;

    A->len = len;

    return A;
}
Array mkNonEmptyArray(float *data, int len)
{
    Array out = mkEmptyArray(len);
    int i;
    for(i = 0; i < len; i++) // Copy data to A->data
        out->data[i] = data[i];
    return out;
}

bool equal(Array A, Array B)
{
    if (A->len != B->len)
        return false;
    int i;
    for(i = 0; i < A->len; i++)
        if (!fEq(A->data[i], B->data[i]))
            return false;
    return true;
}

Array addScalar(Array A, float x)
{
    Array out = mkEmptyArray(A->len);
    int i;
    for(i = 0; i < A->len; i++)
        out->data[i] = A->data[i] + x;
    return out;
}

Array mulScalar(Array A, float x)
{
    Array out = mkEmptyArray(A->len);
    int i;
    for(i = 0; i < A->len; i++)
        out->data[i] = A->data[i] * x;
    return out;
}

Array powScalar(Array A, int power)
{
    Array out = mkEmptyArray(A->len);
    int i;
    for(i = 0; i < A->len; i++)
        out->data[i] = pow(A->data[i], power);
    return out;
}

Array addArray(Array A, Array B)
{
    assert(A->len == B->len);

    Array out = mkEmptyArray(A->len);
    int i;
    for(i = 0; i < A->len; i++)
        out->data[i] = A->data[i] + B->data[i];
    return out;
}

Array mulArray(Array A, Array B)
{
    assert(A->len == B->len);

    Array out = mkEmptyArray(A->len);
    int i;
    for(i = 0; i < A->len; i++)
        out->data[i] = A->data[i] * B->data[i];
    return out;
}


float sum(Array A)
{
    int i;
    float total = 0;
    for(i = 0; i < A->len ; i++)
        total += A->data[i];
    return total;
}
float mean(Array A)
{
    return sum(A) / A->len;
}
float std(Array A)
{
    return sqrt(sum(powScalar(addScalar(A, -mean(A)), 2)) / (A->len-1));
}
Array zScores(Array A)
{
    return    mulScalar(addScalar(A, -mean(A)), 1/std(A));
}
