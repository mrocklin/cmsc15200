#include<stdio.h>

//  Compute the smallest power of base greater than 100
//  I.e. when base == 2 we expect to see 128
void main()
{
    int i, base;
    i = 1;
    base = 2;

    while( i < 100)
    {
        i = i * base;
    }
    printf("Smallest power of %d greater than 100 is %d\n", base, i);
}
