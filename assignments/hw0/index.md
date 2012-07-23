---
layout: assignment 
title: Hello World 
due: Wednesday July 25th, start of lecture
---

Introduction
------------


Hello World
-----------

Download the file [helloworld.c](helloworld.c), copy it to desktop (see *A Few
Linux Commands* below) and open it up with a text editor. If you double click on it the default text editor, Bluefish, will open. 

This is the most basic C program. It prints "Hello World!" to the screen. Our first step will be to compile this .c file into an executable or binary file. 

A Few Linux Commands 
--------------------

Open a terminal by going to **Applications:Accessories:Terminal** or by
pressing `Ctrl-Alt-T`. Now type

    pwd

to print your working directory (where you are). You should get something like
`/home/your_username`. This is your home directory; all of your files will
live here. 

You can list the files and directories in this directory by typing 
    
    ls
    
Do this now. There shouldn't be much there. You should see your Desktop directory and the helloworld.c file you just downloaded (Chromium downloads to your home directory by default). 

Move the helloworld.c file to the Desktop by typing the following:

    mv helloworld.c Desktop

Note that in Linux (and programming) upper and lower case matter. So make sure
you type **D**esktop instead of **d**esktop! The `helloworld.c` file should appear on your desktop. 

Change to the directory "Desktop" in the terminal by typing 

    cd Desktop
    
And then type `pwd` to see your working directory and `ls` to list the files on the Desktop. 

Compiling
---------

*Compile* the .c file `helloworld.c` into an executable program,
`helloworld.exe` using the `gcc` command as follows:

    gcc helloworld.c -o helloworld.exe

Type `ls` again to see that a new file, `helloworld.exe` has been created. This
file is an executable program that we can run by typing its name preceeded with
a `./`

    ./helloworld.exe

Try this now to see the results. The first part of the assignment is to change
the hello world program to say your name. For example, if your name was Alice
your task is to make an executable program that prints "`Hello Alice!`" to the
screen. To do this you will need to change the `helloworld.c` code with the text editor, save, and then compile the code again to a new executable. Run this executable to make sure that it works. 

When `gcc` runs we don't want it to print anything out. If it does print
something out it means that something is wrong, usually a compile error. When
this happens to you check out [this explanation]({{site.baseurl}}/tips/errors.html) on compile time
errors.

For this task you will submit both the code and the executable. This is the only time when we will ask for the executable. In the future we will only want your code. 

Rectangles 
----------

Download the file [rect.c](rect.c) and move it to the Desktop. If you need to
move your working directory from `/home/username/Desktop` directory down a level to `/home/username/` you can type 

    cd ..

After moving rect.c compile it using `gcc ` like you did in the last section and run the executable (be sure not to save over your executable from last section).

Hopefully you see something like:

    Area of Rectangle with sides 3, 4 is 12

This simple program computes the area of a rectangle given the two side lengths. The area is computed by multiplying the width by the height. 

Inspect this program with the text editor. The `printf` line may look somewhat cryptic but everything else should be familiar. Your task is to change this program to compute the perimeter of a rectangle given its length and width rather than the area.  

Compile your code and test it. Make sure that the results make sense. 

Submit your modified rect.c code

Fahrenheit to Celsius
---------------------

Page 12 in the Kernighan and Ritchie Text gives an example program that
produces a table matching temperatures in Fahrenheit to temperatures in
Celsius. Download this Fahrenheit-to-Celcius code [ftoc.c](ftoc.c) to your Desktop. Compile and run the executable, look at the results, and then look at the code.

This program is more complex than the previous two. It has similar elements like integer variables, `printf`, and mathematical expressions but it also contains some new elements like `while`. Additionally K and R's style is different. For example they declare variables

    int fahr, celsius;
    int lower, upper, step;

and assign values to them

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 10;      /* step size */
    fahr = lower;

in two different steps. If you can understand this program perfectly then that's great, but it's not necessary for today's assignment. 

Task one
--------

Decrease the stepsize to increase the number of rows in the table. Set the step variable to 5 and see the effect this has on the output of the program. Do this again, setting the step size to 1. 

Submit your `ftoc.c` code with step size equal to one. 

Task two - challenge
--------------------

_reminder_ : Challenge problems are worth far less credit than the effort that
they require. You are encouraged to try them but do not worry too much if they
are too difficult. 

This program converts degrees Fahrenheit (F) to degrees Celsius (C) by the following formula 

    C = 5 * (F-32) / 9

A similar conversion is to change miles per hour (mph) to kilometers per hour (kph)

    kph = 1.6 * mph

Copy the `ftoc.c` program to a new file, `mtok.c` by typing 

    cp ftoc.c mtok.c

in the terminal. Edit this program so that it displays a table converting miles per hour to kilometers per hour, starting from 0 up to 100 miles per hour in steps of 10.  Your output should look something like this:

    0    0
    10   16
    20   32
    30   48
    40   64
    50   80
    60   96
    70   112
    80   128
    90   144
    100  160

Submit your `mtok.c` file
