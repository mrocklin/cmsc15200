---
layout: default
title: Handling Errors
---

You will write code with errors. This is inevitable. Rather than trying to avoid them we do our best to find and understand them so that we can correct them quickly and move on. At the beginning this can be a frustrating process. 

*Compile-time errors* are obvious errors in your syntax. `gcc` will find them for you and print a cryptic message letting you know what kind of error it is and where it can be found. Lets look at the following example. 

    #include<stdio.h>
    void main()
    {
        printf("Hello World")
    }

Do you see anything wrong? `gcc` does. When I try to compile this program gcc prints out the following

    helloworld.c: In function 'main':
    helloworld.c:5:1: error: expected ';' before '}' token

These sorts of messages are the best that <code>gcc</code> can do. For a computer, it's not a bad attempt at communicating in English. It's saying that in the helloworld.c program on line 5 character 1 (<code>helloworld.c:5:1</code>) it expected a '<code>;</code>' before the '<code>}</code>' it just found.

If we count down five lines we see the '<code>}</code>' but why it expected a ';' here is a mystery. Oh! Just above this line it appears we missed a semi-colon! How silly of us! (after 10+ years I still do this). We fix the <code>helloworld.c</code> file and try running <code>gcc</code> again, hoping it will compile. We continue to do this until it compiles. 

So error messages take a little practice to understand fully. In the meantime it's always good to look at the line number which appaers just after the filename like 5 does in <code> helloworld.c:5:1 </code>. Then look around in your code at this location to see if anything looks odd. Perhaps you misspelled something, are using capitalization incorrectly, missing a semi-colon, parenthesis, equals sign, etc....

*So what do I do if I can't find the error?* Please do not spend hours
searching for a bug. Instead, try posting the error to the staff listhost. If you're the first one then you'll get to help all the other students by asking a question. Other solutions include coming back to the problem later and also coming to office hours. 
