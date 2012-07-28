---
layout: default
title: Unit Testing with Assert 
---

You should test your program to make sure that it is correct. If your program
is broken up into many small functions then it becomes easier to test each of
them individually. This is called "unit testing" and it makes it much easier to
isolate errors.

The library `assert.h` is very useful for unit testing. It contains a function

    void assert(bool condition)

which does nothing if `condition` is True and stops the program if `condition`
is false. We use it by giving it conditions that we believe to be true. This is
best explained with an example

    #include<assert.h>

    int max(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }
    void test_max()
    {
        assert(max(1,2) == 2);
        assert(max(5,2) == 5);
        assert(max(3,3) == 3); // make sure we work in the equality case
        assert(max(-3, -10) == -3); // check negative values
    }

    void main()
    {
        // Run tests 
        test_max(); // we will comment this line out when we're finished writing
    }

In unit testing each function has a corresponding test function. That test
function contains a few assert statements with conditions that we know should
be true. If none of the tests/assertions fail then test_max does nothing. If
one of them fails it will stop the program and tell us which one. 

Check out the code example `unit-testing.c` for an example

Test Driven Development
-----------------------

Modern programmers often write tests before they write their functions (i.e.
they write `test_max` before they write `max`). This helps them outline clear
goals of what a function should do. It also serves to highlight errors as they
write code. A test-driven programmer keeps programming until "all tests pass". 
