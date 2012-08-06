#include<math.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
 
float fEq(float a, float b) // float equals
{
    return fabs(a-b) / b < .0001;
}

struct point
{
    float x;
    float y;
};
typedef struct point *          Point;

// Constructor -- make function
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
void test_dist()
{
    Point a = mkPoint(0, 0);
    Point b = mkPoint(1, 1);
    
    assert(fEq(dist(a, b), sqrt(2)));
}
struct triangle
{
    Point a;
    Point b;
    Point c;
};
typedef struct triangle*        Triangle;

Triangle mkTriangle(Point a, Point b, Point c)
{
    Triangle t = malloc(sizeof(struct triangle));
    t->a = a;
    t->b = b;
    t->c = c;
    return t;
}

float perimeter(Triangle t)
{
    return dist(t->a, t->b) + dist(t->b, t->c) + dist(t->c, t->a);
}
void test_perimeter()
{
    Triangle t = mkTriangle(mkPoint(0, 0), mkPoint(0, 1), mkPoint(1, 0));
    assert(fEq(perimeter(t), 1 + 1 + sqrt(2)));
}

void main()
{
    Point a = mkPoint(0, 0); // malloc(sizeof(struct point));
    Point b = mkPoint(0, 1); // malloc(sizeof(struct point));
    Point c = mkPoint(1, 0); //malloc(sizeof(struct point));
    Triangle t = mkTriangle(a,b,c);
    Triangle t2 = mkTriangle(mkPoint(0, 0), mkPoint(0, 1), mkPoint(1, 0));
    /*
    t->a = a;
    t->b = b;
    t->c = c;
    t->a->x = 0;
    t->a->y = 0;
    t->b->x = 1;
    t->b->y = 0;
    t->c->x = 0;
    t->c->y = 1;
    */


    test_dist();
    printf("Tests pass!\n");
}

