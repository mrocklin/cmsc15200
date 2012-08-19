from math import sqrt
p = {"x": 3, "y":2}
q = {"x": 1, "y":0}

def dist(a, b):
    return sqrt( (a["x"] - b["x"])**2 + (a["y"] - b["y"])**2 )

print("The distance between the points (%f, %f) and (%f, %f) is %f"%
    (p['x'], p['y'], q['x'], q['y'], dist(p, q)))
