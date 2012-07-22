#include <stdio.h>

void main()
{
    float x, y, max_xy;
    x = 3.2;
    y = 1.6 * 1.8;
    if (x > y)
    {
        max_xy = x;
    }
    else
    {
        max_xy = y;
    }
    printf("The maximum of x and y is %f\n", max_xy);
}
