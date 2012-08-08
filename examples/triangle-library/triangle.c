#include<math.h>
#include<stdlib.h>
#include "triangle.h"

//---------------------------------------------------------------------------
//      Point
//---------------------------------------------------------------------------
struct point
{
    float x;
    float y;
};

// Point constructor - requires x and y coordinates
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

//---------------------------------------------------------------------------
//      Triangle 
//---------------------------------------------------------------------------
struct triangle
{
    Point a;
    Point b;
    Point c;
};

// Triangle constructor - requires three Points
Triangle mkTriangle(Point a, Point b, Point c)
{
    Triangle t = malloc(sizeof(struct triangle));
    t->a = a;
    t->b = b;
    t->c = c;
    return t;
}

// Just one function in this example
float perimeter(Triangle t)
{
    return dist(t->a, t->b) + dist(t->b, t->c) + dist(t->c, t->a);
}
