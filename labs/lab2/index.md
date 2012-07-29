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

Make a new C Project
--------------------

If you're using eclipse today you can follow these steps to start up a new C
project. 

    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include <stdlib.h>
    
    void main(int argc, char *argv[])
    {
    	printf("hello world");
    }

Playing with chars
------------------

*Lesson in this section: types are merely suggestions*

A `char` in C is just an individual character. `char`s
are enclosed in single quotes: `'A'` and `'a'` and
`'?'` are all `char`s.

The way C represents `char`s internally is with a bit string
(everything on a computer is ultimately represented this way). For
example: the bit string `00100001` corresponds to `'!'`,
`01000000` corresponds to `'@'`, `01000001`
corresponds to `'A'`, and so on. If it seems that there is not
much rhyme or reason to this scheme, you're right! The system is
somewhat (though not entirely) arbitrary.

Since C represents not only characters but integers as bit strings,
it is the case that there are integers and characters which are
represented with the very same bit string. That is, the string
`00100001`, which represents the character `'!'`,
corresponds exactly to an 8-bit representation of the number
33. Internally, `'!'` and 33 are identical.* It is only the fact
that your program expects `00100001` to be a character that C
associates that bit string with `'!'`; otherwise it might very
well treat the same bits as the integer 33.


*This statement is not entirely accurate, but assume it is for now.*


In fact, C is very happy to treat characters as integers and
integers as characters: it doesn't care about the difference
between them. This means a programmer can perform arithmetic on
characters as if they were numbers. If you try the following

    char c = '!' + '!';
    printf("%c", c);

you will discover that in character
arithmetic, `'!' + '!' == 'B'`. This is because `'!'` is 33 and `'B'` is 66. Similarly `'%'*2`
is `'J'` because of the '%' and 'J's numerical values.

The way C matches integers to characters is standard for many programming languages and programs dating back to the 1960s. 
C uses the **ASCII Character Set**,where ASCII stands for 
"American Standard Code for Information Interchange." 

You can view a chart of the complete ASCII character set <a href="http://www.ascii-code.com/">here</a> or the commonly printed characters <a href="http://en.wikipedia.org/wiki/ASCII#ASCII_printable_characters">here</a>. There are alternatives to ASCII which go beyond the 255 characters into other writing 
systems. Unicode is such an alternative which is rapidly gaining popularity. 

Take a moment to inspect the ASCII character set (either link is fine).
You will notice that
the alphabet appears twice, in two big contiguous chunks, once in
lowercase form, and once in uppercase. 

The lesson is this: characters can be treated as numbers in many useful ways.
You can add and subtract from characters
to move around the ASCII chart. You can compare characters using
greater-than and less-than relations, and because of the way the ASCII
character set is laid out, letters will often have the quantitative
properties you expect: that is, `'b'` is greater than
`'a'` but less than `'c'`. In fact, `'b'+1 == 'c'`

<hr>

TASK: Print out the ASCII table. That is, for each integer from 1 to 255 print both the integer representation (like 65) and the character representation (like 'A'). You can do this by representing the same value/variable as both an int and a char in printf (use both the %d and %c placeholders in the string but use the same value for each).  

Many of the characters in the ASCII table are not printable. These will come out as boxes or spaces.

Playing with Pointers and Strings 
---------------------------------

*Lesson in this section: how to deal with pointers*

For help with this section please review the <a href="http://en.wikiversity.org/wiki/String_handling_in_C">wikiversity article</a> on C-Strings. 

Strings in C are an interesting example because they are usually handled with pointers. In our first example we're going to create a function which concatenates (adds) two strings. Note that there are no built-in functions in C which natively handle entire string objects as a whole, all operations must be built out of smaller operations on individual characters. * There is no String class/type in C. When we say "String", we mean a pointer to an array of characters.* 

Your task in this section is to create a function which concatenates/adds two strings together. It should have the following header/signature:
<pre> char *mystrcat(char *A, char *B) //strcat for string concatenation</pre> 
It takes in two string inputs, and returns the concatenation of those same strings. **mystrcat("hello", "world")** should return **"helloworld"**. Note that the naive solution <pre> char *output = A+B; //This does not work </pre> will only create a third pointer to some bizarre location in memory that is the addition of the two locations A and B (pointers are just numeric locations in memory). 

Instead you need to recognize that A and B point to locations in memory 
    
    A ----> {'H', 'e', 'l', 'l', 'o', '\0'}
    B ----> {'W', 'o', 'r', 'l', 'd', '\0'}

In this case you would need to allocate space for 5+5+1 == 11 chars and fill that space with 
    
    {'H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd', '\0'}

You will need to transfer each letter individually, add a terminator at the end and then finally return the pointer to the beginning 'H'.

First you will need to determine the length of the two strings. Then, you will need to allocate enough space to hold the addition of the two strings plus a terminating character. Then, copy the characters in the first string. Then copy the characters in the second string. Then you will need to write a terminator character '\0' and finally return the pointer to beginning of the result string. 


