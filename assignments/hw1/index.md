---
layout: assignment 
title: Geometry, Weight, and Cats
due: Sunday July 29th, 8pm
---

Introduction
------------

In this assignment you will write several small programs to develop an understanding of variables, conditional, loops, and functions. 

When you're ready to submit your assignment please see the [submission
guidlines](../../submissionGuidelines.html)

Problem 1-A: Geometry
---------------------
A point in the real plane can be described by an x and y coordinate, written as (x, y). A line segment can be described by two points (x1, y1) and (x2, y2). The length of a line segment can be found by computing the following mathematical formula 

<p><a href="http://www.codecogs.com/eqnedit.php?latex=\large \fn_cm d = \sqrt{(x_1-x_2)^2 @plus; (y_1-y_2)^2}" target="_blank"><img src="http://latex.codecogs.com/png.latex?\large \fn_cm d = \sqrt{(x_1-x_2)^2 + (y_1-y_2)^2}" title="\large \fn_cm d = \sqrt{(x_1-x_2)^2 + (y_1-y_2)^2}" /></a>

Write a program, similar to the rect.c program from HW0 that computes the length of a line segment described by the four variables x1, y1, x1, y2 which can take on any values in the plane. These values can just be initialized directly in the code (i.e. you don't need to use `scanf`). Verify that your program works by testing the simple case (x1, y1) == (1, 1/2) and (x2, y2) == (0, 1+1/2). This should give the result of sqrt(2) == 1.41...

Such a test might look like 
    
    printf("A line segment with points (%f, %f), (%f, %f) has the length %f\n", x1, y1, x2, y2, len)

where I'm assuming that x1, y1, x2, y2, and len are all floats (hence the %f) that exist in your program. This is only a suggestion to give you an idea about how such a test might look. Ideally you would also add a line saying "we expected such and such a value" so that it would be easy to see if they matched.   

Note: You will need to use a sqrt function found in the `math.h`
library. Using this library in your code requires a couple of special steps.
They are outlined [here](../../tips/math.html). Please e-mail the listhost if these instructions are not sufficiently clear. 

Problem 1-B: Geometry
---------------------

Write a length function which computes the length of a line segment as described above. What inputs does it need? What type of value does it return? Depending on how you write it this might be a very short function. There is no new mathematical work that needs to be done in this section. 

Modify the code in Problem 1 to use this function. 

Problem 1-C: Geometry
---------------------

Similarly a triangle can be described by three points (x1, y1), (x2, y2), (x3, y3). The perimeter of a triangle is defined to be the sum of the lengths of the three associated line segments. 

Write a function to compute the perimeter of a triangle. Try to make it as simple as possible by using your function from 1-B. In your main code design and run at least two tests to show that your function works correctly (you will need to compute the perimeter of two triangles by hand to provide answers for your tests). 

Answer the following question in words as a comment at the bottom of your code. Answers should not be longer than a few sentences.

Imagine writing a similar function for quadilaterals (like rectangles) or pentagons (five pointed polygons); what would change in your code? If you wanted to write a similar function for a polygon of any number of points how would you do it? If this programming task seems difficult, explain the difficulty. 

Problem 1-Submission
--------------------

<p> Please submit two files. One for 1-B and one for 1-C. Both should include the functions you wrote and a main which demonstrates that these functions work well.  

Problem 2-A: Ideal Weight 
-------------------------

You will write a function `ideal_weight` that calculates an
ideal weight based on the user's gender, age and height. The formula
for doing so is below.
 
    Please know that there is a variety of ideal weight calculations put
    forward by various constituents. The one we present is as much
    folklore as it is hard science, so take its results with a grain of
    salt!
 
The formula is as follows. In every case, `h` stands for height
in centimeters and `a` stands for age in years. The weight
given by the formula is *in kilograms*.

<blockquote> 
<table width=60% border=1 cellpadding=5> 
  <tr><td> 
    <ul> 
       <li>For males up to and including age 18, the ideal weight is
       <blockquote>(<i><b>h</b></i> - 36) / 2</blockquote> 
       <li>For males between age 19 and 55 inclusive, the ideal weight is
       <blockquote> 
       ((<i><b>h</b></i> - 36) / 2) + ((<i><b>a</b></i> - 18) / 7)
       </blockquote> 
       <li>For males between 56 and 75 inclusive, the ideal weight is
       <blockquote> 
       <nobr> 
       ((<i><b>h</b></i> - 36) / 2) + ((37 / 7) - ((<i><b>a</b></i> - 55) / 4))
       </nobr> 
       </blockquote> 
       <li>For males over the age of 76, the ideal weight is the same as for
       males 18 or younger.<br><br> 
       <li>For females, the calculations are the same as for males, but in
       every case the calculation is finally multiplied by 0.86.
       </ul> 
  </td></tr></table> 
</blockquote> 
</p> 
 
The function `ideal_weight` will have the following header:

    double ideal_weight(char g, double h, int a)

where `g`, `h` and `a` are understood to mean
gender, height (in centimeters) and age, respectively.
 
The `ideal_weight` function can be written in a variety of
ways. Here is a skeleton of one way, which you may use as a starting
point if you like:

    // a function that calculates ideal weight
    double ideal_weight(char g, double h, int a) {
        if ((g == 'm') && (a <= 18)) 
        {
            return ...
        } 
        else if ((g == 'm') && (a >= 19) && (a <= 55)) 
        {
            return ...
        } 
        // et cetera
    }


Write a main function and test that this function works for both men and women. 


Problem 2-B: Ideal Weight
-------------------------

Write a program to display a table of the ideal weight for men and women of height 170cm over a list of ages ranging from 0 to 100. Exactly how you format this is up to you. You might want to produce two tables (one for each sex) that lists age and ideal weight or one table that lists age, ideal weight for men and ideal weight for women.

You may find using the tab character, '\t' in printf is useful to maintain
uniform spacing. Alternatively you may want to control spacing by controling
the precision of numbers. [This page](http://www.codingunit.com/printf-format-specifiers-format-conversions-and-formatted-output) has a nice example on printing floating point to a certain precision with a certain spacing. 

Problem 2-Submission
--------------------

You should submit two .c files. One for 2-A and one for 2-B. The first should have a main function which demonstrates that your function works for a few known inputs (you should work out the values by hand to check). The second should have a main function which prints a table. Each file should have the ideal_weight function included. 

Problem 3 : The Island of FOO

On the small island of FOO live a family of wild cats and a large nest of rats.
The rats breed prolifically, providing food for the cats.
Cats die of old age, starvation and indigestion,
and also increase somewhat, depending on the food supply (the rats).
The more rats that are around, the more the cats can breed. 
The rats die both from old age and from being hunted by the cats. The more cats there are, the faster the rats get eaten up.
If C and R stand for the number of Cats and Rats at the beginning of some month,
then at the start of the next month, the new populations, C' and R',
are determined like this:

    C' = C - 0.30C + 0.00033CR
    R' = R - 0.016CR + 0.43R
 
<img src=http://upload.wikimedia.org/wikipedia/commons/a/aa/Volterra_lotka_dynamics.PNG alt="Predator Prey Plot" width=40% align=right>

In each equation, the first term is the old size,
the second term is the death rate (notice the minus sign)
and the third term is the birth rate (notice the plus sign). 
Note that the death rate of the rats depends on the current population of the cats 
and that the birth rate of the cats depends on the current population of the rats. 
They are interconnected.
 
Write a program that displays the cat and rat population for 30 months.
At the start of month #1, there are 30.0 cats and 1000.0 rats.
Fractional animals exist and are quite reasonable in FOOland.
Produce a table (nicely labeled)
showing the month number, number of cats at the beginning of that month
and the number of rats at the beginning of that month.
 
For example, the first part of your table should look like this:

    Month      Cats      Rats
    -----      ----      ----
    1          30.0     1000.0
    2          30.9      950.0


Problem 3-Submission
--------------------

You should submit a single .c file that, when run, produces a table.  

Problem - Challenge : Population Stability on the Island of FOO
---------------------------------------------------------------

We ask the question: Is the Rat/Cat population on the island of Foo relatively stable? Can we expect rats and cats to exist on this island several years in the future?

Answer this question by running the simulation beyond 30 months. The populations will go extinct if either of them drop below 2. Does this ever happen? Write a program to evolve the simulation until either one of the popuations dip below 2 or until 10000 months have passed.

Answer: Yes. At some month we find that the Cat and Rat populations equalled  76.4 and -12.9 respectively. At what month does this happen in your simulation?

This result shows that there were -12.9 rats. Fractional Rats exist in FOOLand, negative Rats do not. This is strange. This is a sign that our simulation does not reflect reality. Even though our code is correct our mathematics is not. 

The problem is that we are updating the Rat and Cat population every month; this is too infrequent. We need to change our code so that we can control the size of the timestep. This will allow us to step forward by 10ths of a month or 100ths of a month. The birth rate and death rate terms in the update equations will need to be reduced by this same factor (these were the second and third terms in each expression).

Change you program to have a variable timestep. Turn this program into a function that takes in a timestep and returns the number of months (not steps) before one of the species goes extinct. Run your function a few times in main with different time steps. Observe the results.

Does changing the stepsize affect the stability of the Rat/Cat population? If yes, how so? Can you detect how the timestep affects the time of extinction? Given that nature is continuous (i.e. the timestep is infinitessimal) what can you say about the eventual fate of Rats and Cats on the island of FOO? Should we expect to see them 1000 years from today? 

Problem Challenge - Submission 
--------------------------------

You should submit a separate .c file for this problem. It should include the simulation function, and a main which uses the simulation function to print out a few values. You should answer the questions as comments at the bottom of the file. 
Specific questions that were asked were:

 * At what month does the original simulation produce negative results?
 * How does extinction time depend on the timestep?
 * Will Rats/Cats be on the island in 1000 years?
