#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct point
{
    float x;
    float y;
};
typedef struct point *          Pt; // Pt is short for "struct point *"

float dist(Pt p, Pt q) // takes two pointers to struct points
{
    // use arrow instead of dot 
    return sqrt( pow(p->x - q->x, 2) + pow(p->y - q->y, 2)); 
}

void main()
{
    Pt a = malloc(sizeof(struct point));
    Pt b = malloc(sizeof(struct point));
    a->x = 0;
    a->y = 0;
    b->x = 2;
    b->y = 3;
    printf("The distance between (%f, %f) and (%f, %f) is %f\n",
            a->x, a->y, b->x, b->y, dist(a, b));
}

