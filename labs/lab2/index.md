---
layout: lab 
title: Lab 2 - Strings 
---

Goals
-----

Today's lab exercises the following concepts

* Text/Strings
* Pointers
* Dynamically allocated memory
* Command line inputs

We'll do this by building simple encryption program

References
----------

* Kernighan and Ritchie, Section 5.5, Page 105 

* [An example using malloc on Wikipedia](http://en.wikipedia.org/wiki/Malloc#Usage_example)

* [Wikipedia article describing Caesar Cipher](http://en.wikipedia.org/wiki/Caesar_cipher)

* [Wikiversity article on C-Strings](http://en.wikiversity.org/wiki/String_handling_in_C)

To Start
--------

Update your svn repository to download the materials for lab2. 

    cd username-152
    svn up

There is a file

    lab2/caesar.c

which contains a function 

    int strlength(char *s) // compute the length of a string

which will be helpful in part 1 and a function

    char cycle(char c, int shift, char base, int len) // cycle a character

which will be helpful in part 2. Each is well documented and is accompanied by
a test function.

If you are using Eclipse you can follow 
[these instructions](../../tips/new-c-project.html) 
to create a new C project from existing source.

Playing with Pointers and Strings 
---------------------------------

For help with this section please review the <a href="http://en.wikiversity.org/wiki/String_handling_in_C">wikiversity article</a> on C-Strings. 

We start with a warm up exercise. We will build a program to concatenate two
strings. Concatenate means to "join together". You will build a function like
this

    char* concatenate(char* A, char* B)

that works like this

    char *A = "Hello";
    char *B = "World";
    char *output = concatenate(A, B) // output points to a string "HelloWorld" 

Note that the naive solution `output = A + B` just adds the pointer values.
This does not work.

We don't have functions in C which natively handle entire string objects as a whole, all operations must be built out of smaller operations on individual characters. *There is no String class/type in C. When we say "String", we mean a pointer to an array of characters.* 

A and B point to locations in memory that hold many characters. We know a
string of characters is finished when we reach the special terminating
character `'\0'`
    
    A ----> {'H', 'e', 'l', 'l', 'o', '\0'}
    B ----> {'W', 'o', 'r', 'l', 'd', '\0'}

In this case you would need to allocate space for 5+5+1 == 11 chars so that we
can store `"Hello"`, `"World"`, and a terminating character `'\0'` at the end.

    char* output = malloc(11);

and fill that space with 
    
    {'H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd', '\0'}

You will need to transfer each letter individually, add a terminator at the end and then finally return the pointer to the beginning 'H'.

First you will need to determine the length of the two strings. Then, you will need to allocate enough space to hold the addition of the two strings plus a terminating character. Then, copy the characters in the first string. Then copy the characters in the second string. Then you will need to write a terminator character '\0' and finally return the pointer to beginning of the result string. 

Caesar Cipher
-------------

The Caesar Cipher is a rudimentary encryption scheme whereby each letter is
shifted up or down by a constant. For example we could move the word "Cat" up by one to "Dbu" C->D , a->b , t->u. This method was invented (they say) by Caesar and was used in communication with his Generals. It is not recommended for use today....

To write this easily we'll take advantage of characters' numerical representation in the ASCII format, 'A' = 65, 'B' = 66, 'C' = 67, etc.... Because characters are the same as eight-bit integers we can abuse the type system and type 'A'+2 to obtain 'C'. 

###Small functions to Identify Letters###

We'll want to shift letters but not punctuation or spaces. In addition we will need to distinguish upper-case from lower-case letters. Write two functions, 

    bool isUpper(char c)
    bool isLower(char c)

that return True if the character is an upper case letter (between 'A' and 'Z') or is a lower case letter (between 'a' and 'z'). Because statements like 'B'>'A' are themselves boolean values these functions can be written as simple one liners. As an example a function, isletter, could be written using the above functions as
    
    bool isLetter(char c)
    {
    	return isUpper(c) || isLower(c);
    }

Note that bool is not native in C. You will have to include the standard bool library by putting the following line at the top of your code.

    #include <stdbool.h>

###Encrypting a character###

Write a function `encryptChar` which takes in a character, **c**, and an
integer, **shift**, and returns that character shifted up or down by the
integer. You can use the included function `cycle` to help you with this task. 

Test that this function works on a variety of inputs. There are easy cases like
`encryptChar('A', 1)=='B'` and more challenging cases like `encryptChar('z',
3)=='c'` or `encryptChar('a', -3)=='x'`. Make sure that it correctly encrypts
both upper case and lower case letters. Make sure that it does not affect non-letters.

Unfortunately, `c+shift` will not work in cases where `c+shift > 'Z'` or
` < 'A'` (if c is upper case) or `c+shift > 'z'` or ` < 'a'` 
(if c is lowercase).
In these cases you'll have to add or subtract 26 so that the letters wrap
around, i.e. so that `encryptChar('Z', 1)` returns `'A'` 
and `encryptChar('A',-1)` returns `'Z'`. 
The function `cycle` handles all of this logic for you. See the
comments above it and the included test function. `cycle` is more powerful than
you need. For example `cycle` can change numbers around as well. We do not need
to use this ability.

It's important to recognize that we're playing with both chars and ints at the same time. C gives us much more control than other languages you may have tried.These other languages keep you away from potentially dangerous activities. C lets you play with dangerous things but allows you to get burned. 

###Putting it all together###

Build a function which takes an input string and shift integer, allocates a new
string of the same size, and then stores the encrypted version of each letter
of the input string into the output string. Return a pointer to the beginning
of the output string. Make sure you can add a terminating character `'\0'`

Verify that this function works both by playing with it in `main` and by
writing some test cases. Make sure you test some interesting cases; test
that your function works correctly on punctuation, upper and lower case
letters, letters that wrap beyond 'Z', etc....

Write a decryption function that takes an encrypted string (like "Dbu") and the 
shift integer (like 1) and returns the original (like "Cat"). This should be a
very short function.

For very long strings or for inputs that need to be processed very quickly we
may choose to not make a copy of the input string. Instead, we may choose to
affect the input memory directly. Write an encryption function that writes the
result directly onto the memory pointed to by the input. We call this computing
*in place*. It is generally considered dangerous but is sometimes done for
performance reasons. Your function will not need to return anything (why is
this?).

*Potential error:* To test your code you may be tempted to make a string as follows 

    char *testString = "My test string tests both UPPER and lower case letters, as well as punctuation.\n";
    encrypt(testString);
    printf(testString);

Unfortunately strings that we specify directly in quotes are usually stored in
*read-only memory* and can not be modified. Modifying them will result in a
Segmentation Fault. To fix this create a dynamic copy of your string using the
`strdup` function found in `string.h`. `strdup` is short for string duplication.

    testString = strdup(testString); //duplicate testString dynamically

This string is stored in normal memory and is fine to change.

###Free###

The companion to **malloc** is **free**. **free** releases memory back into the
common pool. This is especially important if your program creates lots of
temporary arrays. If you don't free them then you'll quickly run out of space.
Think about the memory space that you've malloc'ed. Free those variables when they are no longer needed. Often programmers are lazy about this because usually arrays left hanging around are freed automatically when their home function returns. It is good to understand that **free** exists however. 

Program Arguments
-----------------

See the [tips page on arguments](../../tips/command-line-arguments.html) before proceeding

Modify your program so that it takes two arguments. A message, enclosed in quotes, and a shift/integer. It should encrypt the message using the shift and then print the result to the screen using printf. To ensure that your message string is treated as a single input you should enclose it with quotation marks ("").

The shift you enter as an argument will enter your program as a string, not an integer. You can convert the string "12" to the integer 12 using the function `int atoi(char *s)` (atoi is for "AASCI to Integer").

Your arguments might look like the following:
`"This is the string I want to encrypt" 12`

Once this section is complete you should be able to run your program from the
command line as follows

    gcc caesar.c -o caesar.exe
    ./caesar.exe "Some important message." 13

We would then expect to see the encrypted text printed to screen. 
