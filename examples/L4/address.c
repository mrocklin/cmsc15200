#include<stdio.h>

void main()
{
    int A[4] = {5,1,3,7};
    printf("%u\n", A);
    printf("A[0] == %d\n", *(A));
    printf("A[1] == %d\n", *(A + 1));
    printf("A == %u\n", A);
    printf("A+1 == %u\n", A+1);
}
