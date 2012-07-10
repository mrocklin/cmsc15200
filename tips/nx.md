---
layout: default
title: Installing NX
---

Installing C, Eclipse, etc... on your home computer may be
challenging. An alternative is to remotely access the Maclab. This can be 
done using the text-based program
[ssh](http://www.cs.uchicago.edu/info/services/ssh)
or in a fully graphical way using the program 
[NX](http://www.nomachine.com/download.php>NX)

NX allows you to use a Maclab computer remotely. Depending on your 
internet connection there may be a slight but usually tolerable amount of 
latency. In general this is a very clean solution that requires the minimum
amount of work. 

Go to [the NX download page](http://www.nomachine.com/download.php)
and download the *NX Client* that matches your operating system  (Windows, Mac, and Linux are all supported). Install this program on your 
computer (this is usually easy.) 

Note: If you're using Mac OS-X Lion edition you'll have to download and install the [newest beta version](http://www.nomachine.com/preview/download-package.php?Prod_Id=13)

Run the newly installed NX program. You will need 

* Your CS username
* Your CS password
* The name of a computer on the CS network that you want to use

You will have to configure a new session. This will ask you for the 
hostname (discussed below) and how you would like to display. "Fullscreen"
and "Available Area" are both excellent choices.

The hostnames of the computers in the Maclab are printed on top of the 
computer. If you want to access these computers from outside the CS 
network you must add ".cs.uchicago.edu" to the end of the name. 
For example `altair` is one of the Maclab computers. The hostname is
thus `altair.cs.uchicago.edu`. Please, find a computer other than 
altair to log into. If everyone logs into altair then everyone will be 
slow.

One computer can only be accessed by a couple of users within a
certian time period. As a result you may find that the machine you're
trying to log into is inaccessible. If this happens just try another. It
make take a few tries before you find one that is open.

You can also find a list of available computers by visiting [this page](http://tools.cs.uchicago.edu/find_cs_hosts/find.cgi)
