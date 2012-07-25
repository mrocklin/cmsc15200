#include<stdio.h>

// compute x == a ^ b
// compute a raised to the power b
int power(int base, int exponent)
{
    int i = 0;
    int result = 1;
    while( i < exponent)
    {
        result = result * base;
        i = i + 1;
    }
    return result;
}

void main()
{
    int i; 
    // Print a table of the powers of two from 0 to 10 in steps of 1
    for(i = 0; i < 10; i = i + 1)
        printf("2^%d = %3d\n", i,  power(2, i));
}
    
