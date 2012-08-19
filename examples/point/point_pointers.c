#include<stdio.h>
#include<stdlib.h>

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
void main()
{
    Point p = mkPoint(3, 2);
    printf("This point is at (%f, %f)\n", p->x, p->y);
}
