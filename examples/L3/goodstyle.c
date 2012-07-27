// This computes a^b
// example : power(3, 2) == 9
int power(int base, int exponent)
{
    int i=0;
    int result=1; //I'm going to return this value
    while(i< exponent)
    {
        result=result*base;
        i=i+1;
    }
    return result;
}

breakupmanywordvariablenames // This is hard to read
break up many //can't use spaces :(

breakUpManyWordVariableNames // CamelCase - easier to type and more common
                             // first letter lower-case, 
                             // every other first letter is upper-case
break_up_many_word_variable_names // underscores - harder type, easier to read

// one statement per line, maximum
// Indent within every pair of curly braces
