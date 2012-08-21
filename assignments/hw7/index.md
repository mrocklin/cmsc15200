---
layout: assignment 
title: Polynomial Class
due: Saturday Aug 25th, 8pm
---

Part 1: Quadratic Polynomials
-----------------------------

A [quadratic polynomial](http://en.wikipedia.org/wiki/Quadratic_polynomial) is a function of the form:

<a href="http://www.codecogs.com/eqnedit.php?latex=\large f(x) = ax^2 @plus; bx@plus;c" target="_blank"><img src="http://latex.codecogs.com/png.latex?\large f(x) = ax^2 + bx+c" title="\large f(x) = ax^2 + bx+c" /></a>

We can represent a quadratic polynomial with the three numbers, a, b, and c.

###Requirements###

You will build a Quadratic class. The class will be able to perform the following operations

* Convert itself to a string
* Add itself to another quadratic
* Multiply itself by a number
* Evaluate the quadratic at a given x (i.e. compute f(x)) 
* Check for equality with another Quadratic
* Determine if the polynomial has real roots
* Compute the real roots of the polynomial (if they exist)

<h5> Conversion to a String </h5>
Write a method to convert your Quadratic object into a string. For example:

    In [1]: p = Quadratic(2,2,1)
    In [2]: print p
    Out[2]  2x^2 + 2x + 1

You may choose to handle the special cases when some of the coefficients a,b, or c are zero if you like but this is not required. 

when the `str` function is called on an object it checks to see if the object has a `.__str__` method and calls that. Check examples from class for details. In addition, you may want to make a `.__repr__` method. This is what ipython calls when it prints the object to the screen. 

###Polynomial Addition and Scalar Multiplication###

Your polynomials should be able to add themselves to other polynomials to produce new polynomials. Similarly they should be able to multiply themselves by scalars. I.e., the following should work

    In [2]: p = Quadratic(2,3,1)

    In [3]: q = Quadratic(-5,2,2)

    In [4]: print p
    Out[4]: 2x^2 + 3x + 1

    In [5]: print q
    Out[5]: -5x^2 + 2x + 2

    In [6]: print p.add(q) # This produces a new Quadratic
    Out[6]: -3x^2 + 5x + 3

    In [7]: print p.mul(2) # This produces a new Quadratic
    Out[7]: 4x^2 + 6x + 2

Use the special method names `__add__` and `__mul__` so that the last two lines
can be written
    
    In [6]: print p+q # This produces a new Quadratic
    Out[6]: -3x^2 + 5x + 3

    In [7]: print p*2 # This produces a new Quadratic
    Out[7]: 4x^2 + 6x + 2

###Evaluate at x###

We often want to evalutate a function at a specific x point. Write a method, `evalutateAt` which takes a value and returns the value of the quadratic at that point. i.e.

    In [10]: p
    Out[10]: 2x^2 + 3x + 1
    
    In [11]: p.evaluateAt(1)
    Out[11]: 6
    
    In [13]: p.evaluateAt(-1)
    Out[13]: 0

###Roots###

Write a method `roots` which returns the real roots of a quadratic polynomial,
i.e. the values for `x` when `f(x)==0`. You'll have to use the [Quadratic
Equation](http://en.wikipedia.org/wiki/Quadratic_equation). There can be 0, 1 or 2 roots to a quadratic polynomial. This function should always return either a list or a tuple.

    In [17]: p
    Out[17]: 2x^2 + 3x + 1

    In [18]: p.roots()
    Out[18]: (-0.5, -1.0)

You do not need to handle the special case when the quadratic is linear, i.e. when the x^2 coefficient is zero.

Note that not all quadratic polynomials have roots (not all quadratics pass through the x-axis). Write a function that determines if the quadratic has real roots

    In [19]: p.hasRealRoots()
    Out[19]: True

Submission Guidelines
---------------------
Submit a single .py file that contains your class. Your class should have at least the following fields and methods

* fields, a, b, c
* `__str__`
* `__eq__`
* `__add__`
* `__mul__`
* `roots`
* `hasRealRoots`
* `evaluateAt`

We have supplied a test file for you. Your code should pass all tests.

Part 2: General Polynomials
---------------------------

###Requirements###

Build a class to represent a polynomial of arbitrary degree. We can represent a Quadratic with three floats, `a,b,c`. To represent a polynomial of arbitrary degree we will need an arbitrary number of floats. The class will be able to perform the following operations

* Convert itself to a string
* Check for equality with another Polynomial
* Add itself to another polynomial
* Multiply itself by a number
* Evaluate the polynomial at a given x (i.e. compute f(x)) 
* Compute the derivative of the polynomial (i.e. `x^2 -> 2x`)
* Compute the indefinite integral of the polynomial (i.e. `x^2 -> x^3/3 + C`)
* Plot the function between the x-values -10, and 10 (you will need to import plot from the pylab module)

Regarding the integration task. You may assume that the additive constant, C, is zero. 

###Submission Guidelines###

Submit a polynomial.py file as well as a test_polynomial.py file. Test_polynomial should look similar to test_quadratic with the addition of some new tests for derivatives and integrals. You do not need to test plotting.

You should use the same names as you used for Quadratic. You should include the following additional methods

* `derivative`
* `integral`
* `draw`

*Note - Don't remember/never took calculus? Taking derivatives and computing integrals of polynomials is one of the more mechanical tasks in calculus. Check out the wikipedia page on the [power rule](http://en.wikipedia.org/wiki/Power_rule)

Part 3: Inheritance
-------------------

Change your quadratic function so that it inherits from Polynomial. You may need to introduce new fields to quadratic so that the Polynomial functions work on Quadratics. Ensure that the new functions for derivative, indefinite integral, and plotting work on Quadratics.

###Submission Guidelines###

You should change your quadratic.py file very slightly for this change. You should add new tests to test_quadratic.py to make sure that the new methods work properly.

Challenge - General Functions - 10%
-----------------------------------

*This section requires you to treat variables as functions. This is a challenging topic that we did not seriously cover in class. This section is challenging. I expect only a few students to get halfway. I do not expect anyone to complete it perfectly.*

Build a class to represent a general real-valued function. The class will be able to perform the following operations

* Add itself to another Function 
* Multiply itself by another Function
* Evaluate the function at a given x (i.e. compute f(x)) 
* Plot itself over a given range (with default -10, to 10)
* Compute the derivative of the Function using [finite differences](http://en.wikipedia.org/wiki/Finite_differences) (this is hard)
* Compute the definite integral of the Function using [quadrature](http://en.wikipedia.org/wiki/Numerical_integration). In particular you can use the [trapezoid rule](http://en.wikipedia.org/wiki/Trapezoid_rule) (this is hard)

How can we represent any arbitrary function? We represent Quadratics with three floats, `a,b,c` - what python variable can we use to represent any possible mathematical function? We will use Python functions. The methods of this object will manipulate functions as variables. Just as Quadratic.add created new a new set of `a,b,c` for a new Quadratic, Function.add will create a new Python function for a new Function object. This is challenging.
