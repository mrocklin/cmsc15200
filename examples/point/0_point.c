#include<stdio.h>
#include<math.h>

struct point
{
    float x;
    float y;
};

float dist(struct point a, struct point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void main()
{
    struct point p;
    p.x = 3;
    p.y = 2;
    struct point q;
    q.x = 1;
    q.y = 0;
    printf("The distance between the points (%f, %f) and (%f, %f) is %f\n",
            p.x, p.y, q.x, q.y, dist(p, q));
}
