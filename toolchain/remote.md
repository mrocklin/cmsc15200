---
layout: default
title: Logging in Remotely 
---

We will guarantee a working software environment in the Maclab. It's more challenging guarantee working software on everyone's personal computer. Of course, while the Maclab provides and excellent work environment, you may prefer to work from home. One solution to this is to download and install software yourself. Another option is to log into the Maclab remotely. 

There are two options to log in remotely, `ssh` and NX. SSH is terminal-based,
NX is graphical. 

SSH
---

`ssh` gives you access to the Terminal application from any remote commputer.
If you have a Unix based machine (Mac OS-X or Linux), it is installed by
default and is accessible through the Terminal. If you have a Windows machine
you can install
[PuTTY](http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html). You can use ssh from a terminal as follows


    ssh username@computername

For example if I were to log in remotely to the server
`bellatrix.cs.uchicago.edu` I would type the following into my local terminal. 

    ssh mrocklin@bellatrix.cs.uchicago.edu

PuTTY has a simple log-in screen. 

This solution allows you to use text editors like `emacs` and `vim` and `gcc`
to compile. `emacs` and `vim` are well loved tools but are not straightforward to use. You may want to look up online tutorials if you choose to go this route. 

File transfer can be done using `scp` for Unix-like systems (Mac OS-X, Linux)
or [WinSCP](http://winscp.net/eng/index.php) for Windows machines. Again, you will need to provide your CS username and password. 


NX
--


Finding a computer to log into 
------------------------------

Here is [a list of computers to which you have access](http://tools.cs.uchicago.edu/find_cs_hosts/search.cgi?host=cpu_mhz&host=description&host=location&host=os&verbose=1). 
Alternatively if you're in the MacLab the names are printed on the top of the computer itself.  If you see a machine that is tagged with "bellatrix" then its full computer name is bellatrix.cs.uchicago.edu. 

If you're using NX then you may need to try a few before you find one that isn't busy. 
