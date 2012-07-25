#include<stdio.h>

// Define a function
// Note the input and output types
int max(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}

void main()
{
    int n ;
    int a,b,c,d,e;
    n = -10000;

    // Compute the largest of these numbers
    a = 5; 
    b = 10; 
    c = 3;
    d = 13;
    e = 4;

    // isn't it nice that we don't have to type so many if-else lines?
    n = max(n, a);
    n = max(n, b);
    n = max(n, c);
    n = max(n, d);
    n = max(n, e);

    printf("%d\n", n);
}

