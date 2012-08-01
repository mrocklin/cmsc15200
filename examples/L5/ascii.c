#include<stdio.h>
#include<assert.h>

// ASCII = American standard code for information interchange 
// Prints out an ASCII chart
//
void main()
{
    int i;
    for(i = 1; i < 256; i++)
        printf("%d : %c\n", i, i);

    assert('A' == 65);
}
