#include<stdio.h>

// Want to compute the maximum of four numbers

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
    // Note how repetitive the following code is 
    int max_of_ab;
    if (a>b)
        max_of_ab = a;
    else
        max_of_ab = b;

    int max_of_cd;
    if (c>d)
        max_of_cd = c;
    else
        max_of_cd = d;

    if (max_of_ab > max_of_cd)
        m = max_of_ab;
    else
        m = max_of_cd;

    printf("The maximum is %d\n", m);
}

