---
layout: default
title: SVN 
---

We will use [SVN](http://tortoisesvn.tigris.org/) to communicate homework 
between the course instructor, students, and graders.

You can access the UChicago SVN server through a web interface
[here](https://phoenixforge.cs.uchicago.edu/)

Both you and the course staff have access to the following repository

    https://phoenixforge.cs.uchicago.edu/svn-internal/username-152

where `username` should be replaced by your CNetID. 

On a UNIX based system you can check out this repository with the `svn co`
command. `co` stands for check out

    svn co https://phoenixforge.cs.uchicago.edu/svn-internal/username-152

If you're running OS-X and prefer a GUI environment you may want to look at
some of the options listed on [this stackoverflow
post](http://stackoverflow.com/questions/899/best-subversion-client-for-mac-os)

If you're running Windows you can look at the options listed on [this
stackoverflow
post](http://stackoverflow.com/questions/569278/your-favorite-gui-client-for-svn).
[TortiseSVN](http://tortoisesvn.tigris.org/) has been a standard for a long
while. 


Using SVN
---------

There are four important svn commands 

    svn co repository-name

This checks out a repository onto your local computer. It creates a special
directory that is connected to the web server. This only happens once. 

    svn up

This updates the directory on your computer with any new changes on the server.
This is how you will download new homeworks. We will place files into the
server, you will update your computer's directory by typing `svn up`

    svn ci -m"An informative message"

This sends the work you have done on your computer up to the server. This is
how you submit your homework. `CI` stands for "Check in". When you check in you
have the option of recording a small message. Examples of messages might be
*"Turning in HW1"* or *"Solved part 1"*. You can check in many times before the
deadline. See the section below.

    svn add some_new_file

If you create a new file in your repository directory it is not yet part of the
repository. You first need to call `svn add` on it to tell svn that you care
about this file and want it to communicate itself to the server. If you make a
new `.c` file you should add it. You do not need to add `.c` files that were
already there. You only need to do this once per file and you will not need to 
do it at all for the first week. 

Question: _"How do I make sure that I have correctly submitted my homework?"_

Answer:   _"At the top of this page we supply a link to the web interface of
your svn repository. The files that are visible there are what we will grade."_

Commit Often
------------

SVN is useful to communicate code between many programmers. It is also useful
as a very advanced undo button. Each time you commit/checkin with `svn ci` you 
record the whole state of your directory. It is possible to revert your svn 
directory to any previous state. As a result we encourage you to check in your 
code often, preferably every time you get something new to work and you have
tested that it works. If you screw things up (this will happen) you will be
able to easily revert back to a working state.

Update before edit
------------------

SVN is also useful if you work on many computers (like both the Maclab and your
home computer). When you leave one location make sure you check-in. When you
start work at a second location make sure you update the local directory to
download the changes you've made. If you do not update but make changes on an
old version and then try to commit the server will become confused. It will
then ask you to resolve the problem. This will rapidly cause you to become 
confused. You can avoid this problem by always typing `svn up` just before you
start working

Getting help from the Course Staff
----------------------------------

You will need help with your code during this course. The course staff is here
for that. In fact, you're paying us for just this reason.

We are much more effective if we can see your code. SVN enables you to
share your code with us very easily by checking it in. This is far preferable
to sending us code snippets by e-mail. 

If you have a question that requires us to look at your code then be sure to
check in your code before you e-mail us.

If you run into an issue with SVN itself (see the section just above) feel free
to e-mail us about that too. 
