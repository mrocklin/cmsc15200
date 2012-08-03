#include<stdio.h>
#include<math.h>

struct point
{
    float x;
    float y;
};

float dist(struct point p, struct point q)
{
    return sqrt( pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
}

void main()
{
    struct point a, b; // make two struct points
    a.x = 0;
    a.y = 0;
    b.x = 2;
    b.y = 3;
    printf("The distance between (%f, %f) and (%f, %f) is %f\n",
            a.x, a.y, b.x, b.y, dist(a, b));
}

