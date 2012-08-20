from math import sqrt
from pylab import plot

# A Shape Interface
class Shape(object):

    def area(self):
        raise NotImplementedError()

    def perimeter(self):
        raise NotImplementedError()

    def contains(self, pt):
        raise NotImplementedError()

    def __repr__(self):
        return str(self)

    def __contains__(self, other):
        return self.contains(other)

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distTo(self, other):
        return sqrt( (self.x - other.x)**2 + (self.y - other.y)**2 )

    def __str__(self): # Convert to string function
        return "(%f, %f)"%(self.x, self.y)

    def __repr__(self):
        return str(self)

    def add(self, other):
        return point(self.x + other.x, self.y + other.y)

    def __add__(self, other):
        return self.add( other)

class Line(object):
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def draw(self):
        plot([self.a.x, self.b.x], [self.a.y, self.b.y], color="Black")

class Triangle(Shape):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def perimeter(self):
        return (  self.a.distTo(self.b)
                + self.b.distTo(self.c)
                + self.c.distTo(self.a))

    def draw(self):
        Line(self.a, self.b).draw()
        Line(self.b, self.c).draw()
        Line(self.c, self.a).draw()

class Rectangle(Shape):
    def __init__(self, ur, ll):
        self.ur = ur
        self.ll = ll

    def height(self):
        return self.ur.y - self.ll.y

    def width(self):
        return self.ur.x - self.ll.x

    def perimeter(self):
        return self.height() * 2 + self.width() * 2

    def area(self):
        return self.height() * self.width()

    def contains(self, p):
        return (    self.ll.x <= p.x and p.x <= self.ur.x
                and self.ll.y <= p.y and p.y <= self.ur.y)

    def __str__(self):
        return ("Rectangle spanning UR: %s LL: %s"%
                    (str(self.ur), str(self.ll)))

    def __repr__(self):
        return str(self)

    def draw(self):
        lr = Point(self.ur.x, self.ll.y)
        ul = Point(self.ll.x, self.ur.y)
        ur = self.ur
        ll = self.ll
        Line(ur, ul).draw()
        Line(ul, ll).draw()
        Line(ll, lr).draw()
        Line(lr, ur).draw()

class Circle(Shape):
    def __init__(self, center, radius):
        self.center = center
        self.radius = radius

    def area(self):
        return self.radius**2 * pi

    def perimeter(self):
        return self.radius * 2 * pi

    def contains(self, p):
        return self.center.distTo(p) <= self.radius

class Square(Rectangle):
    def __init__(self, center, sidelength):
        self.center = center
        self.sidelength = sidelength
        self.ur = Point(center.x + sidelength/2.0, center.y + sidelength/2.0)
        self.ll = Point(center.x - sidelength/2.0, center.y - sidelength/2.0)

    def __str__(self):
        return ("Square of sidelength %s centered at %s"%
                    (str(self.sidelength), str(self.center)))
