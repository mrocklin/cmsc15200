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

float dist(Point a, Point b)
{
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}
void test_dist()
{
    Point a = malloc(sizeof(struct point));
    a->x = 0;
    a->y = 0;
    Point b = malloc(sizeof(struct point));
    b->x = 1;
    b->y = 1;
    
    assert(fEq(dist(a, b), sqrt(2)));
}

struct triangle
{
    Point a;
    Point b;
    Point c;
};
typedef struct triangle*        Triangle;

float perimeter(Triangle t)
{
    return dist(t->a, t->b) + dist(t->b, t->c) + dist(t->c, t->a);
}

void main()
{
    Triangle t;
    t = malloc(sizeof(struct triangle));
    Point a = malloc(sizeof(struct point));
    Point b = malloc(sizeof(struct point));
    Point c = malloc(sizeof(struct point));
    t->a = a;
    t->b = b;
    t->c = c;
    t->a->x = 0;
    t->a->y = 0;
    t->b->x = 1;
    t->b->y = 0;
    t->c->x = 0;
    t->c->y = 1;



    test_dist();
    printf("Tests pass!\n");
}

