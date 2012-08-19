class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

p = Point(3, 2)
print("This point is at (%f, %f)"%(p.x, p.y))
