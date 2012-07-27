#include<stdio.h>

// Want to compute the maximum of four numbers

int max(int x, int y) // defining max
{
    if (x > y)
        return x;
    else
        return y;
}

void main()
{
    int a,b,c,d;
    int m; // this will store my result
    // Some input data
    a = 5;
    b = 3;
    c = 7;
    d = -2;

    // write code to store the maximum of a,b,c,d into m

    m = max(max(a,b), max(c,d));

    printf("The maximum is %d\n", m);
}

