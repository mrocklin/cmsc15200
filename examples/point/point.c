#include<stdio.h>

struct point
{
    float x;
    float y;
};
void main()
{
    struct point p;
    p.x = 3;
    p.y = 2;
    printf("This point is at (%f, %f)\n", p.x, p.y);
}
