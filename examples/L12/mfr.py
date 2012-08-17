def stringLengths(L):
    newList = []
    for s in L:
        newList.append(len(s))
    return newList

def squareList(L):
    newList = []
    for x in L:
        newList.append(x**2) # ** is the "raise to power" operator in Python
    return newList

def is_even(x):
    return x%2 == 0

def evenList(L):
    newList = []
    for x in L:
        if is_even(x):
            newList.append(x)
    return newList

def longWords(L):
    newList = []
    for s in L:
        if (len(s) > 4):
            newList.append(s)
    return L

def sum(L):
    total = 0
    for x in L:
        total += x
    return total

def join_with_commas(L):
    s = L[0]
    for word in L[1:]:
        s = s + ', ' + word
    return s

def max(L):
    currentMax = L[0]
    for x in L[1:]:
        currentMax = max(currentMax, x)
    return currentMax
