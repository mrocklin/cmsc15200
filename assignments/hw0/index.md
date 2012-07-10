---
layout: assignment 
title: Hello World 
due: Tuesday July 26th, 8pm
---

Introduction
------------


Hello World
-----------

Download the file [helloworld.c](helloworld.c), copy it to desktop *(see *A Few
Linux Commands* below) and open it up with a text editor. If you double click on it the default text editor, Bluefish, will open. 

This is the most basic C program. It prints "Hello World!" to the screen. Our first step will be to compile this .c file into an executable or binary file. 

A Few Linux Commands 
--------------------

Open a terminal by going to *Applications:Accessories:Terminal*. You may want to right click on the Terminal option and select "Add this launcher to Panel" to make this useful program accessible on the top panel of the screen. We'll use it quite a bit. 

type

    pwd

to print your working directory (where you are). You should get something like
`/home/your_username`. This is your home directory. 

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
this happens to you check out [this explanation](/tips/errors.html) on compile time
errors.

For this task you will submit both the code and the executable. This is the only time when we will ask for the executable. In the future we will only want your code. 
