#include<math.h>
#include<assert.h>
#include<stdio.h>

 
float fEq(float a, float b) // float equals
{
    return fabs(a-b) / b < .0001;
}

struct point
{
    float x;
    float y;
};


float dist(struct point a, struct point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
void test_dist()
{
    struct point a;
    a.x = 0;
    a.y = 0;
    struct point b;
    b.x = 1;
    b.y = 1;
    
    assert(fEq(dist(a, b), sqrt(2)));
}

struct triangle
{
    struct point a;
    struct point b;
    struct point c;
};


float perimeter(struct triangle t)
{
    return dist(t.a, t.b) + dist(t.b, t.c) + dist(t.c, t.a);
}
void main()
{
    test_dist();
    printf("Tests pass!\n");
}
