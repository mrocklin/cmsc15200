#include<stdio.h>
#include<math.h>

// This program must be compiled with a special flag to use the math library
// gcc hypotenuse.c -o hypotenuse.exe -lm

void main()
{
    float a,b,c;
    a = 3.0;
    b = 4.0;
    c = sqrt(a*a + b*b);
    printf("Hypotenuse of triangle with sides %f, %f is %f\n", a, b, c);
}
