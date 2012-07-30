#include<stdio.h>

void printArray(int X[], int len)
{
    int i;
    printf("[");
    for(i = 0; i < len; i++) // i goes from 0 to len 
        printf("%d, ", X[i]); //print A[i] where i goes from 0 to 4
    printf("]\n");
}

int sum(int X[], int len)
{
    int i;
    int total = 0;
    for(i = 0; i < len; i++)
    {
        total = total + X[i];
    }
    return total;
}

void main()
{
    int A[] = {5, 1, 3, 7, 10};
    int B[] = {4, 3};

    printArray(A, 5);
    printArray(B, 2);

    printf("The sum of A is %d\n", sum(A, 5));
}
