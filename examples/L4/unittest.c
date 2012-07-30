#include<stdio.h>
#include<assert.h>


int sum(int X[], int len)
{
    int i;
    int total = 0;
    for(i = 0; i < len; i++)
        total += X[i];
    return total;
}
// This is a unit test
void test_sum()
{
    int A[] = {1,2,3};
    assert(sum(A, 3) == 6);
    int B[] = {-1, 1};
    assert(sum(B, 2) == 0);
    int C[] = {};
    assert(sum(C, 0) == 0);
}

void main()
{
    test_sum();
    printf("Tests pass!\nEverything is ok!\n");
}
