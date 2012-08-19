#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point
{
    float x;
    float y;
};
typedef struct point * Point;

Point mkPoint(float x, float y)
{
    Point p = malloc(sizeof(struct point));
    p->x = x;
    p->y = y;
    return p;
}
float dist(Point a, Point b)
{
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}
void main()
{
    Point p = mkPoint(3, 2);
    Point q = mkPoint(1, 0);
    printf("The distance between the points (%f, %f) and (%f, %f) is %f\n",
            p->x, p->y, q->x, q->y, dist(p, q));
}
