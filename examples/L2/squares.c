#include<stdio.h>

void main()
{
    int i, max_number;
    i = 0; 
    max_number = 10;

    // Print out the squares from 0 to max
    while(i < max_number)
    {
        printf("%d squared is %d\n", i, i*i);
        i = i + 2; // add one to i
    }
    printf("All finished\n");
}
