def fact(n):
    total = 1
    i = 1
    while(i <= n):
        total = total * i
        i += 1
    return total

def factList(L):
    newList = []
    for x in L:
        newList.append(fact(x))
    return newList
