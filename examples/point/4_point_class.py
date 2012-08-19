from math import sqrt

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distTo(self, other):
        return sqrt( (self.x - other.x)**2 + (self.y - other.y)**2 )

    def __str__(self): # Convert to string function
        return "(%f, %f)"%(self.x, self.y)

p = Point(3, 2)
q = Point(1, 0)

print("The distance between the points (%f, %f) and (%f, %f) is %f"%
        (p.x, p.y, q.x, q.y, p.distTo(q)))

# Or the following
print("The distance between the points %s and %s is %f"%
        (str(p), str(q), p.distTo(q)))
