#include<stdlib.h> // malloc, sizeof, free live here
#include<stdio.h>
#include<assert.h>

int strlength(char *s)
{
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}
int strlength2(char *s)
{
    int i = 0;
    char* temp = s;
    while(*temp != '\0')
    {
        i++;
        temp++;
    }
    return i;
}
int strlength3(char *s)
{
    char *temp = s;
    while(*temp != '\0')
    {
        temp++;
    }
    return temp - s;
}
int strlength4(char *s)
{
    char *temp = s;
    while(*temp++ != '\0'); // don't do this (Matt says)
    return temp - s;
}
void test_strlength()
{
    assert(strlength("Hello") == 5);
    assert(strlength("") == 0);
}

// Creates a copy of s
char* duplicate(char *s)
{
    int len = strlength(s);
    char *output = malloc(len * sizeof(char) + 1); // add 1 for the terminator
    int i;
    for(i = 0 ; i < len; i++)
    {
        output[i] = s[i];
    }
    output[len] = '\0'; // add terminator
    return output;
}
char* duplicate2(char *s)
{
    int len = strlength(s);
    char *output = malloc(len * sizeof(char) + 1); // add 1 for the terminator
    char* start_of_output = output;
    while(*s != '\0')
    {
        *output = *s; // copy s value to output value
        output++;
        s++;
    }
    *output = '\0';
    return start_of_output;
}
void test_duplicate()
{
    char *s = "Hello!";
    char *t = duplicate(s);
    assert(strlength(s) == strlength(t));
    free(t); // we malloced t and don't need it anymore
}

void main()
{
    test_strlength();
    test_duplicate();
    printf("Tests Pass!\n");
}
