#include<stdio.h>
#include<assert.h>
#include<math.h>
#include "triangle.h"

float fEq(float a, float b) // float equals
{
    return fabs((a-b) / b) < .0001;
}
void test_fEq()
{
    assert(fEq(1.0/3, .33333));
    assert(fEq(100000.0/3, 33333.));
}

void test_dist()
{
    Point a = mkPoint(0, 0);
    Point b = mkPoint(1, 1);

    assert(fEq(dist(a, b), sqrt(2)));
}
void test_perimeter()
{
    Triangle t = mkTriangle(mkPoint(0, 0), mkPoint(0, 1), mkPoint(1, 0));
    assert(fEq(perimeter(t), 1 + 1 + sqrt(2)));
}


void main()
{
    test_fEq();
    test_dist();
    test_perimeter();
    printf("Tests pass!\n");
}
