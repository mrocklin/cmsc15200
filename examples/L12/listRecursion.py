# Reductions

def sumList(L):
    if len(L) == 0:
        return 0
    head = L[0]
    tail = L[1:]
    return head + sumList(tail)

def maxList(L):
    if len(L) == 1:
        return L[0]
    head = L[0]
    tail = L[1:]
    return max(head, maxList(tail))

# Filter
def is_even(x):
    return x % 2 == 0

def evenList(L):
    if len(L) == 0:
        return []
    head = L[0]
    tail = L[1:]
    if is_even(head):
        return [head] + evenList(tail)
    else:
        return evenList(tail)
