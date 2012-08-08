#include "stats.h"
#include<assert.h>
#include<stdio.h>

void test_mean()
{
    float F[] = {1,2,3};
    Array X = mkNonEmptyArray(F, 3);
    assert(fEq(mean(X), 2));
}
void test_std()
{
    float F[] = {1,2,3};
    Array X = mkNonEmptyArray(F, 3);
    assert(fEq(std(X), 1));
}
void test_zScores()
{
    float in[] = {1,2,3};
    float out[] = {-1,0,1};
    Array X = mkNonEmptyArray(in, 3);
    Array Z = mkNonEmptyArray(out, 3);
    assert(equal(zScores(X), Z));
}
void main()
{
    test_mean();
    test_std();
    test_zScores();

    printf("Tests pass!\n");
}
