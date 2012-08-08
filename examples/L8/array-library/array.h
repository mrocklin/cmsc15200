#include<stdbool.h>

#ifndef ARRAY_H
#define ARRAY_H

typedef struct array *  Array;

bool fEq(float a, float b);
Array mkEmptyArray(int len);
Array mkNonEmptyArray(float *data, int len);
bool equal(Array A, Array B);
Array addScalar(Array A, float x);
Array mulScalar(Array A, float x);
Array powScalar(Array A, int power);
Array addArray(Array A, Array B);
Array mulArray(Array A, Array B);
float sum(Array A);
float mean(Array A);
float std(Array A);
Array zScores(Array A);

#endif
