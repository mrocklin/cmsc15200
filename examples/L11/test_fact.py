from fact import *

def test_fact():
    assert(fact(1) == 1)
    assert(fact(2) == 2)
    assert(fact(3) == 6)
    assert(fact(4) == 24)

def test_factList():
    assert(factList([1,2,4]) == [1,2,24])
