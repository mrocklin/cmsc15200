#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef struct point *          Point;
typedef struct triangle*        Triangle;

Point mkPoint(float x, float y); // Point constructor 
float dist(Point a, Point b); // compute the distance between Points a and b

Triangle mkTriangle(Point a, Point b, Point c); //Triangle Constructor
float perimeter(Triangle t); // compute perimeter of Triangle t

#endif
