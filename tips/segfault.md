---
layout: default
title: Dealing with Segmentation Faults
---

### What is a Segmentation Fault ###
*Question: I'm getting a Segmentation Fault when I run my program. What does
this mean and how do I deal with it?*

A `Segmentation Fault` is a runtime error that occurs when you access memory that you do not own. The following situations cause "Seg-faults"

We make a pointer/array but forget to malloc

    float *A; // make a pointer 
    A[3] = 4; 

We go outside the bounds of an array

    int n = 4;
    float *A = malloc(n * sizeof(float));
    A[n] = 10; // we own the bytes up to A[n-1] but not A[n]

We make a pointer but forget to allocate space

    Point p; // forget "= mkPoint(0, 0);"
    p->x = 3;

We malloc space for a struct but don't malloc space for the pointers that it contains

    Array A = malloc(sizeof(struct array));
    A->data[3] = 5; // data is a float * that has not yet been malloced

###Finding a Segmentation Fault###

*Question: I want to find the line where this happens but this error doesn't have a line number. What's going on?*

Seg-faults are "runtime errors" rather than "compile-time errors." This means that the compiler `gcc` isn't smart enough to find them for us and we need to run the program before we run into the problem. `gcc` was the program that was helping us with line numbers and cryptic error messages before. Now we really appreciate how useful the compiler is. 

Here are some methods for tracking down a Seg-fault. 

* Introduce `printf` statements into your code at strategic locations. This allows you to see what does work and what doesn't. Move the `printf`s around until you zero in on the right location.

* If you're using Eclipse then use the Eclipse debugger. Rather than use `Run as...` use `Debug as...`. Your program will run as before but will stop at the line with the seg-fault. Inspect the variables in the upper right. If the value of any of the pointers is `0x0` then that is likely your problem.

* If you're using the command line/`gcc` then you should use the program `gdb`. 

###Using `gdb`###

First compile your program with the `-g` flag. I.e.

    gcc mycode.c -o mycode.exe -g

Then run the gdb program with your executable as an input

    gdb mycode.exe

And then in the gdb prompt type in `run` and press enter. Your program should run and stop at the line that causes the segfault. You can print the value of any active variable in your program by typing 

    print variable_name

And you can what function called this one by typing `up`
