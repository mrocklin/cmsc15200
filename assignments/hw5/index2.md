---
layout: assignment 
title: Tiny Savings and Loan - part two
due: Monday, August 20th, 8pm 
---

Grading
-------

This is a supplementary assignment for homework five. It is worth potentially 25% of a homework grade. The grading is complex however. 

HW5 will be graded 60% on your lookup code, 40% on your tsl code. Many students did not finish tsl.c. This assignment gives them an opportunity to make up some but not all of the lost credit. Your grade for HW5 will be computed as follows

    lookup.c/h (60 points) + tsl (40 points) + tsl_challenge (5 points)

TSL will be computed as follows

    tsl = max (tsl.c (40 points) , tsl.py (20 points))

I.e. we will take whichever is higher your tsl.c grade or your tsl.py grade. Note that tsl.c is worth 40 points and tsl.py is only worth 20. If you are depending on tsl.py you can only receive up to half credit on this assignment.

Additionally, if you submit working versions of both tsl.py and tsl.c then we will give you an additional 5 points. This is referred to as `tsl_challenge` above. This is here to motivate the over-achievers.

What you have to do
-------------------

You need to create the same program as in HW5, this time using Python. Fortunately, many of the pieces that we needed to build in C are already built in Python. 

In particular 
* instead of lookup.c we can use the python dictionary
* instead of an account struct we can use a list of length two to hold each customer's current balance and trustedness. 

For example the following code makes a new dict, makes an account for Alice,
and then deposits $50 in her account

    accounts = {} # make a new dictionary / empty table
    accounts["Alice"] = [0, "trusted"]
    accounts["Alice"][0] = 50

This entire project can now be done in one small file. We have distributed a tsl.py file which handles input. It is very much like the first tsl.c file we gave you to. It is currently ten lines long. By trying hard to make the solution small we were able to solve the problem by adding only 16 more lines. You do not need to be as terse - this is just to show you that this problem does not need a lot of work. We expect most solutions to be around 50-100 lines total.

Getting Started
---------------

Update your hw5 directory. Run the current python code by typing in 

    python tsl.py input.txt

This will read in each line of input.txt and just print it out again. Your task
is to have these lines manipulate a table of accounts instead of just printing
them out. 

Reminder
--------

You have another homework due on Tuesday. It is worth significantly more credit than this. It would be unfortunate if you were to spend all of your time on this assignment and not complete HW6.