Caesar Cipher
-------------

The Caesar Cipher is a rudimentary encryption scheme whereby each letter is shifted by a constant up or down. For example we could move the word "Cat" up by one to "Dbu" C->D , a->b , t->u. This method was invented (they say) by Caesar and was used in communication with his Generals. It is not recommended for use today....

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

###Shifting a character###

Write a function `shiftChar` which takes in a character, **c**, and an integer, **shift**, and returns that character shifted up or down by the integer. 

Test that this function works on a variety of inputs. There are easy cases like `shiftChar('A', 1)=='B'` and more challenging cases like `shiftChar('z', 3)=='c'` or `shiftChar('a', -3)=='x'`. Make sure that it correctly encrypts both upper case and lower case letters but does not affect non-letters.

Unfortunately, **c+shift** will not work in cases where c+shift > 'Z' or &lt;'A' (if c is upper case) or c+shift > 'z' or &lt;'a' (if c is lowercase). In these cases you'll have to add or subtract 26 so that the letters wrap around, i.e. so that shiftChar('Z', 1) returns 'A' and shiftChar('A',-1) returns 'Z'.

It's important to recognize that we're playing with both chars and ints at the same time. C gives us much more control than other languages you may have tried.These other languages keep you away from potentially dangerous activities. C lets you play with dangerous things but allows you to get burned. 

###Putting it all together###

Build a function which takes an input string and shift integer, goes through the string and shifts each character appropriately. Do this *in place*, that is, affect the input string directly. Do not shift non-letters. Your function will not need to return anything. Test your function from your main code. Does it work? Why can we do this? Inputs to functions in C are copied and changes to them are not relayed to the outside. Why is our string changed in our main function then? What exactly was our input to the function? Was it changed?

*Potential error:* To test your code you may be tempted to make a string as follows 

    char *testString = "My test string tests both UPPER and lower case letters, as well as punctuation.\n";
Unfortunately static strings that we specify directly in quotes are usually stored in * read-only memory* and can not be modified. Modifying them will result in a Segmentation Fault. To fix this simply create a dynamic copy of your string using 

    testString = strdup(testString); //duplicate testString dynamically</pre>

This string is stored in normal memory and is fine to change. 

Now, build the same function but rather than have it change the string in place, have it create a new string of the appropriate size and fill it with the shifted characters. Do not simply copy your string and then call your previous encryption function. Pretend that this must be done quickly and the waste of writing the information twice is not acceptable (if you copy then you're writing once in string-copy, and then a second time when you shift). Return the copied string.  

Build Decryption functions for each of your previous Encryption functions. These should each be one line long. 

###Test Case###

To test your function try the string "M! K fobi pkcd, iod kd dswoc pbecdbkdsxq vkxqekqo." with a shift of -10. You should obtain something readable. 

###Free###

The companion to **malloc** is **free**. **free** releases memory back into the common pool. This is especially important if your program creates lots of temporary arrays. If you don't free them then you'll quickly run out of space.  Think about the memory space that you've malloc'ed. Free those variales when they are no longer needed. Often programmers are lazy about this because usually arrays left hanging around are freed automatically when their home function returns. It is good to understand that **free** exists however. 

Program Arguments
-----------------

Usually we write main like this
<img src="argumentsEclipse.png" alt="Arguments in Eclipse" 
width="40%" align="right">

    void main()

You'll often see it written like this instead

    int main(int argc, char* argv[])

This allows us to give our program inputs/arguments. The second input, argv stores the name of the program and the values of the arguments while the first input tells us how many we received. 

We give a program inputs on the command line by following the `./programName` with the inputs. If we wanted to give the program three inputs, 5, 5.5 and the string "hello world" we could type:

    ./programName 5 5.5 "hello world" 

In this case `argc==4` because there is one program and three arguments. 
`argv` is an array of strings (`char* s`) with 

* `argv[0] == programName`
* `argv[1] == "5"`
* `argv[2] == "5.5"`
* `argv[3] == "hello world"`

You can enter arugments in Eclipse in the "Run..." window by clicking on the arugments tab. 

Modify your program so that it takes two arguments. A message, enclosed in quotes, and a shift/integer. It should encrypt the message using the shift and then print the result to the screen using printf. To ensure that your message string is treated as a single input you should enclose it with quotation marks ("").

The shift you enter as an argument will enter your program as a string, not an integer. You can convert the string "12" to the integer 12 using the function `int atoi(char *s)` (atoi is for "AASCI to Integer").

Your arguments might look like the following:
`"This is the string I want to encrypt" 12`

Submission
----------

Submit two .c files. 

1.  One that prints out the ASCII Table. 
2   One that takes a message and encryption number as arguments and prints 
    the string encrypted using the number. Your mystrcat function should be 
    included in this code.  It does not need to be tested in main. For this 
    second program we will test it as follows:
    
    gcc -lm yourfile.c -o yourfile.exe
    ./yourfile.exe "Some message here" 13

We will then expect to see the encrypted text printed to screen. 
