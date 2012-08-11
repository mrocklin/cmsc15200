---
layout: assignment 
title: Tiny Savings and Loan 
due: Thursday, August 16th, 8pm 
---

In this assignment you will handle the transactions for Tiny Savings and Loan,
a small bank that saves and loans money out to customers. You will handle a
stream of inputs like the following

    Alice joins trusted
    Alice deposits 100
    Bob joins untrusted
    Bob deposits 300
    Alice withdraws 50
    Alice withdraws 100
    Bob withdraws 100
    Charlie joins trusted
    Alice prints
    Bob prints
    Charlie prints

You will maintain the balance of each customer and ensure that
they do not withdraw too much money. 

In order to do this you will have to write a lookup-table. You will then use
that lookup table to build the banking application.

Lookup Table
------------

It will be easy to build the banking application if we have the right data
structure. In this assignment you will first build a lookup table to store the
accounts by name. A lookup table has the following header

    Table mkTable();

    bool contains(Table t, char *key); // Does the table contain this key?
    ValueType get(Table t, char *key); // Get the account associated to key
    Table set(Table t, char *key, ValueType value); // Sets the key to new value. Adds new key/value pair if necessary. Returns pointer to table.
    int size(Table t); // How many elements are in the table?
    void printTable(Table t); // Nicely print the table

In a lookup table we store values. Each value has an associated key. Given a
key we can retreive the associated value. 

*Examples:* This is, for example, how a phone book works. In a phone book the
keys are names and the values are phone numbers. You supply a name and get back
a phone number. Normal arrays work this way too. You supply an index/int and
get back a value. Lookup tables are like arrays that are indexed with non-int
keys. 

###Implementation###

Internally a lookup table is a collection of key/value pairs. This collection
must be able to grow. 
We will implement a lookup table with a linked list of nodes. Each node will
contain both a `char *key` and an `Account value` as well as the necessary
fields to link to the other nodes. 

Your lookup table code should know nothing about `Account`s. In fact
you should write your lookup table with the return type `ValueType`. 
You can typedef any type to ValueType at compile-time. For testing we suggest that you typedef 

    typedef int ValueType;

So that your lookup table maps strings to ints. This will make it easy to
write tests (you won't have to make accounts to test your lookup table). 
When you move to the next
section you can typedef Accounts to ValueType and your code should work just
the same. This is because lookup.c doesn't actually need to know anything about
the values that it stores. It will just need to find and return them.

    typedef Account ValueType;

Tiny Savings and Loan
---------------------

Now that we have a lookup table writing this application should be much easier. We strongly recommend that you don't start writing this part of the homework until you are confident that your lookup table works very well.

Tiny savings and loan works under the following rules. 

* Anyone may open an account
When they open an account a credit check is performed. If they pass the credit
check then they are marked as "trusted", otherwise they are "untrusted"

    `Name joins trusted/untrusted`

* Anyone may deposit funds. 
This increases their balance by the amount listed.

    `Name deposits amount`

* Anyone may withdraw their own funds. 
This decreases their balance by the amount listed.

    `Name withdraws amount`

* Trusted members may withdraw an additional $1000
If a member is trusted then their balance can go negative (they owe money to
the bank). They can take out up to $1000. Any transaction which goes below this
value fails completely. 

* Anyone may ask to see their current balance

    `Name prints`

If a withdrawal transaction fails your program should print a short fail
message. See the output below

###Handling inputs###

The main function that we provide will take inputs from the command line and
open up a file `FILE *inputFile`. You can call the function

    char *nextMessage(FILE *f)

with the input file as an input to obtain the next line in the file. You can
call this function many times. Each time you call it it will return the next
line in the file.

We have given you code to handle command line arguments from the user. As it is
set up now this program has two modes. If you give it a text file as a command
line input

    ./tsl.exe input.txt

It will read lines from that file. 

If you do not supply an argument

    ./tsl.exe

It will expect you type in lines by hand at the terminal. This can be useful
for testing. Of course, if you forget about this you will wonder why your
    program isn't doing anything. It's waiting for you. You can signifiy
    `end-of-input` by pressing `Ctrl-D` or just stop the program by `Ctrl-C`

###Program Flow###

You should create an input file stream (this is done for you), create a lookup
table for the accounts, and then read in and handle messages one at a time
affecting the account book at each step.

You should do this until the file runs out. `nextMessage` will return `NULL` 
when it reaches the end of the file. 

Example Input/Output
--------------------

Input:

    Alice joins trusted
    Alice deposits 100
    Alice print
    Bob joins untrusted
    Bob deposits 300
    Bob print

    Alice withdraws 10
    Alice withdraws 10
    Alice print
    Bob withdraws 250
    Bob print

    Alice withdraws 100
    Alice print
    Bob withdraws 200
    Bob print

Output:

    Alice:      $ 100
    Bob:        $ 300
    Alice:      $  80
    Bob:        $  50
    Alice:      $ -20
    Transaction for Bob fails
    Bob:        $  50

Submission
----------

You should submit *at least* the following files

* `lookup.h, lookup.c, test_lookup.c`

* `tsl.c`
