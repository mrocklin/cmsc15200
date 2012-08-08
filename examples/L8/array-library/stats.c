#include "array.h"
#include<math.h>

struct array
{
    float *data;
    int len;
};
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
    return mulScalar(addScalar(A, -mean(A)), 1/std(A));
}
