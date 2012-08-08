#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"array.h"

void test_sum()
{
    float F[] = {1,2,3};
    Array X = mkNonEmptyArray(F, 3);
    assert(fEq(sum(X), 6));
}
void test_addScalar()
{
    float in[] = {1,2,3};
    float out[] = {2,3,4};
    Array X = mkNonEmptyArray(in, 3);
    Array Xp1 = mkNonEmptyArray(out, 3);
    assert(equal(addScalar(X, 1), Xp1));
}
void test_addArray()
{
    float in[] = {1,2,3};
    float in2[] = {3,2,1};
    float out[] = {4,4,4};
    Array X = mkNonEmptyArray(in, 3);
    Array Y = mkNonEmptyArray(in2, 3);
    Array Z = mkNonEmptyArray(out, 3);
    assert(equal(addArray(X, Y), Z));
}


void main()
{
    test_addScalar();
    test_addArray();
    test_sum();

    printf("Tests pass!\n");
}
