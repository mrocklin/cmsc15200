from math import sqrt

p = (3, 2)
q = (1, 0)

def dist(a, b):
    return sqrt( (a[0] - b[0])**2 + (a[1] - b[1])**2 )

print("The distance between the points (%f, %f) and (%f, %f) is %f"%
    (p[0], p[1], q[0], q[1], dist(p, q)))
