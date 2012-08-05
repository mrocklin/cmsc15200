---
layout: assignment 
title: Shapes 
due: Thursday, August 9th, 8pm 
---

In this assignment you will define new data types to describe various shapes. You will write a few functions that work on these types. You will then collect these functions and types into a separate library.

Part 1 - Defining Structs
-------------------------

Design new types using `struct` for the following shapes

* Square 
* Rectangle
* Circle
* Polygon

Part 2 - Some useful functions
------------------------------

Write functions to compute the following for each of your data types

* Perimeter
* Area
* Contains

I.e. you should have functions like `rectanglePerimeter`, `rectangleArea`, and `rectangleContains`, `circlePerimeter`, `circleArea`, ....

You do not need to implement the following functions

* polygonArea
* polygonContains

*Question: What is contains?*

*Answer: contains takes a shape and a point and returns whether or not that point is contained within that shape. For example the point (1,1) is contained within the circle of radius two centered at the origin.

Part 3 - Switch to Pointer Syntax
---------------------------------

If you haven't done so already convert all of your functions to take in pointers to shapes rather than shapes themselves. 

Please make convenient typedefs to minimize typing. I.e.

    typedef struct rectangle *        Rect;

Please make constuction/make functions for each of your shapes. 

    Rect mkRect( ... )

These functions should take in the necessary inputs to define a shape, malloc enough space for the shape, set the inputs and return a pointer to the shape's location in memory. 

Part 4 - `shapes.h` and `test_shapes.c`
---------------------------------------

We often write code that is not for immediate use. Instead we write general
purpose libraries that can be shared with other programmers or used in the
future. When we do this we separate what the code does from how it works. People who use our library need to know what it does but not exactly how it works. They will study the .h file (what) and ignore the .c file (how)

* Make a `shapes.h` file that contains the headers of all functions that you want other people to be able to use. This file should be well commented to include what each function does.

If someone wants to see how a particular function works they will look in the
.c file. They should only see struct and function definitions. They should not
see testing code. 

* Make a `test_shapes.c` file that contains all of your testing code (remove this code from `shapes.c`)

Submission
----------

This homework is separated into four parts. While we recommend that you follow the outlined steps we will only grade the finished product. Please submit the following three files, 

* `shapes.c` - this should contain function and struct defintions
* `shapes.h` - this should contain function headers and typedefs
* `test_shapes.c` this should contain testing code and a `main` that calls that testing code. This is the only file which should have a `main`.
