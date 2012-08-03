// Command line arguments are how we send data to a program
// argv is an array of strings
// argc is the length of that array
// Example: ./command_line_arguments.exe hello 5 5.5
// argc = 4
// argv[0] == "./command_line_arguments.exe"
// argv[1] == "hello"
// argv[2] == "5"
// argv[3] == "5.5"

#include<stdio.h>

int main(int argc, char *argv[])
{
    int i;
    for(i = 0; i < argc; i++)
        printf("The %dth input is : %s\n", i, argv[i]);

    return 0; // everything is ok
}
