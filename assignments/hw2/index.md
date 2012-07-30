---
layout: assignment 
title: Arrays 
due: Thursday August 2nd, 8pm
---

Introduction
------------

In this assignment you will write a series of functions to handle basic statistical manipulations of one dimensional arrays, namely mean, variance, standard deviation, zscore, outliers. 

This assignment is intended to teach you how to use 

* Arrays
* Loops
* Functions
* Basic Testing

The context is that you are given a large quantity of data as an array of
numbers (doubles). From this data you will compute an average (mean), spread
(standard deviation), z-scores, and find values that are oddly large or small
(outliers). You will do this by building a series of functions that make use of
arrays for loops. These operations are very common in data analysis. 

In this assignment you'll need to include the libraries `stdlib.h` and `math.h`
at the top of your .c file. As we learned last week the math library requires
special care. There are instructions [here](../../tips/math.html)

Problem 1: Mean
---------------

Given an array of numbers `double[] data` and a length of the array `int len` compute the average of the array. This can be done by summing all the elements in the array and then dividing by the number of elements. The formula for the mean **mu** of an array **x** of length **n** is as follows

<a href="http://www.codecogs.com/eqnedit.php?latex=\large \fn_cm \mu = \frac{\sum_{i=0}^{n-1} x_i}{n}" target="_blank"><img src="http://latex.codecogs.com/png.latex?\large \fn_cm \mu = \frac{\sum_{i=0}^{n-1} x_i}{n}" title="\large \fn_cm \mu = \frac{\sum_{i=0}^{n-1} x_i}{n}" /></a>

Write a function which takes in an array of doubles and the length of the array and returns the mean. 

Problem 2: Standard Deviation
-----------------------------

The sample standard deviation is (roughly) the expected difference between the numbers in the list and the mean. If the numbers are all very close to the mean then it will be low. If there is a large spread in the numbers then the sample standard deviation will be high.  For example the following two lists have the same mean (2) but very different sample standard deviations:

1. The list `[1, 2, 0, 2, 3, 1, 3, 4]` has a sample standard deviation around 1. The numbers tend to deviate from the mean (here equal to 2) by about 1. 
2. The list `[2, 2, 2, 2, 2, 2, 2, 2]` has sample standard deviation 0 (there is no deviation from the mean). 

The formula for the sample standard deviation **sigma**  of an array **x** of length **n** with mean **mu** is as follows

<a href="http://www.codecogs.com/eqnedit.php?latex=\large \sigma = \sqrt{\frac{\sum_{i=1}^n (x_i - \mu)^2}{N-1}}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\large \sigma = \sqrt{\frac{\sum_{i=1}^n (x_i - \mu)^2}{N-1}}" title="\large \sigma = \sqrt{\frac{\sum_{i=1}^n (x_i - \mu)^2}{N-1}}" /></a>

Write a function which takes an array and it's length and returns the standard deviation.

Problem 3: Z-Scores
-------------------

If these are new to you I'll explain them below. You should also consider the
<a href="http://en.wikipedia.org/wiki/Zscore">explanation of z-scores on wikipedia</a>

We want to normalize an array so that it has mean zero and standard deviation one. Consider the grades on a test for a small class: 
`[64 98 66 60 67 64 70 73 59 75 35 75 ]`

This dataset has mean 67.166667 and standard deviation 14.427457

I would like to scale and recenter this dataset so that the mean is zero and the standard deviation is 1 but preserve the relative distance between all the numbers. The resulting test scores would be z-scores. In this example they are as follows

`Z Scores: [-0.219489 2.137129 -0.080864 -0.496738 -0.011552 -0.219489 0.196385 0.404322 -0.566050 0.542946 -2.229545 0.542946 ]`

The first score 64, has zscore -.21. This means that it is -.21 standard deviations below the mean. We verify this by checking that the mean is 67, that 64-67 is -3 and that -3 is a little more than a negative fifth (-.21) of a standard deviation (14.4). 

Z-scores give us a good way to quickly judge how good a score is without thinking about the average or spread of the data. 

We computed the z-score of 64 by subtracting the mean from the value and then dividing by the standard deviation.
 
I.e. <a href="http://www.codecogs.com/eqnedit.php?latex=\large Z_i = \frac{X_i - \mu}{\sigma}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\large Z_i = \frac{X_i - \mu}{\sigma}" title="\large Z_i = \frac{X_i - \mu}{\sigma}" /></a> 

The z-score of a data point is the number of standard deviations it is above the mean. For example if the mean is 10 and the standard deviation is 2 then the value 11 has z-score .5 and 6 has a z-score of -2. Z-scores are a convenient way to normalize data and quickly see which values are above average, below average, and by how much.  

Write a function which takes an array of doubles and its length and returns a pointer to a new array with the z-scores (also doubles). To do this you will need to dynamcally allocate space for the new array using `malloc`. An example that creates an array of ten ints is below.

`int* A = malloc(10 * sizeof(int));`

The malloc function lives in the library `stdlib.h`. You should include this header file at the top of your code. 

Problem 4: Outliers
-------------------

Outliers are values in our dataset which seem very high or very low given the mean and standard deviation. If we already know the Z-scores of our data then it is easy to define outliers as having a z-score with absolute value greater than some constant. For this exercise, we say that any data point with z-score greater than 2 or less than -2 is an outlier. 

Write three functions that return 

1. How many outliers a dataset contains
2. An array containing the index (location) of those outliers
3. An array containing the values of those outliers

Were there any outliers in the class test scores example?

    [64 98 66 60 67 64 70 73 59 75 35 75 ]
    Z Scores: [-0.219489 2.137129 -0.080864 -0.496738 -0.011552 -0.219489 0.196385 0.404322 -0.566050 0.542946 -2.229545 0.542946 ]
 
Yes! There were two outliers (result from function 1)

They occured at indices `[1, 10]` (result from function 2)

They had the values `[98.0 35.0]` (result from function 3)

Development Flow
----------------

Update your svn repository and look at `hw2/arrays.c`. Please develop your
solution within this file. 

This assignment will also introduce you to testing. When you begin `arrays.c`
already contains a function that sums an array and a function `test_sum` that
tests the `sum` function using [`assert.h`](../../tips/assert.html). 
You can use `sum` and `test_sum` as models for future functions.

There is also a test `test_mean` which includes a simple test for a `mean`
function which is not yet fully written. 

Compile and run this program. It should produce a *runtime error* on the
failing test. 

    arrays.c:42: test_mean: Assertion `mean(A, 3) == 2' failed

This means that we failed a test. This is expected because the mean function
doesn't currently work. Your first step should be to fix the mean function so 
that it computes the average. Then recompile and rerun your tests. If your
code is correct then this test should pass and you should see

    Tests Pass!

As you write the functions for this assignment you should also write tests.

Submission
----------

Please submit one large .c file, not several small ones. Please write your
solution into the file `hw2/arrays.c`.

You should not use `scanf`. All of the non-testing functions 
mentioned in this assignment should return values. None of the functions 
mentioned in this assignment should print.

Your functions should be [unit-tested using assert.h](../../tips/assert.html)

There should be no logic in your main function. Your goal is to produce useful
functions that can be used by anyone. Your functions are portable, your main is
not. You should use `main` just to print out results as you write your code and
to run tests.
